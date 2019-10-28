/*
 * @Author: sunmengtuo
 * @Date: 2019-10-26 09:09:47
 * @LastEditTime: 2019-10-26 11:28:15
 * @LastEditors: Please set LastEditors
 * @Description:
 * @FilePath: \C\C_CPP\LinkList\LinkList.h
 */

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif
    //将链表类型定义成void*，不让用户直接接触到结构体，封装，防止用户无意直接修改了结构体内容
    //LinkList结构体类似链表的
    typedef void* LinkList;
    typedef void(*FOREACH)(void*);
    typedef int(*COMPARE)(void*, void*);
    //初始化
    LinkList Init_LinkList();
    //指定pos插入节点
    void Insert_LinkList(LinkList L, int pos, void* data);
    //指定pos删除节点
    void RemoveByPos_LinkList(LinkList L, int pos);
    //指定值删除节点,判断两个节点是否相同需要用户自己写比较函数，我们是不知道用户在链表里具体放的是什么类型数据，int float 还是结构体
    void RemoveByValue_LinkList(LinkList L, void* data, COMPARE myCmp);
    //遍历,只遍历，把每个节点交给用户，用户要怎么操作自己写回调函数
    void Foreach_LinkList(LinkList L, FOREACH myForeach);
    //清空链表
    void Clear_LinkList(LinkList L);
    //销毁链表
    void Destory_LinkList(LinkList L);
    

#ifdef __cplusplus
}
#endif