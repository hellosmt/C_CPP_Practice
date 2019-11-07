/*
 * @Author: Cement
 * @Date: 2019-11-07 18:29:54
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-07 19:41:07
 * @Description: 类模板的应用-数组类封装
 */
#pragma once

#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class MyArray
{
private:
    T *pArray;
    int m_size;     //数组大小
    int m_capacity; //数组容量
public:
    explicit MyArray(int capacity); //有参构造函数 explicit防止隐式类型转换 防止MyArray arr = 10;这样调用
    MyArray(const MyArray &arr);    //拷贝构造函数
    ~MyArray();                     //析构函数

    //重载[]
    T &operator[](int index);

    //重载=
    MyArray &operator=(const MyArray &arr);

    //获取大小
    int getSize()
    {
        return this->m_size;
    }

    //获取容量
    int getCapacity()
    {
        return this->m_capacity;
    }

    //尾插
    void push_back(T data);
};

//有参构造函数
template <typename T>
MyArray<T>::MyArray(int capacity)
{
    this->m_size = 0;
    this->m_capacity = capacity;
    this->pArray = new T[capacity];
}

//拷贝构造函数
template <typename T>
MyArray<T>::MyArray(const MyArray &arr)
{
    this->m_size = arr.m_size;
    this->m_capacity = arr.m_capacity;
    this->pArray = new T[this->m_capacity];
    //拷贝数据
    for (int i = 0; i < this->m_size; ++i)
    {
        this->pArray[i] = arr.pArray[i];
    }
}

//析构函数
template <typename T>
MyArray<T>::~MyArray()
{
    if (this->pArray != NULL)
    {
        delete[] this->pArray;
        this->pArray = NULL;
    }
    this->m_capacity = 0;
    this->m_size = 0;
}

//重载[]
template <typename T>
T &MyArray<T>::operator[](int index)
{
    return this->pArray[index];
}

//重载=
template <typename T>
MyArray<T> &MyArray<T>::operator=(const MyArray &arr)
{
    //先判断原始数据是否为空
    if (this->pArray != NULL)
    {
        delete[] this->pArray;
        pArray = NULL;
    }
    this->m_size = arr.m_size;
    this->m_capacity = arr.m_capacity;
    this->pArray = new T[this->m_capacity];
    //拷贝数据
    for (int i = 0; i < this->m_size; ++i)
    {
        this->pArray[i] = arr[i];
    }
}

//尾插
template <typename T>
void MyArray<T>::push_back(T data)
{
    //数组已经满了需要重新申请更大的空间
    if (this->m_size == this->m_capacity)
    {
        //新空间容量为原先的两倍
        int new_capacity = this->m_capacity * 2;
        T *temp = new T[new_capacity];
        memset(temp, 0, sizeof(T) * new_capacity);
        //拷贝数据知道新空间
        for (int i = 0; i < this->m_size; ++i)
        {
            temp[i] = this->pArray[i];
        }
        //释放原先的空间
        delete[] this->pArray;
        //指向新空间
        this->pArray = temp;
        this->m_capacity = new_capacity;
    }
    //插入新数据
    this->pArray[this->m_size] = data;
    //size+1
    ++this->m_size;
}
