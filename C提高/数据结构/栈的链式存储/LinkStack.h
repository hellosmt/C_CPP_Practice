/*
 * @Author: Cement
 * @Date: 2019-10-28 08:01:17
 * @LastEditors: Cement
 * @LastEditTime: 2019-10-28 08:11:12
 * @Description: 栈的链式存储头文件
 */
#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#ifdef __cplusplus
extern "C"{
#endif

    struct StackNode
    {
        struct StackNode* next;
    };

    struct LStack
    {
        struct StackNode header;
        int size;
    };

    typedef void* LinkStack;

    //初始化栈
    LinkStack Init_LinkStack();

    //假定头结点后为栈顶，因此在入栈和出栈操作时不用遍历节点
    //入栈
    void Push_LinkStack(LinkStack stack, void* data);

    //出栈
    void Pop_LinkStack(LinkStack stack);

    //获得栈顶元素
    void* Top_LinkStack(LinkStack stack);

    //获得栈的大小
    int GetSize_LinkStack(LinkStack stack);

    //销毁栈
    void Destroy_LinkStack(LinkStack stack);
    
    
    
#ifdef __cplusplus
}
#endif