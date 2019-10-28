/*
 * @Author: Cement
 * @Date: 2019-10-28 08:39:43
 * @LastEditors: Cement
 * @LastEditTime: 2019-10-28 08:53:09
 * @Description: 链式栈测试
 */

#include"LinkStack.h"

struct Person
{
    struct StackNode node;
    char name[64];
    int age;
};

void test()
{
    LinkStack s = Init_LinkStack();
    struct Person p1 = {NULL, "aaa", 20};
    struct Person p2 = {NULL, "bbb", 18};
    struct Person p3 = {NULL, "ccc", 25};
    struct Person p4 = {NULL, "ddd", 30};
    struct Person p5 = {NULL, "eee", 90};
    struct Person p6 = {NULL, "fff", 80};

    //入栈
    Push_LinkStack(s, &p1);
    Push_LinkStack(s, &p2);
    Push_LinkStack(s, &p3);
    Push_LinkStack(s, &p4);
    Push_LinkStack(s, &p5);
    Push_LinkStack(s, &p6);
    
    //获得栈顶元素，打印并pop出
    while (GetSize_LinkStack(s)!=0)
    {
        struct Person* p = (struct Person*)Top_LinkStack(s);
        printf("%s:%d\n", p->name, p->age);
        Pop_LinkStack(s);
    }
    
    //销毁
    Destroy_LinkStack(s);
}

int main()
{
    test();
}