/*
 * @Description: binary tree.h
 * @Author: Jkonel
 * @Date: 2020-05-09 09:44:57
 * @LastEditors: jkonel
 * @LastEditTime: 2020-05-21 11:08:36
 */
#ifndef _BINTREE_H
#define _BINTREE_H

#define NoInfo 0

typedef int binTreeData;

//二叉树核心结构
typedef struct bin_Tree
{
    int a;
    struct bin_Tree* left;   //左子树指针
    struct bin_Tree* right;  //右子树指针
} binTree, *pBinTree;



pBinTree BinSearchTreeDelete(pBinTree bst, int x);

void BinTreeInorderTraversal(pBinTree ptree);
void BinTreePreorderTraversal(pBinTree ptree);
void BinTreePostorderTraversal(pBinTree ptree);
void BinTreeInorderTraversal_Nrec(pBinTree ptree);

void BinTreeLevelorderTraversal(pBinTree ptree);

void BinTreeSearchLeaves(pBinTree ptree);

int BinTreeHight(pBinTree ptree);

pBinTree BinTreeLevelCreate(int dat[]);

#endif
