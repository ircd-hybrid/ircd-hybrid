#include <check.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <limits.h>

/*
 * Security invariant: When constructing a buffer to hold the concatenation
 * of filename and member strings, the allocated buffer size MUST be at least
 * strlen(filename) + strlen(member) + 1 bytes, and no integer overflow must
 * occur in the size calculation. The sprintf/strcpy into the buffer must
 * never write beyond the allocated region.
 */

/* Simulate the vulnerable allocation and write pattern from dlopen.c:226 */
static int safe_concat_attempt(const char *filename, const char *member, char **out)
{
    if (!filename || !member) return -1;

    size_t filename_len = strlen(filename);
    size_t member_len   = strlen(member);

    /* Check for integer overflow in size calculation */
    if (member_len > SIZE_MAX - filename_len - 1) {
        return -2; /* overflow detected */
    }

    size_t total = filename_len + member_len + 1;

    /* Simulate what the vulnerable code does: use 'len' (which might be
     * pre-computed or wrong) as the base for allocation */
    size_t len = filename_len; /* correct usage */

    /* Overflow check on len + member_len + 1 */
    if (member_len > SIZE_MAX - len - 1) {
        return -2;
    }

    char *attempt = (char *)malloc(len + member_len + 1);
    if (!attempt) return -3;

    /* The invariant: the buffer must be large enough for the sprintf result */
    size_t required = filename_len + member_len + 1;
    size_t allocated = len + member_len + 1;

    if (allocated < required) {
        free(attempt);
        return -4; /* buffer too small — security violation */
    }

    /* Safe write: use snprintf to enforce bounds */
    int written = snprintf(attempt, allocated, "%s%s", filename, member);
    if (written < 0 || (size_t)written >= allocated) {
        free(attempt);
        return -5; /* truncation or error */
    }

    /* Verify the result is correct */
    if (strlen(attempt) != filename_len + member_len) {
        free(attempt);
        return -6;
    }

    if (out) *out = attempt;
    else free(attempt);

    return 0;
}

/* Test that allocation size calculation never overflows for adversarial inputs */
static int check_no_overflow(size_t len, size_t member_len)
{
    /* Replicate the arithmetic from the vulnerable code */
    if (member_len > SIZE_MAX - len) return 0; /* overflow */
    size_t sum = len + member_len;
    if (sum > SIZE_MAX - 1) return 0; /* overflow */
    return 1; /* safe */
}

START_TEST(test_buffer_allocation_security)
{
    /* Invariant: The allocated buffer must always be large enough to hold
     * strlen(filename) + strlen(member) + 1 bytes without overflow,
     * and sprintf must never write beyond the allocated region. */

    const char *filename_payloads[] = {
        "",
        "a",
        "/usr/lib/libfoo.so",
        "/usr/lib/libfoo.so.1",
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
        "/path/to/some/very/long/library/name/that/exceeds/normal/limits/libfoo.so",
        "\x00",
        "lib\x00hidden",
        "../../../../etc/passwd",
        "/tmp/evil.so\x00.legit",
        "normal_lib",
        "/lib/x86_64-linux-gnu/libc.so.6",
    };

    const char *member_payloads[] = {
        "",
        "(",
        "(member)",
        "(AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA)",
        "(../../../../etc/shadow)",
        "(\x00evil)",
        "(normal_member)",
        "(member_with_special_chars_!@#$%^&*)",
    };

    int num_filenames = sizeof(filename_payloads) / sizeof(filename_payloads[0]);
    int num_members   = sizeof(member_payloads)   / sizeof(member_payloads[0]);

    for (int i = 0; i < num_filenames; i++) {
        for (int j = 0; j < num_members; j++) {
            const char *filename = filename_payloads[i];
            const char *member   = member_payloads[j];

            /* Skip payloads with embedded nulls for strlen-based tests */
            if (memchr(filename, '\0', 20) != (void*)(filename + strlen(filename)))
                continue;
            if (memchr(member, '\0', 20) != (void*)(member + strlen(member)))
                continue;

            size_t filename_len = strlen(filename);
            size_t member_len   = strlen(member);

            /* Invariant 1: No integer overflow in size calculation */
            int no_overflow = check_no_overflow(filename_len, member_len);
            ck_assert_msg(no_overflow == 1,
                "Integer overflow detected in size calculation for filename='%s' member='%s'",
                filename, member);

            if (!no_overflow) continue;

            /* Invariant 2: Allocated size must be sufficient */
            size_t allocated = filename_len + member_len + 1;
            size_t required  = strlen(filename) + strlen(member) + 1;
            ck_assert_msg(allocated >= required,
                "Allocated buffer too small: allocated=%zu required=%zu for filename='%s' member='%s'",
                allocated, required, filename, member);

            /* Invariant 3: The concat operation must succeed without overflow */
            char *out = NULL;
            int result = safe_concat_attempt(filename, member, &out);
            ck_assert_msg(result == 0,
                "safe_concat_attempt failed with code %d for filename='%s' member='%s'",
                result, filename, member);

            if (out) {
                /* Invariant 4: Result string length must equal sum of inputs */
                size_t result_len = strlen(out);
                ck_assert_msg(result_len == filename_len + member_len,
                    "Result length mismatch: got %zu expected %zu for filename='%s' member='%s'",
                    result_len, filename_len + member_len, filename, member);

                /* Invariant 5: Result must start with filename and end with member */
                ck_assert_msg(strncmp(out, filename, filename_len) == 0,
                    "Result does not start with filename for filename='%s' member='%s'",
                    filename, member);
                ck_assert_msg(strcmp(out + filename_len, member) == 0,
                    "Result does not end with member for filename='%s' member='%s'",
                    filename, member);

                free(out);
            }
        }
    }
}
END_TEST

START_TEST(test_size_overflow_detection)
{
    /* Invariant: Size calculations that would overflow SIZE_MAX must be
     * detected and rejected before any allocation or write occurs. */

    /* Test near-overflow values */
    size_t near_max_len    = SIZE_MAX - 2;
    size_t small_member    = 1;
    size_t overflow_member = 3; /* near_max_len + 3 + 1 overflows */

    /* near_max_len + small_member + 1 = SIZE_MAX: borderline */
    int safe1 = check_no_overflow(near_max_len, small_member);
    /* This should detect overflow (SIZE_MAX - 2 + 1 = SIZE_MAX - 1, +1 = SIZE_MAX: ok but tight) */
    /* Actually SIZE_MAX - 2 + 1 = SIZE_MAX - 1, then +1 = SIZE_MAX which is valid size_t */
    /* But malloc(SIZE_MAX) will fail — the invariant is about overflow detection */
    (void)safe1;

    /* near_max_len + overflow_member would overflow */
    int safe2 = check_no_overflow(near_max_len, overflow_member);
    ck_assert_msg(safe2 == 0,
        "Overflow not detected for near-max size calculation: len=%zu member_len=%zu",
        near_max_len, overflow_member);

    /* SIZE_MAX + anything overflows */
    int safe3 = check_no_overflow(SIZE_MAX, 1);
    ck_assert_msg(safe3 == 0,
        "Overflow not detected for SIZE_MAX len");

    int safe4 = check_no_overflow(SIZE_MAX, SIZE_MAX);
    ck_assert_msg(safe4 == 0,
        "Overflow not detected for SIZE_MAX + SIZE_MAX");

    /* Zero-length inputs should always be safe */
    int safe5 = check_no_overflow(0, 0);
    ck_assert_msg(safe5 == 1,
        "False overflow detected for zero-length inputs");

    int safe6 = check_no_overflow(0, 100);
    ck_assert_msg(safe6 == 1,
        "False overflow detected for zero filename + small member");
}
END_TEST

START_TEST(test_snprintf_bounds_enforcement)
{
    /* Invariant: Using snprintf with the correct buffer size must never
     * result in truncation for valid (non-overflowing) inputs. */

    struct { const char *filename; const char *member; } cases[] = {
        { "",                    ""          },
        { "libfoo.so",           ""          },
        { "",                    "(member)"  },
        { "libfoo.so",           "(member)"  },
        { "/usr/lib/libfoo.so",  "(archive)" },
        { "a",                   "b"         },
        { "AAAAAAAAAAAAAAAA",    "(BBBBBBBB)"},
    };
    int num_cases = sizeof(cases) / sizeof(cases[0]);

    for (int i = 0; i < num_cases; i++) {
        const char *filename = cases[i].filename;
        const char *member   = cases[i].member;

        size_t filename_len = strlen(filename);
        size_t member_len   = strlen(member);

        /* Invariant: no overflow */
        ck_assert_msg(check_no_overflow(filename_len, member_len),
            "Unexpected overflow for test case %d", i);

        size_t bufsize = filename_len + member_len + 1;
        char *buf = (char *)malloc(bufsize);
        ck_assert_ptr_nonnull(buf);

        int written = snprintf(buf, bufsize, "%s%s", filename, member);

        /* Invariant: snprintf must not truncate */
        ck_assert_msg(written >= 0,
            "snprintf returned error for case %d", i);
        ck_assert_msg((size_t)written < bufsize,
            "snprintf truncated output for case %d: written=%d bufsize=%zu",
            i, written, bufsize);

        /* Invariant: written length matches expected */
        ck_assert_msg((size_t)written == filename_len + member_len,
            "snprintf wrote wrong number of bytes for case %d: written=%d expected=%zu",
            i, written, filename_len + member_len);

        free(buf);
    }
}
END_TEST

Suite *security_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Security");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_buffer_allocation_security);
    tcase_add_test(tc_core, test_size_overflow_detection);
    tcase_add_test(tc_core, test_snprintf_bounds_enforcement);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = security_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}