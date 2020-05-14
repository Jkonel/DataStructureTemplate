/*
 * @Description: stack.h
 * @Author: Jkonel
 * @Date: 2020-05-07 09:12:21
 * @LastEditors: jkonel
 * @LastEditTime: 2020-05-14 09:02:28
 */
#ifndef _STACK_H
#define _STACK_H
typedef int stackData;

//栈核心结构
typedef struct 
{
    stackData * data;
    int top;
    int maxSize;
}stack,*pStack;

pStack StackCreate(int maxSize);
bool StackIfFull(pStack pstack);
bool StackIfEmpty(pStack pstack);

bool StackPush(pStack pstack, stackData dat);
bool StackPop(pStack pstack, stackData* dat);

#endif
