/*
 * @Author: your name
 * @Date: 2019-11-08 10:57:12
 * @LastEditTime: 2019-11-08 11:05:22
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C_CPP\STL\test.cpp
 */
#include<iostream>
#include<vector>
using namespace std;

class Person
{
public:
    string m_name;
    int m_age;

    //一定要有Person的默认构造函数，因为在构造数组时，pArray=new T[capacity]，这里会调用的Person的默认构造函数
    Person()
    {
    }

    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
};

void test()
{
    vector<int> v ;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for (vector<int>::iterator  it = v.begin(); it < v.end(); it++)
    {
        cout<<*it<<" "<<endl;
    }
}

void test02()
{
    vector<Person> v;
    Person p1 = Person("Linux",20);
    Person p2 = Person("C", 30);
    Person p3 = Person("CPP", 65);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    for (vector<Person>::iterator  it = v.begin(); it < v.end(); it++)
    {
        cout<<(*it).m_name<<":"<<(*it).m_age<<endl;
    }
}


int main()
{
    //test();
    test02();
}