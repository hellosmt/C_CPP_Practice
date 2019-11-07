/*
 * @Author: Cement
 * @Date: 2019-11-07 14:03:14
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-07 14:23:27
 * @Description: 友元函数碰到类模板
 */

//友元函数可以类内实现也可以类外实现
//类内实现和平时一样，类外实现步骤比较复杂
#include <iostream>
using namespace std;

//让编译器提前看到printPerson声明 否则下面声明它会不认识这是什么

//让编译器看到Person类声明
template<class NameType, class AgeType> class Person;

template<class NameType, class AgeType> void printPerson(Person<NameType, AgeType>& p);

template <class NameType, class AgeType>
class Person
{
    //一定要加上<>才是告诉编译器这是模板函数声明，否则只是普通函数声明
    friend void printPerson<>(Person<NameType, AgeType>& p);
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
template<class NameType, class AgeType>
void printPerson(Person<NameType, AgeType>& p)
{
    p.showPerson();
}

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
    cout<<"===================friend=================="<<endl;
    printPerson(p);
}

int main()
{
    test();
}
