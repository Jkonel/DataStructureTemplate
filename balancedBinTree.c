/*
 * @Description: balanced binary tree.c
 * @Author: Jkonel
 * @Date: 2020-05-21 10:21:41
 * @LastEditors: jkonel
 * @LastEditTime: 2020-05-26 10:39:22
 */
#include <stdio.h>
#include <stdbool.h>
#include "balancedBinTree.h"
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
 * @description: 平衡树左单旋调整
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
 * @description: 平衡树右单旋调整
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
 * @description: 平衡树左右双旋调整
 * @param : 局部根节点ptree
 * @return: 调整后的局部根节点
 */
pBalabcedBinTree AVLDoubleLeftRightRotation(pBalabcedBinTree ptree)
{
    ptree->left = AVLSingleRightRotation(ptree->left);
    return AVLSingleLeftRotation(ptree);
}

/**
 * @description: 平衡树右左双旋调整
 * @param : 局部根节点ptree
 * @return: 调整后的局部根节点
 */
pBalabcedBinTree AVLDoubleRightLeftRotation(pBalabcedBinTree ptree)
{
    ptree->right = AVLSingleLeftRotation(ptree->right);
    return AVLSingleRightRotation(ptree);
}
