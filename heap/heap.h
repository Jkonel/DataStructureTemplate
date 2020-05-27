/*
 * @Description: 
 * @Author: Jkonel
 * @Date: 2020-05-26 17:49:41
 * @LastEditors: jkonel
 * @LastEditTime: 2020-05-26 19:16:00
 */ 
#ifndef _HEAP_H
#define _HEAP_H
#define MAXHEAPDATA 1000

typedef int heapData;

//堆核心结构
typedef struct {
    heapData* dat;
    int cureentSize;
    int maxSize;
} heap, *pHeap, maxHeap, *pMaxHeap, minHeap, *pMinHeap;

bool HeapIfFull(pHeap pheap);
bool HeapIfEmpty(pHeap pheap);
pMaxHeap MaxHeapCreate(int maxSize);
bool MaxHeapInsert(pMaxHeap pheap, heapData x);
bool MaxHeapDeletMax(pMaxHeap pheap, heapData* res);

#endif
