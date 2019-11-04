/*
 * @Author: sunmengtuo
 * @Date: 2019-11-04 20:12:03
 * @LastEditTime: 2019-11-04 21:21:04
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C_CPP\C++基础\多态\计算器案例\Calculator.cpp
 */

#include<iostream>
#include<string>
using namespace std;

class Calculator
{
public:
    void set_v1(int v)
    {
        this->val1 = v;
    }

    void set_v2(int v)
    {
        this->val2 = v;
    }

    //虚函数
    virtual int getResult()
    {
        return 0;
    }
    
    //析构函数,若不写成虚的，则在析构指向子类对象的父类指针时只会调用父类的析构函数而不会调用子类的析构函数，导致释放不干净
    virtual ~Calculator()
    {
        cout<<"Calculator deconstructor"<<endl;
    }

    int val1;
    int val2;
};

//改写成纯虚版本
class AbstractCalculator
{
public:
    void set_v1(int v)
    {
        this->val1 = v;
    }

    void set_v2(int v)
    {
        this->val2 = v;
    }

    //纯虚函数
    virtual int getResult()=0;

    int val1;
    int val2;
};


class PlusCalculator:public Calculator
{
public:
    
    virtual int getResult()
    {
        return this->val1 + this->val2;
    }

    //析构函数
    virtual ~PlusCalculator()
    {
        cout<<"PlusCalculator deconstructor"<<endl;
    }
};

class SubCalculator:public AbstractCalculator
{
public:
    virtual int getResult()
    {
        return this->val1 - this->val2;
    }
};

void test()
{
    //父类指针指向子类对象
    Calculator* cal = new PlusCalculator;
    cal->set_v1(10);
    cal->set_v2(100);
    cout<<cal->getResult()<<endl;
    delete cal;

}

int main()
{
    test();
}
