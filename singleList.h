/*
 * @Description:单链表头文件
 * @Author: Jkonel
 * @Date: 2020-04-28 14:08:22
 * @LastEditors: jkonel
 * @LastEditTime: 2020-04-28 14:13:33
 */
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

//链表核心结构
typedef struct linked_List
{
    int a;  //存储数据
    struct linked_List* next;
} linked_List, *pLinked_List;


void ListInit(pLinked_List pHeader);
pLinked_List ListCreateNode(int a);
bool ListInsertNode(pLinked_List* header, pLinked_List node, int addr);
pLinked_List ListReverse(pLinked_List oldHeader);



#endif
