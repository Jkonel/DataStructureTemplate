/*
 * @Description: Binary Search Tree.c
 * @Author: Jkonel
 * @Date: 2020-05-21 10:06:30
 * @LastEditors: jkonel
 * @LastEditTime: 2020-05-21 10:14:25
 */
#include <stdio.h>
#include <stdbool.h>
#include "binSearchTree.h"
#include "binTree.h"

/*
    与二叉树的区别：左子树节点值<该节点值<右子树节点值
*/

/**
 * @description: 二叉搜索树查找相应值
 * @param :bst
 * @return:ptree
 */
pBinTree BinSearchTreeFind(pBinTree bst, int x)
{
    //递归查找
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

    //循环查找
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
    else if (bst->a > x) {  //插入二叉搜索树一定在叶子节点(KEY)
        bst->left = BinSearchTreeInsert(bst->left, x);  //递归调用
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
