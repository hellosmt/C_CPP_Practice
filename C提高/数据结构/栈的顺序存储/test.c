/*
 * @Author: Cement
 * @Date: 2019-10-27 21:16:38
 * @LastEditors: Cement
 * @LastEditTime: 2019-10-27 23:08:26
 * @Description: 
 */

#include"SeqStack.h"

struct Person
{
    char name[64];
    int age;
};

void test()
{
    SeqStack s = Init_SeqStack();
    struct Person p1 = {"aaa", 20};
    struct Person p2 = {"bbb", 18};
    struct Person p3 = {"ccc", 25};
    struct Person p4 = {"ddd", 30};
    struct Person p5 = {"eee", 90};
    struct Person p6 = {"fff", 80};
    Push_SeqStack(s, &p1);
    Push_SeqStack(s, &p2);
    Push_SeqStack(s, &p3);
    Push_SeqStack(s, &p4);
    Push_SeqStack(s, &p5);
    Push_SeqStack(s, &p6);

    while (GetSize_SeqStack(s)>0)
    {
        struct Person* p =  Top_SeqStack(s);
        printf("%s:%d\n", p->name, p->age);
        Pop_SeqStack(s);
    }

    Destroy_SeqStack(s);
}

int main()
{
    test();
}