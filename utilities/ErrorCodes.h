/*
 * \author {Paul Liu}
 * \summary {Error codes and some macros in this projects.}
 */

#ifndef _ERROR_CODES_H_
#define _ERROR_CODES_H_

#ifndef BOOL
#define BOOL  int
#endif

#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL  0
#endif

#ifndef RESULT
#define RESULT int
#endif

#define EC_OK                 0
#define EC_NULL_POINTER       1
#define EC_INVALID_PARAMETER  2
#define EC_IMPOSSIBLE_CASE    3
#define EC_OUT_OF_MEMORY      4
#define EC_OUT_OF_RANGE       5
#define EC_QUEUE_OVERFLOW     6
#define EC_STACK_OVERFLOW     7

#endif
