/*
 * @Description: queue.h
 * @Author: Jkonel
 * @Date: 2020-05-07 09:58:56
 * @LastEditors: jkonel
 * @LastEditTime: 2020-05-12 10:28:48
 */
#ifndef _QUEUE_H
#define _QUEUE_H

//队列核心结构
typedef struct
{
    int* data;//任意类型指针
    int front, rear;
    int maxSize;
} queue, *pQueue;

pQueue QueueCreate(int maxSize);

bool QueueIfFull(pQueue pqueue);
bool QueueIfEmpty(pQueue pqueue);

bool QueueInsert(pQueue pqueue, int dat);
bool QueueExport(pQueue pqueue, int* dat);


#endif
