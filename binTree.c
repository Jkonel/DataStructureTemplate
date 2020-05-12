/*
 * @Description: binary tree.c
 * @Author: Jkonel
 * @Date: 2020-05-09 09:44:00
 * @LastEditors: jkonel
 * @LastEditTime: 2020-05-12 10:24:27
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binTree.h"

/**
 * @description: 二叉树空判断
 * @param : 二叉树头指针pTree
 * @return: true：空；false：非空
 */
bool BinTreeIfEmpty(pBinTree ptree)
{
    if (ptree == NULL) {
        return true;
    }
    else {
        return false;
    }
}

/**
 * @description: 二叉树递归中序遍历(左-根-右)
 * @param : 二叉树头指针ptree
 * @return: void
 */
void BinTreeInorderTraversal(pBinTree ptree)
{
    if (ptree != NULL) {
        BinTreeInorderTraversal(ptree->left);
        printf("%d ", ptree->a);
        BinTreeInorderTraversal(ptree->right);
    }
}

/**
 * @description: 二叉树递归先序遍历(根-左-右)
 * @param : 二叉树头指针ptree
 * @return: void
 */
void BinTreePreorderTraversal(pBinTree ptree)
{
    if (ptree != NULL) {
        printf("%d ", ptree->a);
        BinTreePreorderTraversal(ptree->left);
        BinTreePreorderTraversal(ptree->right);
    }
}

/**
 * @description: 二叉树递归后序遍历(左-右-根)
 * @param : 二叉树头指针ptree
 * @return: void
 */
void BinTreePostorderTraversal(pBinTree ptree)
{
    if (ptree != NULL) {
        BinTreePreorderTraversal(ptree->left);
        BinTreePreorderTraversal(ptree->right);
        printf("%d ", ptree->a);
    }
}

/**
 * @description: 二叉树层序遍历函数
 * @param : ptree
 * @return: void
 */
#include "queue.h"
void BinTreeLevelorderTraversal(pBinTree ptree)
{
    pQueue pqueue;
    pBinTree pTempTree;

    if (ptree == NULL)
        return;
    pqueue = QueueCreate(100);
    QueueInsert(pqueue, ptree);
    while (!QueueIfEmpty(pqueue)) {
        QueueExport(pqueue, &pTempTree);
        printf("%d ", pTempTree->a);
        if (pTempTree->left != NULL) {
            QueueInsert(pqueue, pTempTree->left);
        }
        if (pTempTree->right != NULL) {
            QueueInsert(pqueue, pTempTree->right);
        }
    }
}

/**
 * @description: 二叉树非递归中序遍历
 * @param : ptree
 * @return: void
 */
#include "stack.h"
void BinTreeInorderTraversal_Nrec(pBinTree ptree)
{
    pBinTree pLocalTree = ptree;
    pStack pstac = StackCreate(20);

    while (pLocalTree != NULL || !StackIfEmpty(pstac)) {
        while (pLocalTree != NULL) {
            StackPush(pstac, pLocalTree);  //伪代码
            pLocalTree = pLocalTree->left;
        }
        StackPop(pstac, &pLocalTree);  //伪代码
        printf("%d ", pLocalTree->a);
        pLocalTree = pLocalTree->right;
    }
}


/**
 * @description: 二叉树叶子节点输出
 * @param :ptree
 * @return:void
 */
void BinTreeSearchLeaves(pBinTree ptree)
{
    if (ptree != NULL) {
        if (ptree->left = NULL && ptree->right == NULL) {
            printf("%d ", ptree->a);
        }
        BinTreeSearchLeaves(ptree->left);
        BinTreeSearchLeaves(ptree->right);
    }
}

/**
 * @description: 二叉树高度递归求解
 * @param :ptree
 * @return:高度
 */
int BinTreeHight(pBinTree ptree)
{
    int hl, hr, hmax;
    if (ptree != NULL) {
        hl = BinTreeHight(ptree->left);
        hr = BinTreeHight(ptree->right);
        hmax = hl > hr ? hl : hr;
        return hmax + 1;
    }
    else {
        return 0;
    }
}
