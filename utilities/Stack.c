/*
 * \author {Paul Liu}
 * \summary {This is the implementation of Stack structure of this project.}
 */

#include <stdlib.h>
#include <stdio.h>

#include <ErrorCodes.h>

struct Stack {
  int capacity;
  int top;
  void const * * ppArray;
};

int Stack_New (struct Stack * * ppStack, int capacity) {
  struct Stack * pStack = NULL;
  void * pArray = NULL;

  if (ppStack == NULL) return EC_NULL_POINTER;
  if (capacity < 1) return EC_OUT_OF_RANGE;
  
  pArray = malloc (capacity * sizeof (void const *));
  if (pArray == NULL) return EC_OUT_OF_MEMORY;

  pStack = malloc (sizeof (struct Stack));
  if (pStack == NULL) {
    free (pArray);
    return EC_OUT_OF_MEMORY;
  }
  pStack -> capacity = capacity;
  pStack -> top = -1;
  pStack -> ppArray = pArray;

  * ppStack = pStack;
  return EC_OK;
}

int Stack_Delete (struct Stack * pStack) {
  if (pStack == NULL) return EC_NULL_POINTER;
  if (pStack -> ppArray == NULL) return EC_IMPOSSIBLE_CASE;
  free (pStack -> ppArray);
  free (pStack);
  return EC_OK;
}

int Stack_Push (struct Stack * pStack, void const * pObj) {
  if (pStack == NULL) return EC_NULL_POINTER;
  if (pObj == NULL) return EC_NULL_POINTER;
  if (pStack -> ppArray == NULL) return EC_IMPOSSIBLE_CASE;
  if (pStack -> top < -1) return EC_IMPOSSIBLE_CASE;
  if (pStack -> top > pStack -> capacity - 2) return EC_STACK_OVERFLOW;

  ++ (pStack -> top);
  pStack -> ppArray [pStack -> top] = pObj;
  return EC_OK;
}

int Stack_Pop (struct Stack * pStack, void const * * ppObj) {
  if (pStack == NULL) return EC_NULL_POINTER;
  if (ppObj == NULL) return EC_NULL_POINTER;
  if (pStack -> ppArray == NULL) return EC_IMPOSSIBLE_CASE;
  if (pStack -> top > pStack -> capacity - 1) return EC_IMPOSSIBLE_CASE;
  if (pStack -> top < 0) return EC_OUT_OF_RANGE;

  -- (pStack -> top);
  * ppObj = pStack -> ppArray [pStack -> top];
  return EC_OK;
}

int Stack_GetTop (struct Stack * pStack, void const * * ppObj) {
  if (pStack == NULL) return EC_NULL_POINTER;
  if (ppObj == NULL) return EC_NULL_POINTER;
  if (pStack -> ppArray == NULL) return EC_IMPOSSIBLE_CASE;
  if (pStack -> top < 0) return EC_OUT_OF_RANGE;
  if (pStack -> top > pStack -> capacity - 1) return EC_IMPOSSIBLE_CASE;

  * ppObj = pStack -> ppArray [pStack -> top];
  return EC_OK;
}

int Stack_IsEmpty (struct Stack * pStack, int * pEmpty) {
  if (pStack == NULL) return EC_NULL_POINTER;
  if (pEmpty == NULL) return EC_NULL_POINTER;
  if (pStack -> top < 0) * pEmpty = TRUE;
  else * pEmpty = FALSE;
  return EC_OK;
}
