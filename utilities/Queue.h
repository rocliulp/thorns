/*
 * \author {Paul Liu}
 * \summary {Interface of Queue structure in this project.}
 */

#ifndef _QUEUE_H_
#define _QUEUE_H_

struct Queue;

int Queue_New (struct Queue * * ppQueue, int capacity);
int Queue_Delete (struct Queue * pQueue);

int Queue_Put (struct Queue * pQueue, void const * pObj);
int Queue_Get (struct Queue * pQueue, void * * ppObj);
int Queue_IsEmpty (struct Queue * pQueue, int * pEmpty);

#endif
