/*
 * @Description: balanced binary tree.h
 * @Author: Jkonel
 * @Date: 2020-05-21 10:21:52
 * @LastEditors: jkonel
 * @LastEditTime: 2020-05-26 08:59:29
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


#endif
