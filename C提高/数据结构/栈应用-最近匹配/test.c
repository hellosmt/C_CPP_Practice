/*
 * @Author: your name
 * @Date: 2019-10-28 11:00:36
 * @LastEditTime: 2019-10-28 11:54:13
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C\C_CPP\C提高\数据结构\栈应用-最近匹配\test.c
 */
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"SeqStack.h"


int isLeft(char c)
{
    return c == '(';
}

int isRight(char c)
{
    return c == ')';
}

void test()
{
    const char* str = "5+5*((1+2)+9/3*1)-(1)+3" ;
    SeqStack s = Init_SeqStack();
    char *p = (char*)str;//这里要强转
    while (*p!='\0')
    {
        //是左括号就压栈
        if (isLeft(*p))
        {
            Push_SeqStack(s,p);
        }
        //是右括号就出栈进行匹配
        if (isRight(*p))
        {   
            //栈里没有左括号了，则匹配失败
            if (GetSize_SeqStack(s)==0)
            {
                printf("%s\n", str);
                for (int i = 0; i < p-str; i++)
                {
                    printf(" ");
                }
                printf("^\n");
                return;
            }
            //从栈顶拿出左括号进行匹配
            Pop_SeqStack(s);
        }
        ++p;
    }
    //栈里是否还有多的左括号
    if (GetSize_SeqStack(s)!=0)
    {
        printf("Failure!");
        return;
    }
    printf("Success!");
}

int main()
{
    test();
}