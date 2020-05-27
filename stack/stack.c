/*
 * @Description: Stack.c
 * @Author: Jkonel
 * @Date: 2020-05-07 09:08:57
 * @LastEditors: jkonel
 * @LastEditTime: 2020-05-14 09:03:45
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

/**
 * @description: 创建栈
 * @param : maxSize
 * @return: pStack
 */
pStack StackCreate(int maxSize)
{
    pStack pstack = (pStack)malloc(sizeof(stack));
    pstack->data = (stackData*)malloc(maxSize * sizeof(stackData));
    pstack->top = -1;
    pstack->maxSize = maxSize;
    return pstack;
}

/**
 * @description: 栈是否已满判断
 * @param : pStack
 * @return: true:满；false:非满
 */
bool StackIfFull(pStack pstack)
{
    return (pstack->top == pstack->maxSize - 1);
}

/**
 * @description: 栈是否为空判断
 * @param : pstack
 * @return: true：空；false：非空
 */
bool StackIfEmpty(pStack pstack)
{
    return (pstack->top == -1);
}


/**
 * @description: 入栈操作函数
 * @param : pstack，dat
 * @return: true:succeed；false：!
 */
bool StackPush(pStack pstack, stackData dat)
{
    if (StackIfFull(pstack)) {
        return false;
    }
    else {
        pstack->data[++(pstack->top)] = dat;
        return true;
    }
}


/**
 * @description: 出栈操作函数
 * @param : pstack；dat*
 * @return: true：出栈成功；false：出栈失败
 */
bool StackPop(pStack pstack, stackData* dat)
{
    if (StackIfEmpty(pstack)) {
        return false;
    }
    else {
        *dat = pstack->data[(pstack->top)--];
        return true;
    }
}
