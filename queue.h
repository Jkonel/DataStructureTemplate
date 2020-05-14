/*
 * @Description: queue.h
 * @Author: Jkonel
 * @Date: 2020-05-07 09:58:56
 * @LastEditors: jkonel
 * @LastEditTime: 2020-05-14 08:58:18
 */
#ifndef _QUEUE_H
#define _QUEUE_H

typedef int queueData;

//队列核心结构
typedef struct
{
    queueData* data;//任意类型指针
    int front, rear;
    int maxSize;
} queue, *pQueue;

pQueue QueueCreate(int maxSize);

bool QueueIfFull(pQueue pqueue);
bool QueueIfEmpty(pQueue pqueue);

bool QueueInsert(pQueue pqueue, queueData dat);
bool QueueExport(pQueue pqueue, queueData* dat);


#endif
