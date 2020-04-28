/*
 * @Description:main.c
 * @Author: Jkonel
 * @Date: 2020-04-28 14:08:22
 * @LastEditors: jkonel
 * @LastEditTime: 2020-04-28 21:57:32
 */
#include <stdio.h>
#include "singleList.h"

pLinked_List Header;


int main(int argc, char* argv[])
{
    int a = 0;

    ListInit(Header);
    for (int i = 0; i < 10; i++) {
        ListInsertLastNode(&Header, ListCreateNode(i));
    }
    for (int i = 0; i < 10; i++) {
        ListFindNode(&Header, i, &a);
        printf("%d ", a);
    }
    getchar();
    ListEmptyNode(&Header);
    return 0;
}
