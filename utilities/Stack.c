/*
 * \author {Paul Liu}
 * \summary {This is the implementation of Stack structure of this project.}
 */

#include <stdlib.h>
#include <stdio.h>

#include <ErrorCodes.h>

struct Stack {
  int capacity;
  void const * * ppArray;
};

int Stack_New (struct Stack * * ppStack, int capacity) {
  if (ppStack == NULL) return EC_NULL_POINTER;
  if (capacity < 1) return EC_OUT_OF_RANGE;

  

  return EC_OK;
}
