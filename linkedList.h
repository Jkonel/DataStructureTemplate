#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H


//链表核心结构
typedef struct linked_List
{
    int a;  //存储数据
    struct linked_List* next;
} linked_List, *pLinked_List;


#endif
