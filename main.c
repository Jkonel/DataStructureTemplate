#include <stdio.h>
#include "linkedList.h"

pLinkedList header;

union test
{
    int a;
    char b[2];
    /* data */
} testDemo;


int main(void)
{
    testDemo.b[0] = '1';
    testDemo.b[1] = '2';
    printf("%d\n", testDemo.a);
    // printf("testDemo\n");
    printf("%d\n", sizeof(float));
    getchar();
    return 0;
}
