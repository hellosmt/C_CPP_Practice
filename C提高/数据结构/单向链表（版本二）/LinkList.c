/*
 * @Author: Cement
 * @Date: 2019-10-27 07:54:04
 * @LastEditors: Cement
 * @LastEditTime: 2019-10-27 09:19:38
 * @Description: 思路一是节点中存放一个指向用户数据的一个指针，然后将节点串联起来形成用户数据的链式存储，这样每插入一个或者删除一个都要malloc或者是free。思路二是和用户约定它的数据结构体中空出一个struct node的空间存放我们定义的LinkNode，该Node中的next节点指向下一个用户数据，将node和用户数据绑定在一起
 */

#include "LinkList.h"
//有个缺点，不能插入重复数据（地址相同的数据，否则next指向哪个？）



//初始化
LinkList Init_LinkList()
{
    struct LList *L = (struct LList *)malloc(sizeof(struct LList));
    if (NULL == L)
    {
        return NULL;
    }

    L->header.next = NULL;
    L->size = 0;
    return L;
}

//指定pos插入节点
void Insert_LinkList(LinkList L, int pos, void *data)
{
    if (NULL == L || NULL == data)
    {
        return;
    }
    //将L转成链表指针类型
    struct LList *myList = (struct LList *)L;
    if (pos > myList->size || pos < 0)
    {
        pos = myList->size;
    }
    //设置辅助指针变量
    struct LinkNode *pCurrent = &(myList->header);
    //插入节点
    for (int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }
    ((struct LinkNode *)data)->next = pCurrent->next;
    pCurrent->next = data;
    ++myList->size;
}

//指定pos删除节点
void RemoveByPos_LinkList(LinkList L, int pos)
{
    if (NULL == L)
    {
        return;
    }
    struct LList *myList = (struct LList *)L;
    if (pos < 0 || pos > myList->size-1)
    {
        return;
    }
    //设置辅助指针变量
    struct LinkNode *pCurrent = &(myList->header);
    //删除节点
    for (int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }
    //不需要记录要删除的节点，因为插入的时候没有malloc，所以在删除时不用free，是对应的
    //struct LinkNode *pRemove = pCurrent->next;
    pCurrent->next = pCurrent->next->next;
    //free(pRemove);
    //pRemove = NULL;
    --myList->size;
}

//指定值删除节点,判断两个节点是否相同需要用户自己写比较函数，我们是不知道用户在链表里具体放的是什么类型数据，int float 还是结构体
void RemoveByValue_LinkList(LinkList L, void *data, COMPARE myCmp)
{
    if (NULL == L || NULL == data || NULL == myCmp)
    {
        return;
    }
    struct LList *myList = (struct LList *)L;
    //前一个节点
    struct LinkNode *pPrev = &(myList->header);
    //当前节点
    struct LinkNode *pCurrent = (&(myList->header))->next;

    while (pCurrent != NULL)
    {
        if (myCmp(pCurrent, data))
        {
            pPrev->next = pCurrent->next;
            --myList->size;
            break;
        }
        pPrev = pCurrent;
        pCurrent = pCurrent->next;
    }
}

//遍历,只遍历，把每个节点交给用户，用户要怎么操作自己写回调函数
void Foreach_LinkList(LinkList L, FOREACH myForeach)
{
    if (NULL == L || NULL == myForeach)
    {
        return;
    }
    struct LList *List = (struct LList *)L;
    struct LinkNode *pCurrent = (&(List->header))->next;
    while (pCurrent != NULL)
    {
        myForeach(pCurrent);
        pCurrent = pCurrent->next;
    }
}

//销毁链表，不需要释放用户数据内存，因为那些内存不是我开的
//如果用户希望在销毁链表时也帮他们把数据内存给销毁掉，可以设置一个flag参数
//原则上是你开辟的内存你管，我开辟的内存我管，如果有特殊需求也可以开发满足要求的接口
void Destory_LinkList(LinkList L)
{
    if (NULL == L)
    {
        return;
    }
    free(L);
    L = NULL;
}