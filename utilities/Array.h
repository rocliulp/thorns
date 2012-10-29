/*
 * \author {Paul Liu}
 * \summary {Array interface}
 */

#ifndef _ARRAY_H_
#define _ARRAY_H_

struct Array;

int Array_New (struct Array * * ppArray, int capacity);
int Array_Delete (struct Array * pArray);

int Array_GetCapacity (struct Array * pArray, int pCapacity);
#endif
