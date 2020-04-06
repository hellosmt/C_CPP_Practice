#include<stdlib.h>
void fun()
{
    int *p = (int*)malloc(10*sizeof(int));
    p[10]=0; // 堆空间数组访问越界，编译能成功
}

int main(int argc, char* argv[])
{
    fun();
    return 0;
}