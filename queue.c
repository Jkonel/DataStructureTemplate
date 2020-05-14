/*
 * @Description: queue.c
 * @Author: Jkonel
 * @Date: 2020-05-07 09:58:46
 * @LastEditors: jkonel
 * @LastEditTime: 2020-05-14 08:59:24
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"

/**
 * @description: 队列创建函数
 * @param : maxSize
 * @return: pqueue
 */
pQueue QueueCreate(int maxSize)
{
    pQueue pqueue = (pQueue)malloc(sizeof(queue));
    pqueue->data = (queueData*)malloc(maxSize * sizeof(queueData));
    pqueue->front = 0;
    pqueue->rear = 0;
    pqueue->maxSize = maxSize;
    return pqueue;
}

/**
 * @description: 队列满判断
 * @param : pqueue
 * @return: true:满；false：非满
 */
bool QueueIfFull(pQueue pqueue)
{
    return ((pqueue->rear + 1) % pqueue->maxSize == pqueue->front);
}

/**
 * @description: 队列空判断
 * @param : pqueue
 * @return: true：空；false：非空
 */
bool QueueIfEmpty(pQueue pqueue)
{
    return (pqueue->front == pqueue->rear);
}

/**
 * @description: 队列插入函数
 * @param : pqueue；dat
 * @return: true：插入成功；false：插入失败
 */
bool QueueInsert(pQueue pqueue, queueData dat)
{
    if (QueueIfEmpty(pqueue)) {
        return false;
    }
    else {
        pqueue->rear = (pqueue->rear + 1) % pqueue->maxSize;
        pqueue->data[pqueue->rear] = dat;
        return true;
    }
}

/**
 * @description: 队列输出元素
 * @param :pqueue；dat*
 * @return:true：输出成功；false：输出失败
 */
bool QueueExport(pQueue pqueue, queueData* dat)
{
    if (QueueIfEmpty(pqueue)) {
        return false;
    }
    else {
        pqueue->front = (pqueue->front + 1) % pqueue->maxSize;
        *dat = pqueue->data[pqueue->front];
        return true;
    }
}
