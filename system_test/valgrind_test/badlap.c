#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 内存覆盖
int main()
{
    char x[50];
    int i;
    for(i = 0 ; i < 50; i++)
    {
        x[i] = i+1;
    }

    strncpy(x+20, x, 20);//ok
    strncpy(x+20, x, 21);//overlap
    strncpy(x, x+20, 20);//ok
    strncpy(x, x+20, 21);//overlap
    return 0;
}