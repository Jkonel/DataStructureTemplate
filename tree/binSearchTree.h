/*
 * @Description: binary search tree.h 
 * @Author: Jkonel
 * @Date: 2020-05-21 10:07:05
 * @LastEditors: jkonel
 * @LastEditTime: 2020-05-21 10:16:13
 */ 

#ifndef _BINSEARCHTREE_H
#define _BINSEARCHTREE_H

pBinTree BinSearchTreeFind(pBinTree bst, int x);
pBinTree BinSearchTreeFindMin(pBinTree bst);
pBinTree BinSearchTreeFindMin(pBinTree bst);

pBinTree BinSearchTreeInsert(pBinTree bst, binTreeData x);
pBinTree BinSearchTreeDelete(pBinTree bst, int x);


#endif
