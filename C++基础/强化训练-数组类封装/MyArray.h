/*
 * @Author: Cement
 * @Date: 2019-11-02 21:57:33
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-02 22:34:40
 * @Description: 
 */
#pragma once

#include<iostream>

class MyArray
{
public:
    //默认构造函数 容量默认100
    MyArray();
    //有参构造函数
    MyArray(int capacity);
    //拷贝构造函数
    MyArray(const MyArray& arr);
    //析构函数
    ~MyArray();

    //尾插法
    void push_back(int data);
    //根据索引获取值
    int get_data(int index);
    //根据索引设置值
    void set_data(int  index, int data);
    //获取大小
    int get_size();

private:
    int* pAddress; //指向真正存储数据的指针
    int m_size;  //数组大小
    int m_capacity; //数组容量
    
};