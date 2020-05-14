/*
 * @Description: binary tree.h
 * @Author: Jkonel
 * @Date: 2020-05-09 09:44:57
 * @LastEditors: jkonel
 * @LastEditTime: 2020-05-14 09:09:13
 */
#ifndef _BINTREE_H
#define _BINTREE_H
typedef int binTreeData;

//二叉树核心结构
typedef struct bin_Tree
{
    int a;
    struct bin_Tree* left;   //左子树指针
    struct bin_Tree* right;  //右子树指针
} binTree, *pBinTree;



#endif
