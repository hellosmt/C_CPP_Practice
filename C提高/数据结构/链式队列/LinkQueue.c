/*
 * @Author: Cement
 * @Date: 2019-10-28 22:45:25
 * @LastEditors: Cement
 * @LastEditTime: 2019-10-28 23:29:51
 * @Description: 链式队列函数实现，设定链表头为队列头，链表尾为队列尾
 */

#include "LinkQueue.h"



struct LQueue
{
    struct QueueNode header;
    struct QueueNode *rear; //始终指向队列的尾部，这样插入元素时不用遍历
    int size;
};

//初始化
LinkQueue Init_LinkQueue()
{
    struct LQueue *q = (struct LQueue *)malloc(sizeof(struct LQueue));
    if (NULL == q)
    {
        return NULL;
    }
    q->header.next = NULL;
    q->rear = &(q->header);
    q->size = 0;
    return q;
}

//入队列
void Push_LinkQueue(LinkQueue queue, void *data)
{
    if (queue == NULL || data == NULL)
    {
        return;
    }
    struct LQueue *q = (struct LQueue *)queue;
    struct QueueNode *node = (struct QueueNode *)data;
    //在队列尾部放入节点
    q->rear->next = data;
    node->next = NULL;
    //更新尾指针
    q->rear = node;
    ++q->size;
}

//出队列
void Pop_LinkQueue(LinkQueue queue)
{
    if (queue == NULL)
    {
        return;
    }
    struct LQueue *q = (struct LQueue *)queue;
    if (q->size == 0)
    {
        return;
    }

    struct QueueNode *pDel = q->header.next;
    //队头节点出队列
    q->header.next = pDel->next;
    pDel->next = NULL;

    --q->size;
    //还要考虑只有一个节点时，因为删除队头后要更新尾指针使其指向头结点
    if (q->size == 0)
    {
        q->rear = &(q->header);
    }
}

//获得队头元素
void *Front_LinkQueue(LinkQueue queue)
{
    if (queue == NULL)
    {
        return NULL;
    }
    struct LQueue *q = (struct LQueue *)queue;
    if (q->size == 0)
    {
        return NULL;
    }

    return q->header.next;
}

//获得队尾元素
void *Rear_LinkQueue(LinkQueue queue)
{
    if (queue == NULL)
    {
        return NULL;
    }
    struct LQueue *q = (struct LQueue *)queue;
    if (q->size == 0)
    {
        return NULL;
    }

    return q->rear;
}

//获得队列的大小
int GetSize_LinkQueue(LinkQueue queue)
{
    if (queue == NULL)
    {
        return -1;
    }
    struct LQueue *q = (struct LQueue *)queue;
    return q->size;
}

//销毁队列
void Destroy_LinkQueue(LinkQueue queue)
{
    if (queue == NULL)
    {
        return;
    }
    free(queue);
    queue = NULL;
}