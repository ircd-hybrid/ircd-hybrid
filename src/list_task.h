#ifndef INCLUDED_list_task_h
#define INCLUDED_list_task_h
#include <stdbool.h>

#include "list.h"

struct Client;

/**
 * @struct ListTask
 * @brief Holds the filtering criteria and execution state for a /LIST request.
 */
struct ListTask
{
  struct Client *client;  /**< Back-pointer to the client who owns this task. */
  list_node_t node;  /**< Node for membership in the global listing queue. */

  list_t include_masks;  /**< Channels to show (exact names or wildcards). */
  list_t exclude_masks;  /**< Channels to hide (exact names or wildcards). */

  char *topic;  /**< Topic wildcard string to match. */
  unsigned int hash_index;  /**< The current hash bucket for background iteration. */
  unsigned int users_min;  /**< Minimum users required in the channel. */
  unsigned int users_max;  /**< Maximum users allowed in the channel. */
  unsigned int created_min;  /**< Minimum channel creation time (real time). */
  unsigned int created_max;  /**< Maximum channel creation time (real time). */
  unsigned int topicts_min;  /**< Minimum topic set time (real time). */
  unsigned int topicts_max;  /**< Maximum topic set time (real time). */

  bool exact_match;  /**< True if no wildcards are used. */
  bool is_queued;  /**< True if actively linked in the background task queue. */
};

extern void list_task_destroy(struct ListTask *);
extern void list_task_start(struct ListTask *);
extern struct ListTask *list_task_create(struct Client *);
#endif  /* INCLUDED_list_task_h */
