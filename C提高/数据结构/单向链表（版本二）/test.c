/*
 * @Author: Cement
 * @Date: 2019-10-26 15:21:41
 * @LastEditors: Cement
 * @LastEditTime: 2019-10-27 09:24:26
 * @Description: 
 */

#include "LinkList.h"

//用户自己的数据结构体
struct Person
{
    struct LinkNode node;
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
    struct Person p1 = {NULL, "aaa", 20};
    struct Person p2 = {NULL, "bbb", 18};
    struct Person p3 = {NULL, "ccc", 25};
    struct Person p4 = {NULL, "ddd", 30};
    struct Person p5 = {NULL, "eee", 90};
    struct Person p6 = {NULL, "fff", 80};
    //插入
    Insert_LinkList(L, 0, &p1);
    Insert_LinkList(L, 0, &p2);
    Insert_LinkList(L, 0, &p3);
    Insert_LinkList(L, 0, &p4);
    Insert_LinkList(L, 3, &p5);
    Insert_LinkList(L, 9, &p6);
    //  遍历打印
    Foreach_LinkList(L, myPrint);
    printf("========================\n");
    //删除
    RemoveByPos_LinkList(L, 2);
    Foreach_LinkList(L, myPrint);
    printf("========================\n");

    //struct Person pRemove = {NULL, "ddd", 30};
    //RemoveByValue_LinkList(L, &pRemove, myCompare);
    //Foreach_LinkList(L, myPrint);
    printf("========================\n");

    //销毁链表
    Destory_LinkList(L);
}

int main()
{
    test();
}
