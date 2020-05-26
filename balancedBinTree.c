/*
 * @Description: balanced binary tree.c
 * @Author: Jkonel
 * @Date: 2020-05-21 10:21:41
 * @LastEditors: jkonel
 * @LastEditTime: 2020-05-26 17:30:46
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "balancedBinTree.h"

/**
 * @description: 平衡树深度求解
 * @param : 求解节点的左右子节点
 * @return: 左右子节点的最大深度
 */
int AVLMax(int a, int b)
{
    return a > b ? a : b;
}

/**
 * @description: 平衡树左单旋调整(左侧子树左节点调整)
 * @param : 调整局部根节点ptree
 * @return: 调整后的局部根节点
 */
pBalabcedBinTree AVLSingleLeftRotation(pBalabcedBinTree ptree)
{
    pBalabcedBinTree pB = ptree->left;
    ptree->left = pB->right;
    pB->right = ptree;

    ptree->height = AVLMax(ptree->left, ptree->right) + 1;
    pB->height = AVLMax(pB->left, pB->right) + 1;

    return pB;
}

/**
 * @description: 平衡树右单旋调整(右侧子树右节点调整)
 * @param : 局部根节点ptree
 * @return: 调整后的局部根节点
 */
pBalabcedBinTree AVLSingleRightRotation(pBalabcedBinTree ptree)
{
    pBalabcedBinTree pB = ptree->right;
    ptree->right = pB->left;
    pB->left = ptree;

    ptree->height = AVLMax(ptree->left, ptree->right) + 1;
    pB->height = AVLMax(pB->left, pB->right) + 1;

    return pB;
}

/**
 * @description: 平衡树左右双旋调整(左侧子树右节点调整)
 * @param : 局部根节点ptree
 * @return: 调整后的局部根节点
 */
pBalabcedBinTree AVLDoubleLeftRightRotation(pBalabcedBinTree ptree)
{
    //右旋+左旋
    ptree->left = AVLSingleRightRotation(ptree->left);
    return AVLSingleLeftRotation(ptree);
}

/**
 * @description: 平衡树右左双旋调整(右侧子树左节点调整)
 * @param : 局部根节点ptree
 * @return: 调整后的局部根节点
 */
pBalabcedBinTree AVLDoubleRightLeftRotation(pBalabcedBinTree ptree)
{
    //左旋+右旋
    ptree->right = AVLSingleLeftRotation(ptree->right);
    return AVLSingleRightRotation(ptree);
}


pBalabcedBinTree AVLInsert(pBalabcedBinTree ptree, balancedBinTreeData x)
{
    if (ptree == NULL) {  //递归插入
        ptree = (pBalabcedBinTree)malloc(sizeof(balaancedBinTree));
        ptree->a = x;
        ptree->height = 1;
        ptree->left = ptree->right = NULL;
    }
    else if (x < ptree->a) {  //插入左子树
        ptree->left = AVLInsert(ptree->left, x);

        if ((ptree->left->height - ptree->right->height) ==
            2) {  //插入左子树后不平衡
            if (x < ptree->left->a) {
                ptree = AVLSingleLeftRotation(ptree);  //左单旋
            }
            else {
                ptree = AVLDoubleLeftRightRotation(ptree);  //左右旋
            }
        }
    }
    else if (x > ptree->a) {  //插入右子树
        ptree->right = AVLInsert(ptree->right, x);

        if ((ptree->left->height - ptree->right->height) ==
            -2) {  //插入右子树后不平衡
            if (x > ptree->right->a) {
                ptree = AVLSingleRightRotation(ptree);  //右单旋
            }
            else {
                ptree = AVLDoubleRightLeftRotation(ptree);  //右左旋
            }
        }
    }

    ptree->height =
        AVLMax(ptree->left->height, ptree->right->height) + 1;  //高度更新

    return ptree;
}
