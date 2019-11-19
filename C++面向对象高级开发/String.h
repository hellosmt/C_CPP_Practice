/*
 * @Author: Cement
 * @Date: 2019-11-18 10:21:01
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-18 20:24:28
 * @Description:跟着侯捷老师的C++面向对象高级开发课程自己实现String类
 */

#ifndef __STRING__
#define __STRING__

#include <iostream>
#include <cstring>

class String
{
private:
    char *str;

public:
    //带默认参数的构造函数
    String(const char *s = 0);

    //拷贝构造函数
    String(const String &s);

    //拷贝赋值
    String &operator=(const String &s);

    //获取字符串
    char* get_str () const
    {
        return this->str;
    }

    //析构函数
    ~String();
};

//带默认参数的构造函数
//声明写了默认值，实现这里不要写
inline String::String(const char *s )
{
    if (s)
    {
        this->str = new char[strlen(s) + 1];
        strcpy(this->str, s);
    }
    else
    {
        this->str = new char[1];
        *this->str = '0';
    }
}

//拷贝构造函数
inline String::String(const String &s)
{
    this->str = new char[strlen(s.str) + 1];
    strcpy(this->str, s.str);
}

//拷贝赋值
inline String &String::operator=(const String &s)
{
    //判断是否为自我赋值，如果不进行判断，客户真的进行了自我赋值，即两个指针指向同一块区域，则下面第一句就会将这块内容给delete掉，后面就会出错
    if (this == &s)
    {
        return *this;
    }

    if (this->str)
    {
        delete[] this->str;
        this->str = NULL;
    }
    this->str = new char[strlen(s.str) + 1];
    strcpy(this->str, s.str);
    return *this;
}

//析构函数
inline String::~String()
{
    if (this->str)
    {
        delete[] this->str;
        this->str = NULL;
    }
}

#endif
