/*
 * @Description: binary tree.c
 * @Author: Jkonel
 * @Date: 2020-05-09 09:44:00
 * @LastEditors: jkonel
 * @LastEditTime: 2020-05-09 10:07:57
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
