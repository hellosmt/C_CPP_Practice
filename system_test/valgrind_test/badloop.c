// valgrind示例----使用未初始化的内存
#include<stdio.h>

int main(void)
{
    int a[5];
    int i, s;
    a[0] = a[1] =a[3] =a[4] = 0;
    s = 0;
    for(i = 0 ; i< 5; i++)
    {
        s += a[i]; // a[2]没有被初始化
    }
    if(s ==  377)
    {
        printf("sum is %d\n", s);
    }
    return 0;
}
