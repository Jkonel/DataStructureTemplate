/*
 * @Description: balanced binary tree.h
 * @Author: Jkonel
 * @Date: 2020-05-21 10:21:52
 * @LastEditors: jkonel
 * @LastEditTime: 2020-05-26 17:33:02
 */ 

#ifndef _BALANCEDBINTREE_H
#define _BALANCEDNINTREE_H
typedef int balancedBinTreeData;

//平衡二叉树核心结构
typedef struct balanced_bin_tree
{
    balancedBinTreeData a;
    struct balanced_bin_tree* left;
    struct balanced_bin_tree* right;
    int height;
} balaancedBinTree, *pBalabcedBinTree;

int AVLMax(int a, int b);
pBalabcedBinTree AVLSingleLeftRotation(pBalabcedBinTree ptree);
pBalabcedBinTree AVLSingleRightRotation(pBalabcedBinTree ptree);
pBalabcedBinTree AVLDoubleLeftRightRotation(pBalabcedBinTree ptree);
pBalabcedBinTree AVLDoubleRightLeftRotation(pBalabcedBinTree ptree);
pBalabcedBinTree AVLInsert(pBalabcedBinTree ptree, balancedBinTreeData x);

#endif
