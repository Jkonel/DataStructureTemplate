/*
 * @Description:单链表源文件
 * @Author: Jkonel
 * @Date: 2020-04-28 10:57:47
 * @LastEditors: jkonel
 * @LastEditTime: 2020-05-09 09:03:43
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "singleList.h"


/**
 * @description: 单链表初始化
 * @param : 链表头指针
 * @return: void
 */
void ListInit(pLinked_List pheader)
{
    pheader = NULL;
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
 * @description: 单链表插入节点函数(无空头节点，从0开始计算第一个节点)
 * @param :header:链表头二级指针;
 *         node:待插入节点;
 *         addr:待插入下标(从0开始)
 * @return:true:插入成功
 *         false:插入失败
 */
bool ListInsertNode(pLinked_List* ppheader, pLinked_List pnode, int addr)
{
    pLinked_List* pplink = ppheader;
    pLinked_List pcurrent = *ppheader;
    int cnt = 0;  // current现在的节点下标，从0开始

    while (pcurrent != NULL && cnt < addr) {
        pplink = &pcurrent->next;
        pcurrent = (*pplink);
        cnt++;
    }
    if (pcurrent != NULL) {
        (*pplink) = pnode;
        pnode->next = pcurrent;
        return true;
    }
    else {
        return false;  //链表长度不够
    }
}

/**
 * @description:单链表尾插函数
 * @param : header：链表二级头指针；
 *          node：待插入的节点
 * @return: void
 */
void ListInsertLastNode(pLinked_List* ppheader, pLinked_List pnode)
{
    pLinked_List* pplink = ppheader;
    while ((*pplink) != NULL) {
        pplink = &(*pplink)->next;
    }
    *pplink = pnode;
    pnode->next = NULL;
}

/**
 * @description: 单链表头插函数
 * @param : header：链表二级头指针；
 *          node：待插入的节点
 * @return: void
 */
void ListInsertHeadNode(pLinked_List* ppheader, pLinked_List pnode)
{
    pnode->next = (*ppheader);
    *ppheader = pnode;
}

/**
 * @description: 单链表头节点删除函数
 * @param : ppheader链表二级头指针
 * @return: true：删除成功
 *          false：删除失败(没有节点)
 */
bool ListDeleteHeadNode(pLinked_List* ppheader)
{
    if (*ppheader != NULL) {
        pLinked_List temp = *ppheader;
        *ppheader = (*ppheader)->next;
        free(temp);
        return true;
    }
    else {
        return false;
    }
}

/**
 * @description:单链表尾节点删除函数
 * @param : ppheader:链表二级头指针
 * @return: true：删除成功
 *          false：删除失败(没有节点)
 */
bool ListDeleteLastNode(pLinked_List* ppheader)
{
    if (*ppheader != NULL) {
        pLinked_List* pplink = ppheader;
        while ((*pplink)->next != NULL) {
            pplink = &(*pplink)->next;
        }
        free(*pplink);
        *pplink = NULL;
        return true;
    }
    else {
        return false;
    }
}

/**
 * @description: 单链表节点删除函数
 * @param : ppheader：链表二级头指针；
 *          addr：待删除节点下标(从0开始)
 * @return: true：删除成功
 *          false：删除失败(没有该节点)
 */
bool ListDeleteNode(pLinked_List* ppheader, int addr)
{
    pLinked_List* pplink = ppheader;
    pLinked_List temp;
    int cnt = 0;

    while ((*pplink) != NULL && cnt < addr) {
        pplink = &(*pplink)->next;
        cnt++;
    }
    if ((*pplink) != NULL) {
        temp = (*pplink)->next;
        free(*pplink);
        *pplink = temp;
        return true;
    }
    else {
        return false;
    }
}

/**
 * @description: 单链表清空函数
 * @param : 链表二级头指针
 * @return: void
 */
void ListEmptyNode(pLinked_List* ppheader)
{
    pLinked_List* pplink = ppheader;
    pLinked_List temp;
    while ((*pplink) != NULL) {
        temp = (*pplink);
        *pplink = (*pplink)->next;
        free(temp);
    }
}

/**
 * @description: 单链表搜索函数
 * @param : ppheader：单链表二级头指针
 *          addr：查找结点下标(从0开始)
 *          a:查找结点数据指针
 * @return: true：查找成功
 *          false：查找失败(没有该节点)
 */
bool ListFindNode(pLinked_List* ppheader, int addr, int* a)
{
    pLinked_List* pplink = ppheader;
    int cnt = 0;

    while ((*pplink) != NULL && cnt < addr) {
        pplink = &(*pplink)->next;
        cnt++;
    }
    if ((*pplink) != NULL) {
        *a = (*pplink)->a;
        return true;
    }
    else {
        return false;
    }
}

/**
 * @description: 单链表长度读取函数
 * @param : ppheader：链表二级头指针
 * @return: 链表长度(真实长度)
 */
int ListLength(pLinked_List* ppheader)
{
    int cnt = 0;
    pLinked_List* pplink = ppheader;

    while ((*pplink) != NULL) {
        cnt++;
        pplink = &(*pplink)->next;
    }
    return cnt;
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



// homework:
/**
 * @description: 递归遍历单链表函数
 * @param : 链表二级头指针
 * @return: void
 */
void ListThrouth(pLinked_List pheader)
{
    if (pheader->next == NULL) {
        printf("%d ", pheader->a);  // 逆序输出
    }
    else {
        ListThrouth(pheader->next);
    }
    /*
            if (pheader->next != NULL) {
             printf("%d ", pheader->a);//顺序输出
             ListThrouth(pheader->next);
         }
         else {
             return;
         }
    */
}


/**
 * @description: 删除单链表中整数元素()
 * @param :链表二级头指针
 * @return:void
 */
void ListDeletePositive(pLinked_List* ppheader)
{
    pLinked_List* pplink = ppheader;
    pLinked_List temp;

    while ((*pplink) != NULL) {
        if ((*pplink)->a > 0) {
            temp = *pplink;
            *pplink = (*pplink)->next;
            free(temp);
        }
        else {
            pplink = &(*pplink)->next;
        }
    }
}

/**
 * @description: 交换相邻序号为奇偶的元素
 * @param : 链表二级头指针
 * @return: void
 */
void ListSwitch(pLinked_List* ppheader)
{
    pLinked_List plink = *ppheader;      //当前节点指针
    pLinked_List* prepplink = ppheader;  //前一节点二级指针
    pLinked_List temp;                   //临时结点指针

    while (plink->next != NULL) {
        temp = (plink->next)->next;
        *prepplink = plink->next;
        (plink->next)->next = plink;
        plink->next = temp;
        prepplink = &(*prepplink)->next;
    }
}

/**
 * @description: 和并生成新链表
 * @param : 原链表二级头指针
 * @return: 新链表头指针
 */
pLinked_List ListCreateNewList(pLinked_List* ppheader)
{
    pLinked_List plink = *ppheader;
    pLinked_List pheader;
    pLinked_List pnode;

    while (plink->next != NULL) {
        ListInsertLastNode(&pheader, ListCreateNode(plink->a + plink->next->a));
        if (plink->next->next != NULL) {
            plink = plink->next->next;
        }
        else {
            return pheader;
        }
    }
    ListInsertLastNode(&pheader, ListCreateNode(plink->a));
    return pheader;
}
