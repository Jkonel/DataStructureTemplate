/*
 * @Description:单链表头文件
 * @Author: Jkonel
 * @Date: 2020-04-28 14:08:22
 * @LastEditors: jkonel
 * @LastEditTime: 2020-04-28 21:55:45
 */
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
#include <stdbool.h>

//链表核心结构
typedef struct linked_List
{
    int a;  //存储数据
    struct linked_List* next;
} linked_List, *pLinked_List;


void ListInit(pLinked_List pHeader);
pLinked_List ListCreateNode(int a);

bool ListInsertNode(pLinked_List* header, pLinked_List node, int addr);
void ListInsertLastNode(pLinked_List* ppheader, pLinked_List pnode);
void ListInsertHeadNode(pLinked_List* ppheader, pLinked_List pnode);

bool ListDeleteHeadNode(pLinked_List* ppheader);
bool ListDeleteLastNode(pLinked_List* ppheader);
bool ListDeleteNode(pLinked_List* ppheader, int addr);
void ListEmptyNode(pLinked_List* ppheader);

bool ListFindNode(pLinked_List* ppheader, int addr, int* a);
pLinked_List ListReverse(pLinked_List oldHeader);



#endif
