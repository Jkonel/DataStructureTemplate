/*
 * @Description: binary tree.c
 * @Author: Jkonel
 * @Date: 2020-05-09 09:44:00
 * @LastEditors: jkonel
 * @LastEditTime: 2020-05-21 11:09:39
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


#include "queue.h"
/**
 * @description: 二叉树层序遍历函数
 * @param : ptree
 * @return: void
 */
void BinTreeLevelorderTraversal(pBinTree ptree)
{
    pQueue pqueue;  //队列元素应为pBinTree类型
    pBinTree pTempTree;

    if (ptree == NULL)
        return;
    pqueue = QueueCreate(100);
    QueueInsert(pqueue, ptree);  //根节点入队列

    while (!QueueIfEmpty(pqueue)) {
        QueueExport(pqueue, &pTempTree);  //出队列一节点
        printf("%d ", pTempTree->a);
        if (pTempTree->left != NULL) {  //入该节点的子节点
            QueueInsert(pqueue, pTempTree->left);
        }
        if (pTempTree->right != NULL) {
            QueueInsert(pqueue, pTempTree->right);
        }
    }
}


#include "stack.h"
/**
 * @description: 二叉树非递归中序遍历
 * @param : ptree
 * @return: void
 */
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



/**
 * @description: 二叉树层序生成(key:队列的应用，左右节点存在再入队列)
 * @param : dat[]:层序生成树指令数组(理论上不出错)
 * @return: pTree：生成树头节点指针
 */
pBinTree BinTreeLevelCreate(int dat[])
{
    pBinTree pTree, pT;
    pQueue pQueu = QueueCreate(100);
    int i = 1;

    if (dat[0] != NoInfo) {
        pTree = (pBinTree)malloc(sizeof(binTree));
        pTree->a = dat[0];
        pTree->left = pTree->right = NULL;
        QueueInsert(pQueu, pTree);  //头节点入队列
    }
    else {
        return NULL;
    }

    while (!QueueIfEmpty(pQueu)) {
        QueueExport(pQueu, &pT);  //取一个元素
        //左节点处理
        if (dat[i] != NoInfo) {
            pT->left = (pBinTree)malloc(sizeof(binTree));
            pT->left->a = dat[i];
            pT->left->left = pT->left->right = NULL;
            QueueInsert(pQueu, pT->left);
        }
        else {
            pT->left = NULL;
        }
        i++;
        //右节点处理
        if (dat[i] != NoInfo) {
            pT->right = (pBinTree)malloc(sizeof(binTree));
            pT->right->a = dat[i];
            pT->right->left = pT->right->right = NULL;
            QueueInsert(pQueu, pT->right);
        }
        else {
            pT->left = NULL;
        }
        i++;
    }
    return pTree;
}
