/*
 * @Description:
 * @Author: Jkonel
 * @Date: 2020-05-26 17:49:23
 * @LastEditors: jkonel
 * @LastEditTime: 2020-05-26 19:13:33
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heap.h"

bool HeapIfFull(pHeap pheap)
{
    return (pheap->cureentSize == pheap->maxSize);
}

bool HeapIfEmpty(pHeap pheap)
{
    return (pheap->cureentSize == 0);
}

pMaxHeap MaxHeapCreate(int maxSize)
{
    pMaxHeap pmaxHeap = (pMaxHeap)malloc(sizeof(maxHeap));
    pmaxHeap->dat = (heapData*)malloc(sizeof(heapData) *
                                      (maxSize + 1));  //多一个，第一个不使用
    pmaxHeap->cureentSize = 0;
    pmaxHeap->maxSize = maxSize;
    pmaxHeap->dat[0] = MAXHEAPDATA;  //哨兵

    return pmaxHeap;
}


bool MaxHeapInsert(pMaxHeap pheap, heapData x)
{
    int i = ++(pheap->cureentSize);

    if (HeapIfFull(pheap))
        return false;  //堆满

    for (; pheap->dat[i / 2] < x; i /= 2) {
        pheap->dat[i] = pheap->dat[i / 2];  // i/2为i元素的父元素，shift-up操作
    }
    pheap->dat[i] = x;

    return true;
}

bool MaxHeapDeletMax(pMaxHeap pheap, heapData* res)
{
    if (HeapIfEmpty(pheap))
        return false;  //堆空

    *res = pheap->dat[1];
    heapData m = pheap->dat[pheap->cureentSize--];
    int parentIndex = 1;
    int sonIndex;

    for (; parentIndex * 2 <= pheap->maxSize; parentIndex = sonIndex) {
        sonIndex = parentIndex * 2;  // 由父节点索引求相应的子节点索引
        if ((sonIndex != pheap->maxSize) &&  //子节点未到达堆尾
            (pheap->dat[sonIndex] <
             pheap->dat[sonIndex + 1])) {  //取最大的子节点
            sonIndex++;
        }
        if (m >= pheap->dat[sonIndex])  //位置合适，结束shift-down
            break;
        else
            pheap->dat[parentIndex] = pheap->dat[sonIndex];  // shift-down
    }
    pheap->dat[parentIndex] = m;

    return true;
}
