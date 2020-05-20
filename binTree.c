/*
 * @Description: binary tree.c
 * @Author: Jkonel
 * @Date: 2020-05-09 09:44:00
 * @LastEditors: jkonel
 * @LastEditTime: 2020-05-19 08:36:44
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


/**
 * @description: 二叉树层序生成
 * @param :
 * @return:
 */


/*****二叉搜索树*****/
/**
 * @description: 二叉搜索树查找相应值
 * @param :bst
 * @return:ptree
 */
pBinTree BinSearchTreeFind(pBinTree bst, int x)
{
    // if (bst == NULL) {
    // return NULL;
    //}

    // if (bst->a > x) {
    // BSTFind(bst->left, x);
    //}
    // else if (bst->a < x) {
    // BSTFind(bst->right, x);
    //}
    // else {
    // return bst;
    //}
    while (bst != NULL) {
        if (bst->a > x) {
            bst = bst->left;
        }
        else if (bst->a < x) {
            bst = bst->right;
        }
        else {
            break;
        }
    }
    return bst;
}

/**
 * @description: 二叉搜索树查找最小值
 * @param :bst
 * @return:ptree
 */
pBinTree BinSearchTreeFindMin(pBinTree bst)
{
    if (bst != NULL) {
        while (bst->left != NULL) {
            bst = bst->left;
        }
    }
    return bst;
}

/**
 * @description: 二叉搜索树查找最大值
 * @param :bst
 * @return:ptree
 */
pBinTree BinSearchTreeFindMax(pBinTree bst)
{
    if (bst != NULL) {
        while (bst->right != NULL) {
            bst = bst->right;
        }
    }
    return bst;
}

/**
 * @description: 二叉搜索树插入一个元素
 * @param : bst；x
 * @return: ptree
 */
pBinTree BinSearchTreeInsert(pBinTree bst, binTreeData x)
{
    if (bst == NULL) {
        bst = (pBinTree)malloc(sizeof(binTree));
        bst->a = x;
    }
    else if (bst->a > x) {  //插入二叉搜索树一定在叶子节点
        bst->left = BinSearchTreeInsert(bst->left, x);
    }
    else if (bst->a < x) {
        bst->right = BinSearchTreeInsert(bst->right, x);
    }  //相等时，直接返回原节点，到叶子时返回生成的新节点
    return bst;
}

/**
 * @description:二叉搜索树删除元素
 * @param :bst；x
 * @return:ptree
 */
pBinTree BinSearchTreeDelete(pBinTree bst, int x)
{
    pBinTree temp;

    if (bst != NULL) {
        if (bst->a > x) {
            bst->left = BinSearchTreeDelete(bst->left, x);
        }
        else if (bst->a < x) {
            bst->right = BinSearchTreeDelete(bst->right, x);
        }
        else {  //找到要删除的节点
            if (bst->left != NULL && bst->right != NULL) {
                //两个子节点，取右边最小元素
                temp = BinSearchTreeFindMin(bst->right);
                bst->a = temp->a;
                BinSearchTreeDelete(bst->right, temp->a);
            }
            else {  //一个或没节点，直接赋值，释放
                temp = bst;
                if (bst->left == NULL) {
                    bst = bst->right;
                }
                else {
                    bst = bst->left;
                }
                free(temp);
            }
        }
    }
    return bst;
}
