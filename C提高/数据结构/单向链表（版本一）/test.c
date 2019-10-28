/*
 * @Author: sunmengtuo
 * @Date: 2019-10-26 09:10:00
 * @LastEditTime: 2019-10-26 15:15:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C\C_CPP\LinkList\test.c
 */
#include"LinkList.h"

//我们要存的数据
struct Person
{
    char name[64];
    int age;
};

//适合Person结构体的打印函数
void myPrint(void *data)
{
    struct Person *p = (struct Person *)data;
    printf("%s:%d\n", p->name, p->age);
}

//适合Person结构体的比较函数
int myCompare(void *data1, void *data2)
{
    struct Person *p1 = (struct Person *)data1;
    struct Person *p2 = (struct Person *)data2;
    return strcmp(p1->name, p1->name) == 0 && p1->age == p2->age;
}

void test()
{
    //初始化链表
    LinkList L = Init_LinkList();
    struct Person p1 = {"aaa", 20};
    struct Person p2 = {"bbb", 18};
    struct Person p3 = {"ccc", 25};
    struct Person p4 = {"ddd", 30};
    struct Person p5 = {"eee", 90};
    struct Person p6 = {"fff", 80};
    //插入
    Insert_LinkList(L, 0, &p1);
    Insert_LinkList(L, 0, &p2);
    Insert_LinkList(L, 0, &p3);
    Insert_LinkList(L, 0, &p4);
    Insert_LinkList(L, 3, &p5);
    Insert_LinkList(L, 9, &p6);
    //  遍历打印
    Foreach_LinkList(L,myPrint);
    printf("========================\n");
    //删除
    RemoveByPos_LinkList(L, 2);
    Foreach_LinkList(L,myPrint);
    printf("========================\n");

    struct Person pRemove = {"ddd", 30};
    RemoveByValue_LinkList(L,&pRemove,myCompare);
    Foreach_LinkList(L,myPrint);
    printf("========================\n");

    //清空链表
    Clear_LinkList(L);
    Foreach_LinkList(L,myPrint);
    
    //销毁链表
    Destory_LinkList(L);
    
}

int main()
{
    test();
}