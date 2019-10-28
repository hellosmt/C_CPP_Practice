/*
 * @Author: Cement
 * @Date: 2019-10-27 20:56:03
 * @LastEditors: Cement
 * @LastEditTime: 2019-10-28 20:21:50
 * @Description: 栈的函数实现
 */

#include "SeqStack.h"

//栈结构体
struct SStack
{
    void *data[MAX];
    int size;
};

//初始化栈
SeqStack Init_SeqStack()
{
    struct SStack *stack = (struct SStack *)malloc(sizeof(struct SStack));
    if (NULL == stack)
    {
        return NULL;
    }
    memset(stack, 0, sizeof(struct SStack));
    // stack->size = 0;
    // for (int i = 0; i < MAX; i++)
    // {
    //     stack->data[i] =NULL;
    // }
    
    return stack;
}

//假定数组末尾为栈顶，因此在入栈和出栈操作时不用移动元素
//入栈
void Push_SeqStack(SeqStack stack, void *data)
{
    if (NULL == stack || NULL == data)
    {
        return;
    }
    struct SStack *myStack = (struct SStack *)stack;
    //栈满
    if (myStack->size == MAX)
    {
        //printf("Failure! The stack is full!\n");
        return;
    }
    //入栈
    myStack->data[myStack->size] = data;
    ++myStack->size;
}

//出栈
void Pop_SeqStack(SeqStack stack)
{
    if (NULL == stack)
    {
        return;
    }
    struct SStack *myStack = (struct SStack *)stack;
    if (myStack->size == 0)
    {
        //printf("Failure! The stack is empty!\n");
        return;
    }
    //出栈
    myStack->data[myStack->size-1] = NULL;
    --myStack->size;
}

//获得栈顶元素
void *Top_SeqStack(SeqStack stack)
{
    if (NULL == stack)
    {
        return NULL;
    }
    struct SStack *myStack = (struct SStack *)stack;
    if (myStack->size == 0)
    {
        //printf("Failure! The stack is empty!\n");
        return NULL;
    }
    //返回栈顶元素
    return myStack->data[myStack->size-1];
}

//获得栈的大小
int GetSize_SeqStack(SeqStack stack)
{
    if (NULL == stack)
    {
        return -1;
    }
    struct SStack *myStack = (struct SStack *)stack;
    return myStack->size;
}

//销毁栈
void Destroy_SeqStack(SeqStack stack)
{
    if (NULL == stack)
    {
        return;
    }
    free(stack);
    stack = NULL;
}