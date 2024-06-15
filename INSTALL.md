# Installation Guide for ircd-hybrid

## Prerequisites

Ensure the following tools and libraries are installed on your system before commencing the installation process:

- **Autoconf** 2.71 or higher
- **Automake** 1.16.5 or higher
- **C compiler** (e.g., GCC)
- **Yacc**
- **Lex** with `noyywrap` support
- **Libtool**
- **GNU make** or a compatible make utility

## Installation Procedure

### Step 1: Configuration

Execute the `configure` script to prepare the build environment. This script verifies the availability of necessary tools and libraries and configures the makefiles accordingly.

```sh
./configure
```

To customize the installation directories, you may provide options to the `configure` script. Example:

```sh
./configure --prefix=/custom/path
```

#### Configuration Options

- `--prefix=PREFIX` - Specify the installation prefix (default: `/usr/local`).
- `--sysconfdir=SYSCONFDIR` - Specify the directory for system configuration files.
- `--libdir=LIBDIR` - Specify the directory for object code libraries.
- `--datadir=DATADIR` - Specify the directory for read-only architecture-independent data.
- `--localstatedir=LOCALSTATEDIR` - Specify the directory for local state files.

### Step 2: Compilation

After successful configuration, compile the program using:

```sh
make
```

For some BSD systems, `gmake` might be required:

```sh
gmake
```

### Step 3: Installation

Install the program using:

```sh
make install
```

### Optional Configuration Parameters

The `configure` script accepts several optional parameters for further customization:

- `--enable-assert` - Enable `assert()` statements. By default, these are disabled. To enable them:

  ```sh
  ./configure --enable-assert
  ```

  This option defines `NDEBUG` to disable `assert()` statements when not enabled.

- `--enable-debugging` - Enable debugging support. By default, this is disabled. To enable it:

  ```sh
  ./configure --enable-debugging
  ```

  This modifies `CFLAGS` to include `-g -O0` and removes any optimization flags (`-O`).

- `--enable-efence` - Enable linking with the Electric Fence (`efence`) memory debugger library. By default, this is disabled. To enable it:

  ```sh
  ./configure --enable-efence
  ```

  This links the application with the Electric Fence memory debugger library. If the library is not found, the configuration process will terminate with an error.

- `--enable-warnings` - Enable comprehensive compiler warnings. By default, these are disabled. To enable them:

  ```sh
  ./configure --enable-warnings
  ```

  This adds extensive warning flags to the compiler options. The exact set of warnings enabled may depend on the compiler and its version. Currently, the following warnings are enabled:

  - `-Wall`
  - `-Wbad-function-cast`
  - `-Wcast-align`
  - `-Wcast-function-type`
  - `-Wcast-qual`
  - `-Wclobbered`
  - `-Wduplicated-cond`
  - `-Wempty-body`
  - `-Wenum-conversion`
  - `-Wignored-qualifiers`
  - `-Wlogical-op`
  - `-Wmissing-declarations`
  - `-Wmissing-field-initializers`
  - `-Wmissing-include-dirs`
  - `-Wmissing-parameter-type`
  - `-Wmissing-prototypes`
  - `-Wnested-externs`
  - `-Wold-style-declaration`
  - `-Woverride-init`
  - `-Wpointer-arith`
  - `-Wredundant-decls`
  - `-Wshadow`
  - `-Wshift-negative-value`
  - `-Wsign-compare`
  - `-Wtype-limits`
  - `-Wundef`
  - `-Wuninitialized`
  - `-Wunreachable-code-break`
  - `-Wwrite-strings`

  Note that the availability and behavior of these warnings may vary depending on the compiler and its version.

- `--enable-kqueue` - Force `kqueue` usage for IO loop mechanism.
- `--enable-epoll` - Force `epoll` usage for IO loop mechanism.
- `--enable-poll` - Force `poll` usage for IO loop mechanism.

- `--with-tls` - Enable TLS support with the specified library. Options: `openssl`, `wolfssl`, `gnutls`, or `none`. By default, TLS support is set to `auto`, which attempts to detect and utilize the best available TLS library. To explicitly specify a TLS library:

  ```sh
  ./configure --with-tls=openssl
  ```

  If the specified TLS library is not found, the configuration process will disable TLS support and output an error message.

#### TLS Library Requirements

- **OpenSSL**: Version 1.1.1 or higher
- **LibreSSL**: Equivalent to OpenSSL 1.1.1 or higher
- **GnuTLS**: Version 3.6.5 or higher
- **wolfSSL**: Version 4.3.0 or higher (must be built with the extended/full OpenSSL compatibility layer)

### IO Loop Mechanism Configuration

The `configure` script attempts to automatically detect and select the optimal IO loop mechanism (`kqueue`, `epoll`, or `poll`). However, manual specification is possible using the following options:

- `--enable-kqueue` - Force `kqueue` usage.
- `--enable-epoll` - Force `epoll` usage.
- `--enable-poll` - Force `poll` usage.

If the specified mechanism is unavailable, the configuration process will terminate with an error.

### Build Date Definition for Reproducible Builds

The build date is defined during the configuration process using the `AX_DEFINE_BUILD_DATE` macro, facilitating reproducible builds. This macro sets the build date based on the current date and time or the `SOURCE_DATE_EPOCH` environment variable, if specified. For more information on reproducible builds and the `SOURCE_DATE_EPOCH` environment variable, please refer to the [Reproducible Builds documentation](https://reproducible-builds.org/docs/source-date-epoch/).

## Post-Installation

After installation, the `ircd-hybrid` server will be located in the directory specified by `--prefix`.

Default installation paths:
- Binaries: `${prefix}/bin`
- Configuration files: `${sysconfdir}`
- Libraries: `${libdir}`
- Data files: `${datadir}`
- State files: `${localstatedir}`

To start the server, navigate to the installation directory and execute:

```sh
${prefix}/bin/ircd
```

## Troubleshooting

For any issues encountered during the installation process, refer to the following steps:

1. Ensure all required dependencies are installed and available in your `PATH`.
2. Check the `configure` script output for any missing libraries or tools.
3. Review the `config.log` file generated by the `configure` script for detailed error messages.
4. Visit the [ircd-hybrid website](https://www.ircd-hybrid.org/) for additional support and resources.

For further assistance, contact the development team at: [bugs@ircd-hybrid.org](mailto:bugs@ircd-hybrid.org).
