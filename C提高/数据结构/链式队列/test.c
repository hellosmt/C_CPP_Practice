/*
 * @Author: Cement
 * @Date: 2019-10-28 23:19:38
 * @LastEditors: Cement
 * @LastEditTime: 2019-10-28 23:36:34
 * @Description: 链式队列测试
 */
#include "LinkQueue.h"

struct Person
{
    struct QueueNode node;
    char name[64];
    int age;
};

void test()
{
    LinkQueue q = Init_LinkQueue();
    struct Person p1 = {NULL, "aaa", 20};
    struct Person p2 = {NULL, "bbb", 18};
    struct Person p3 = {NULL, "ccc", 25};
    struct Person p4 = {NULL, "ddd", 30};
    struct Person p5 = {NULL, "eee", 90};
    struct Person p6 = {NULL, "fff", 80};

    //入队列
    Push_LinkQueue(q, &p1);
    Push_LinkQueue(q, &p2);
    Push_LinkQueue(q, &p3);
    Push_LinkQueue(q, &p4);
    Push_LinkQueue(q, &p5);
    Push_LinkQueue(q, &p6);

    //出队列
    while (GetSize_LinkQueue(q) != 0)
    {
        struct Person *p = (struct Person *)Front_LinkQueue(q);
        printf("head:%s:%d\n", p->name, p->age);

        p = (struct Person *)Rear_LinkQueue(q);
        printf("rear:%s:%d\n", p->name, p->age);

        printf("================\n");
        Pop_LinkQueue(q);
    }

    //销毁
    Destroy_LinkQueue(q);
}

int main()
{
    test();
}