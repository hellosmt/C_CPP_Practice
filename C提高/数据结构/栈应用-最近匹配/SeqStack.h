/*
 * @Author: Cement
 * @Date: 2019-10-27 10:41:38
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2019-10-28 11:08:33
 * @Description: 使用静态数组实现栈
 */

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 100



#ifdef __cplusplus
extern "C"{
#endif
    

    typedef void* SeqStack;

    //初始化栈
    SeqStack Init_SeqStack();

    //假定数组末尾为栈顶，因此在入栈和出栈操作时不用移动元素
    //入栈
    void Push_SeqStack(SeqStack stack, void* data);

    //出栈
    void Pop_SeqStack(SeqStack stack);

    //获得栈顶元素
    void* Top_SeqStack(SeqStack stack);

    //获得栈的大小
    int GetSize_SeqStack(SeqStack stack);

    //销毁栈
    void Destroy_SeqStack(SeqStack stack);
    

#ifdef __cplusplus
}
#endif