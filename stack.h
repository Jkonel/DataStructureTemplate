/*
 * @Description: stack.h
 * @Author: Jkonel
 * @Date: 2020-05-07 09:12:21
 * @LastEditors: jkonel
 * @LastEditTime: 2020-05-07 09:45:30
 */
#ifndef _STACK_H
#define _STACK_H

//栈核心结构
typedef struct 
{
    int * data;
    int top;
    int maxSize;
}stack,*pStack;

pStack StackCreate(int maxSize);
bool StackIfFull(pStack pstack);
bool StackIfEmpty(pStack pstack);

bool StackPush(pStack pstack, int dat);
bool StackPop(pStack pstack, int* dat);

#endif
