#include "linkedList.h"
#include <stdio.h>

pLinkedList Header;

//逆序链表
pLinkedList reverse(pLinkedList oldHeader)
{
    pLinkedList pOldLink, pNewLink, ptemp;
    pOldLink = oldHeader;
    pNewLink = NULL;

    while (pOldLink != NULL) {
        ptemp = pOldLink->next;     //处理位置原始后移预备
        pOldLink->next = pNewLink;  //链表指向交换
        pNewLink = pOldLink;        //链表指向交换
        pOldLink = ptemp;           //处理位置原始后移
    }
    return pNewLink;  //设置新链表头
}
