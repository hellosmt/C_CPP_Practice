/*
 * @Author: your name
 * @Date: 2019-11-04 19:52:58
 * @LastEditTime: 2019-11-04 23:59:43
 * @LastEditors: Cement
 * @Description: In User Settings Edit
 * @FilePath: \C_CPP\C++基础\强化训练-字符串封装\MyString.cpp
 */

#include"MyString.h"

//重载<<
ostream& operator<<(ostream& cout, MyString& str)
{
    cout<<str.getString();
    return cout;
}

MyString::MyString(const char* data)
{
    this->str = new char[strlen(data)+1];
    strcpy(this->str, data);
    this->m_size = strlen(data);
}

//拷贝构造函数
MyString::MyString(const MyString& data)
{
    this->str = new char[strlen(data.str)+1];
    strcpy(this->str, data.str);
    this->m_size = strlen(data.str);
}
//重载=
void MyString:: operator=(const char* data)
{
    if (this->str!=NULL)
    {
        delete[] str;
        this->str = NULL;
    }
    this->str = new char[strlen(data)+1];
    strcpy(this->str, data);
    this->m_size = strlen(data);
}

//获得数据
char* MyString:: getString()
{
    return this->str;
}

//获得长度
char* MyString:: getString()
{
    return this->str;
}
