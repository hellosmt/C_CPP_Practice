/*
 * @Author: Cement
 * @Date: 2019-10-28 22:30:45
 * @LastEditors: Cement
 * @LastEditTime: 2019-10-28 23:22:26
 * @Description: 链式队列头文件
 */
# pragma once 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#ifdef __cplusplus
extern "C"{
#endif
    struct QueueNode
    {
        struct QueueNode *next;
    };
    
    typedef void* LinkQueue;
    
    //初始化
    LinkQueue Init_LinkQueue();

    //入队列
    void Push_LinkQueue(LinkQueue queue, void* data);

    //出队列
    void Pop_LinkQueue(LinkQueue queue);

    //获得队头元素
    void* Front_LinkQueue(LinkQueue queue);

    //获得队尾元素
    void* Rear_LinkQueue(LinkQueue queue);

    //获得队列的大小
    int GetSize_LinkQueue(LinkQueue queue);

    //销毁队列
    void Destroy_LinkQueue(LinkQueue queue);

#ifdef __cplusplus
}
#endif
