/*
 * @Author: Cement
 * @Date: 2019-10-28 08:09:29
 * @LastEditors: Cement
 * @LastEditTime: 2019-10-28 08:56:33
 * @Description: 链式栈函数实现,采用思路二，在用户数据结构体中包含StackNode成员
 */

#include "LinkStack.h"

//初始化栈
LinkStack Init_LinkStack()
{
    struct LStack *stack = (struct LStack *)malloc(sizeof(struct LStack));
    if (NULL == stack)
    {
        return NULL;
    }
    stack->header.next = NULL;
    stack->size = 0;
    return stack;
}

//假定第一个节点为栈顶，因此在入栈和出栈操作时不用遍历节点
//入栈
void Push_LinkStack(LinkStack stack, void *data)
{
    if (NULL == stack || NULL == data)
    {
        return;
    }
    struct LStack *myStack = (struct LStack *)stack;
    struct StackNode *node = (struct StackNode *)data;
    //将节点放在栈顶
    node->next = myStack->header.next;
    myStack->header.next = node;
    ++myStack->size;
}

//出栈
void Pop_LinkStack(LinkStack stack)
{
    if (NULL == stack)
    {
        return;
    }
    struct LStack *myStack = (struct LStack *)stack;
    if (myStack->size == 0)
    {
        printf("Failure! The stack is empty!\n");
        return;
    }
    myStack->header.next = myStack->header.next->next;
    --myStack->size;
}

//获得栈顶元素
void *Top_LinkStack(LinkStack stack)
{
    if (NULL == stack)
    {
        return NULL;
    }
    struct LStack *myStack = (struct LStack *)stack;
    if (myStack->size == 0)
    {
        printf("Failure! The stack is empty!\n");
        return NULL;
    }
    return myStack->header.next;
}

//获得栈的大小
int GetSize_LinkStack(LinkStack stack)
{
    if (NULL == stack)
    {
        return -1;
    }
    struct LStack *myStack = (struct LStack *)stack;
    return myStack->size;
}

//销毁栈
void Destroy_LinkStack(LinkStack stack)
{
    if (NULL == stack)
    {
        return;
    }
    free(stack);
    stack = NULL;
}