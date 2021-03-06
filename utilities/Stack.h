/*
 * \author {Paul Liu}
 * \summary {Interface of Stack structure of this project.}
 */

#ifndef _STACK_H_
#define _STACK_H_

struct Stack;

int Stack_New (struct Stack * * ppStack, int capacity);
int Stack_Delete (struct Stack* pStack);

int Stack_Push (struct Stack * pStack, void const * pObj);
int Stack_Pop (struct Stack * pStack, void const * * ppObj);
int Stack_GetTop (struct Stack * pStack, void const * * ppObj);
int Stack_IsEmpty (struct Stack * pStack, int * pEmpty);

#endif
