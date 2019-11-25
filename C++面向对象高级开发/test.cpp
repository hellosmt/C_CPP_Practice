/*
 * @Author: Cement
 * @Date: 2019-11-16 23:53:57
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-16 23:59:00
 * @Description: 
 */
#include<iostream>
using namespace std;

class A
{
public:
    virtual void func1()
    {
        cout<<"A"<<endl;
    }
};

class B: public A
{
public:
    virtual void func1()
    {
        cout<<"B"<<endl;
    }
};

int main(int argc, char* argv[])
{
    B b;
    A a = (A)b; //子类转为父类

    a.func1();

    A* ap = new B;
    ap->func1();

    ap = &b;
    ap->func1();

}




