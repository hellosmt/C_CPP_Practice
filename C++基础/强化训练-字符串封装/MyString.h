/*
 * @Author: sunmengtuo
 * @Date: 2019-11-04 19:52:58
 * @LastEditTime: 2019-11-05 17:09:45
 * @LastEditors: Cement
 * @Description: In User Settings Edit
 * @FilePath: \C_CPP\C++基础\强化训练-字符串封装\MyString.h
 */
#pragma once

#include<iostream>
#include<cstring>
using namespace std;

class MyString
{
    friend ostream& operator<<(ostream& cout, MyString& data);
public:
    MyString(const char* data);

    //拷贝构造函数
    MyString(const MyString& data);

    //析构函数
    ~MyString();

    //重载=
    void operator=(const char* data);
    void operator=(MyString& data);

    //重载==
    bool operator==(const char* data);
    bool operator==(MyString& data);

    //重载[]
    char operator[](int index);

    //重载+
    MyString& operator+(const char* data);
    MyString& operator+(MyString& data);

    

private:
    char *str; //指向堆区的指针
    int m_size; //字符串大小
};