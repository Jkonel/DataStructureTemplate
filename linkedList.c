/*
 * @Description:单链表相关操作文件
 * @Author: Jkonel
 * @Date: 2020-04-28 10:57:47
 * @LastEditors: jkonel
 * @LastEditTime: 2020-04-28 14:02:34
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"


/**
 * @description: 单链表初始化
 * @param : 链表头指针
 * @return: null
 */
void ListInit(pLinked_List pHeader)
{
    pHeader = NULL;
}

/**
 * @description: 单链表节点创建函数
 * @param :a:节点数据
 * @return:创建的节点
 */
pLinked_List ListCreateNode(int a)
{
    pLinked_List pnode;
    pnode = (pLinked_List)malloc(sizeof(linked_List));
    pnode->a = a;  //数据初始化
    pnode->next = NULL;
    return pnode;
}


/**
 * @description: 单链表插入节点函数
 * @param :header:链表头二级指针;
 *         node:待插入节点;
 *         addr:待插入下标(从0开始)
 * @return:true:插入成功
 *         false:插入失败
 */
bool ListInsertNode(pLinked_List* header, pLinked_List node, int addr)
{
    pLinked_List* pplink = header;
    pLinked_List current = (*header)->next;
    int cnt = 0;  // current现在的节点下标，从0开始

    while (current != NULL && cnt < addr) {
        pplink = &current->next;
        current = (*pplink)->next;
        cnt++;
    }
    if (current != NULL) {
        (*pplink) = node;
        node->next = current;
        return true;
    }
    else {
        return false;
    }
}

/**
 * @description: 链表逆序函数
 * @param : 处理前链表头指针
 * @return: 处理后链表头指针
 */
pLinked_List ListReverse(pLinked_List oldHeader)
{
    pLinked_List pOldList, pNewList, ptemp;
    pOldList = oldHeader;
    pNewList = NULL;

    while (pOldList != NULL) {
        ptemp = pOldList->next;     //处理位置原始后移预备
        pOldList->next = pNewList;  //链表指向交换
        pNewList = pOldList;        //链表指向交换
        pOldList = ptemp;           //处理位置原始后移
    }
    return pNewList;  //设置新链表头
}
