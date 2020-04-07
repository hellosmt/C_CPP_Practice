#include<stdio.h>
#include<stdlib.h>

int main()
{
    char *p = (char*)malloc(sizeof(char));
    char *pt = p;
    *p = 'q';
    free(p); // 释放
    *pt = 'c'; // 对已释放的内存进行读写
    free(pt);  // 释放两次
    return 0;
}