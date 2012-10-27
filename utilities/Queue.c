/*
 * \author {Paul Liu}
 * \summary {This is the implement of Queue structure in this project.}
 */

#include <stdlib.h>
#include <stdio.h>

#include <ErrorCodes.h>

struct Queue {
  int capacity;
  int head;
  int tail;
  void const * * ppArray;
};

int Queue_New (struct Queue * * ppQueue, int capacity) {
  void * pArray = NULL;
  struct Queue * pQueue = NULL;
  if (ppQueue == NULL) return EC_NULL_POINTER;
  if (capacity < 1) return EC_OUT_OF_RANGE;

  pArray = malloc (sizeof (void const *));
  if (pArray == NULL) return EC_OUT_OF_MEMORY;
  pQueue = malloc (sizeof (struct Queue));
  if (pQueue == NULL) {
    free (pArray);
    return EC_OUT_OF_MEMORY;
  }
  pQueue -> capacity = capacity;
  pQueue -> head = -1;
  pQueue -> tail = -1;
  pQueue -> ppArray = pArray;
  
  * ppQueue = pQueue;
  return EC_OK;
}

int Queue_Delete (struct Queue * pQueue) {
  if (pQueue == NULL) return EC_NULL_POINTER;
  if (pQueue -> ppArray == NULL) return EC_NULL_POINTER;
  free (pQueue -> ppArray);
  free (pQueue -> pQueue);
  return EC_OK;
}

int Queue_Put (struct Queue * pQueue, void const * pObj) {
  if (pQueue == NULL) EC_NULL_POINTER;
  if (pObj == NULL) EC_NULL_POINTER;

  if (pQueue -> head > pQueue -> tail) {
    if (pQueue -> head < pQueue -> capacity - 1) {
      ++ (pQueue -> head);
    } else {
      if (pQueue -> tail > 0) {
        pQueue -> head = 0;
      } else {
        return EC_QUEUE_OVERFLOW;
      }
    }
  } else if (pQueue -> head < pQueue -> tail) {
    if (pQueue -> head < pQueue -> tail - 1) {
      ++ (pQueue -> head);
    } else {
      return EC_QUEUE_OVERFLOW;
    }
  } else {
    if (pQueue -> head == -1) {
      ++ (pQueue -> head);
    } else {
      return EC_QUEUE_OVERFLOW;
    }
  }

  pQueue -> ppArray [pQueue -> head] = pObj;
  return EC_OK;
}

int Queue_Get (struct Queue * pQueue, void * * ppObj) {
  if (pQueue == NULL) return EC_NULL_POINTER;
  if (ppObj == NULL) return EC_NULL_POINTER;

  if (pQueue -> head > pQueue -> tail) {
    ++ (pQueue -> tail);
  } else if (pQueue -> head < pQueue -> tail) {
    if (pQueue -> tail < pQueue -> capacity - 1) {
      ++ (pQueue -> tail);
    } else {
      if (pQueue -> head > 0) {
        pQueue -> tail = 0;
      } else {
        return EC_QUEUE_OVERFLOW;
      }
    }
  } else {
    return EC_QUEUE_OVERFLOW;
  }

  * ppObj = pQueue -> ppArray [pQueue -> tail];
  return EC_OK;
}
