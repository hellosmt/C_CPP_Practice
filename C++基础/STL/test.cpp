/*
 * @Author: Cement
 * @Date: 2019-11-11 19:48:16
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-11 21:44:36
 * @Description: stl测试案例-vector的随机访问迭代器,list使用小案例,让set逆序存储,仿函数适配器-打印时给每个元素加上一个起始值
 */


#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <ctime>
#include<algorithm>
#include <functional>
using namespace std;

//vector的随机访问迭代器
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }

    vector<int>::iterator it = v.begin();
    cout << *it << endl;
    it += 3;
    cout << *it << endl;
}

//list使用小案例
void test02()
{
    list<int> l;
    for (int i = 0; i < 10; i++)
    {
        l.push_back(i + 1);
        l.push_front(i + 1);
    }

    for (list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << endl;
    }
}

//让set逆序存储
class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        if (v1 < v2)
        {
            return true;
        }
        return false;
    }
};

//使用仿函数让set逆序存储
void test03()
{

    set<int, MyCompare> s;
    for (int i = 0; i < 10; i++)
    {
        s.insert(rand() % 20);
    }
    for (set<int, MyCompare>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << endl;
    }
}

//仿函数适配器
//打印时给每个元素加上一个起始值
class MyPrint:public binary_function<int, int, void>
{
public:
    void operator()(int data, int start) const   //必须加上const
    {
        cout<<data+start<<" ";
    }
    
};

void test04()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(rand() % 20);
    }
    //你想在遍历打印时给每个元素加上一个起始值，使用适配器
    for_each(v.begin(), v.end(), bind2nd(MyPrint(),1000));
    cout<<endl;
}


int main()
{
    srand((unsigned int)time(NULL));
    //test01();
    //test02();
    //test03();
    test04();
}
