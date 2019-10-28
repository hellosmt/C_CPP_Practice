/*
 * @Author: sunmengtuo
 * @Date: 2019-10-26 09:09:55
 * @LastEditTime: 2019-10-27 09:08:53
 * @LastEditors: Cement
 * @Description: In User Settings Edit
 * @FilePath: \C\C_CPP\LinkList\LinkList.c
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkList.h"

//结构体定义放在.c文件中，而不放在.h文件中，防止用户无意中直接操作了结构体数据，因为头文件用户是可以看到具体内容的，他知道了结构体是什么样的就可以自已直接更改而不是用我们提供的接口去操作，没有达到封装的目的，而.c文件编译后才给用户，二进制码，用户看不懂
struct ListNode
{
    void *data;            //数据域
    struct ListNode *next; //指针域
};

//链表信息结构体
struct LList
{
    struct ListNode header; //头结点，为什么不用指针,因为我给LList结构体分配内存空间时就给这个header分配了空间，用*也可以，就要再多一步给他进行分配
    int size;
};

//初始化
LinkList Init_LinkList()
{
    struct LList *L = (struct LList *)malloc(sizeof(struct LList));
    if (NULL == L)
    {
        return NULL;
    }
    L->header.data = NULL;
    L->header.next = NULL;
    L->size = 0;
    return L;
}

//指定pos插入节点
void Insert_LinkList(LinkList L, int pos, void *data)
{
    if (NULL == L || pos < 0 || NULL == data)
    {
        return;
    }
    struct LList *List = (struct LList *)L;
    if (pos > List->size)
    {
        pos = List->size;
    }

    //新建节点
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->data = data;
    node->next = NULL;

    //设置pCurrent
    struct ListNode *pCurrent = &(List->header);
    for (int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }
    //插入新节点
    node->next = pCurrent->next;
    pCurrent->next = node;

    //长度+1
    List->size++;
}

//指定pos删除节点
void RemoveByPos_LinkList(LinkList L, int pos)
{
    if (NULL == L)
    {
        return;
    }
    struct LList *List = (struct LList *)L;
    if (pos < 0 || pos > List->size-1)
    {
        return;
    }
    struct ListNode *pCurrent = &(List->header);
    //找到要删除节点的前一个节点为当前节点
    for (int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }
    //记录下要删除的那个节点
    struct ListNode *pPos = pCurrent->next;
    //当前节点的next指向下一个的next
    pCurrent->next = pPos->next;

    //释放要删除节点的空间
    free(pPos);
    pPos = NULL;
    List->size--;
}

//指定值删除节点,判断两个节点是否相同需要用户自己写比较函数，我们是不知道用户在链表里具体放的是什么类型数据，int float 还是结构体
void RemoveByValue_LinkList(LinkList L, void *data, COMPARE myCmp)
{
    if (NULL == L || NULL == data || NULL == myCmp)
    {
        return;
    }
    struct LList *List = (struct LList *)L;
    //记录前一个节点
    struct ListNode *pPrev = &(List->header);
    //记录当前节点
    struct ListNode *pCurrent = (&(List->header))->next;
    while (pCurrent != NULL)
    {
        if (myCmp(pCurrent->data, data))
        {
            pPrev->next = pCurrent->next;
            free(pCurrent);
            pCurrent = NULL;
            List->size--;
            break;
        }
        pPrev = pPrev->next;
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
    struct ListNode *pCurrent = (&(List->header))->next;
    while (pCurrent != NULL)
    {
        myForeach(pCurrent->data);
        pCurrent = pCurrent->next;
    }
}

//清空链表
void Clear_LinkList(LinkList L)
{
    if (NULL == L)
    {
        return;
    }
    struct LList *List = (struct LList *)L;
    struct ListNode *pCurrent = (&(List->header))->next;
    while (pCurrent != NULL)
    {
        //先记录下一个节点的地址
        struct ListNode *pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    }
    List->size = 0;
    List->header.next = NULL;
}

//销毁链表
void Destory_LinkList(LinkList L)
{
    if (L == NULL)
    {
        return;
    }
    Clear_LinkList(L);
    free(L);
    L = NULL;
}
