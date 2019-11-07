/*
 * @Author: Cement
 * @Date: 2019-11-07 07:42:32
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-07 08:17:31
 * @Description: 函数模板敲一敲
 */
#include <iostream>
using namespace std;

/*
==============    函数模板简单测试   ==============
*/
template <class T>
T function(T a, T b)
{
    return a + b;
}

//重载的普通函数，除非模板函数更加匹配，否则都是优先使用普通函数
int function(int a, int b)
{
    cout << "=====myFunc=====" << endl;
    return a + b;
}

void test1()
{
    int a = 10, b = 100;
    int ret = function(a, b); //自动类型推导
    cout << ret << endl
         << endl;
    int result = function<>(a, a); //强制使用模板函数
    cout << result << endl;
}

/*
==============    函数模板具体化测试   ==============
*/
class Person
{

public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

//这里的T加&，模板具体化也得加上&，才配套
template <class T>
bool myCompare(T &a, T &b)
{
    cout << "===========myCompare<T>=============" << endl;
    if (a >= b)
    {
        return true;
    }
    return false;
}
//模板具体化
template <>
bool myCompare<Person>(Person &a, Person &b)
{
    cout << "===========myCompare<Person>=============" << endl;
    if (a.m_Age >= b.m_Age)
    {
        return true;
    }
    return false;
}

//模板具体化
template <>
bool myCompare<int>(int &a, int &b)
{
    cout << "===========myCompare<int>=============" << endl;
    if (a >= b)
    {
        return true;
    }
    return false;
}
//普通函数
// bool myCompare(int a, int b)
// {
//     cout<<"===========myCompare============="<<endl;
//     if (a>=b)
//     {
//         return true;
//     }
//     return false;
// }

void test2()
{
    int a = 10, b = 100;
    cout << myCompare(a, b) << endl; //当具体化和模板都匹配时，优先使用具体化

    Person p1 = Person("Linux", 20);
    Person p2 = Person("Ubuntu", 10);
    cout << myCompare(p1, p2) << endl;
}

int main()
{
    test2();
}
