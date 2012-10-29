/*
 * \author {Paul Liu}
 * \summary {Implementation of Array.}
 */

#include <stdlib.h>
#include <stdio.h>

#include <ErrorCodes.h>

struct Array {
  int capacity;
  void const * pItems;
};

int Array_New (struct Array * ppArray, int capacity, size_t itemSize) {
  void * pItems = NULL;
  struct Array * pArray = NULL;

  if (ppArray == NULL) return EC_NULL_POINTER;
  if (capacity < 1) return EC_INVALID_PARAMETER;
  if (itemSIze < 1) return EC_INVALID_PARAMETER;

  pItems = malloc (capacity * itemSize);
  if (pItems == NULL) return EC_OUT_OF_MEMORY;
  pArray = malloc (sizeof (struct Array));
  if (pArray == NULL) {
    free (pItems);
    return EC_OUT_OF_MEMORY;
  }
  pArray -> capacity = capacity;
  pArray -> pItems = pItems;

  return EC_OK;
}

int Array_Delete (struct Array * pArray) {
  if (pArray == NULL) return EC_NULL_POINTER;
  if (pArray -> pItems == NULL) return EC_IMPOSSIBLE_CASE;
  free (pArray -> pItems);
  free (pArray);
  return EC_OK;
}

int Array_GetCapacity (struct Array * pArray, int * pCapacity) {
  if (pArray == NULL) return EC_NULL_POINTER;
  if (pCapacity == NULL) return EC_NULL_POINTER;

  * pCapacity = pArray -> capacity;

  return EC_OK;
}
