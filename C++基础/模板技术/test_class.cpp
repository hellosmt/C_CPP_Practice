/*
 * @Author: Cement
 * @Date: 2019-11-07 08:46:02
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-07 13:36:44
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
    Person(NameType name, AgeType age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    
    //类外实现
    void showPerson();
    
};

//类外实现成员函数
template<class NameType , class AgeType>
void Person<NameType, AgeType>::showPerson()
{
    cout << this->m_name << ":" << this->m_age << endl;
}

//类模板作为函数的参数
//1.指定传入的参数类型
void doWork1(Person<string, int> &p)
{
    cout << "==========doWork1==========" << endl;
    p.showPerson();
}

//2.参数模板化
template <class T1, class T2>
void doWork2(Person<T1, T2> &p)
{
    cout << "==========doWork2==========" << endl;
    p.showPerson();
}

//3.整体类型化
template <class T>
void doWork3(T &p)
{
    cout << "==========doWork3==========" << endl;
    cout << typeid(T).name() << endl; //打印T的类型
    p.showPerson();
}

void test()
{
    //只能支持显式类型推导
    Person<string, int> p = Person<string, int>("Linux", 20);
    p.showPerson();
    doWork1(p);
    doWork2(p);
    doWork3(p);
}

int main()
{
    test();
}
