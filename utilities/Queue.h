/*
 * \author {Paul Liu}
 * \summary {Interface of Queue structure in this project.}
 */

#ifndef _QUEUE_H_
#define _QUEUE_H_

int Queue_Put (struct Queue * pQueue, void const * pObj);
int Queue_Get (struct Queue * pQueue, void const * * ppObj);

#endif
