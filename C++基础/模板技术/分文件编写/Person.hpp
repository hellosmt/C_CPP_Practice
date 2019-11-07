/*
 * @Author: Cement
 * @Date: 2019-11-07 08:46:02
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-07 14:01:32
 * @Description: 模板类敲一敲
 */

#include <iostream>

using namespace std;

template <class NameType, class AgeType>
class Person
{
private:
    NameType m_name;
    AgeType m_age;

public:
    Person(NameType name, AgeType age);

    void showPerson();
};

//模板类分文件进行编写，类声明和成员函数实现卸载一个文件里，并将后缀名改为.hpp
//类外实现成员函数
template <class NameType, class AgeType>
Person<NameType, AgeType>::Person(NameType name, AgeType age)
{
    this->m_name = name;
    this->m_age = age;
}

template <class NameType, class AgeType>
void Person<NameType, AgeType>::showPerson()
{
    cout << this->m_name << ":" << this->m_age << endl;
}
