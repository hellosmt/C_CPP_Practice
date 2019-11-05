/*
 * @Author: your name
 * @Date: 2019-11-04 19:52:58
 * @LastEditTime: 2019-11-05 17:34:59
 * @LastEditors: Cement
 * @Description: In User Settings Edit
 * @FilePath: \C_CPP\C++基础\强化训练-字符串封装\MyString.cpp
 */

#include "MyString.h"

//重载<<
ostream &operator<<(ostream &cout, MyString &data)
{
    cout << data.str;
    return cout;
}

MyString::MyString(const char *data)
{
    this->str = new char[strlen(data) + 1];
    strcpy(this->str, data);
    this->m_size = strlen(data);
}



//拷贝构造函数
MyString::MyString(const MyString &data)
{
    this->str = new char[strlen(data.str) + 1]; //虽然str是private，但可以直接访问？
    strcpy(this->str, data.str);
    this->m_size = strlen(data.str);
}


//析构函数
MyString::~MyString()
{
    if (this->str!=NULL)
    {
        delete[] this->str;
        this->str  = NULL;
    }
    
}

//重载=
void MyString::operator=(const char *data)
{
    //如果我原先是有数据的，在重新赋值之前不释放原先的空间会导致内存泄漏
    if (this->str != NULL)
    {
        delete[] str;
        this->str = NULL;
    }
    //申请新空间
    this->str = new char[strlen(data) + 1];
    strcpy(this->str, data);
    this->m_size = strlen(data);
}

void MyString::operator=(MyString &data)
{
    if (this->str != NULL)
    {
        delete[] str;
        this->str = NULL;
    }
    this->str = new char[data.m_size + 1];
    strcpy(this->str, data.str);
    this->m_size = data.m_size;
}

//重载==
bool MyString::operator==(const char *data)
{
    if (strcmp(this->str, data) == 0)
    {
        return true;
    }
    return false;
}

bool MyString::operator==(MyString &data)
{
    if (strcmp(this->str, data.str) == 0)
    {
        return true;
    }
    return false;
}

//重载[]
char MyString::operator[](int index)
{
    return this->str[index];
}

//重载+
MyString &MyString::operator+(const char *data)
{
    int newSize = this->m_size + strlen(data) + 1;
    
    char* tmp = new char[newSize];

    memset(tmp, 0, newSize);

    //字符串拼接
    strcat(tmp,this->str);
    strcat(tmp, data);

    MyString* s = new MyString(tmp);
    delete[] tmp;
    return *s;
}

MyString &MyString::operator+(MyString &data)
{
    int newSize = this->m_size + data.m_size + 1;
    
    char* tmp = new char[newSize];

    memset(tmp, 0, newSize);

    //字符串拼接
    strcat(tmp,this->str);
    strcat(tmp, data.str);

    MyString* s = new MyString(tmp);
    delete[] tmp;
    return *s;
}

