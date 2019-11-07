/*
 * @Author: Cement
 * @Date: 2019-11-07 13:48:42
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-07 14:01:00
 * @Description: 
 */
#include"Person.hpp"
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
