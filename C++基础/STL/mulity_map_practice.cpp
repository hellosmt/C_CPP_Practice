/*
 * @Author: sunmengtuo
 * @Date: 2019-11-11 09:42:52
 * @LastEditTime: 2019-11-11 11:15:34
 * @LastEditors: Please set LastEditors
 * @Description: mulity_map练习,这里发现一个字符串常量和字符不能简单相加的问题
 * @FilePath: \C_CPP\C++基础\STL\mulity_map_practice.cpp
 */

/*
公司今天招聘了5个员工，5名员工进入公司之后，需要指派员工在那个部门工作
人员信息有: 姓名 年龄 电话 工资等组成
通过Multimap进行信息的插入 保存 显示
分部门显示员工信息 显示全部员工信息
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

#define SALE_DEPATMENT 1     //销售部门
#define DEVELOP_DEPATMENT 2  //研发部门
#define FINACIAL_DEPATMENT 3 //财务部门
#define ALL_DEPATMENT 4      //所有部门

class Employee
{
public:
    string m_name;
    int m_age;

    Employee(string name, int age);
    ~Employee();
};

Employee::Employee(string name, int age)
{
    this->m_name = name;
    this->m_age = age;
}

Employee::~Employee()
{
}

//创建员工vector
void CreateEmployees(vector<Employee> &v)
{
    string name_seed = "ABCDE";
    for (int i = 0; i < 5; ++i)
    {
        string name = "Employee";
        name += name_seed[i];  //一定要用重载运算符+=，而不能在上面简单相加，简单相加相当于是指针加上整数类型，具体解释见main函数注释部分
        Employee e = Employee(name, 20 + i);
        //cout<<e.m_name<<":"<<e.m_age<<endl;
        v.push_back(e);
    }
}

//分配部门
void EmployeeByGroup(multimap<int, Employee> &m, const vector<Employee> &v)
{
    for (vector<Employee>::const_iterator cit = v.begin(); cit < v.end(); ++cit)
    {
        m.insert(make_pair(rand() % 3 + 1, *cit));
    }
}

//打印所有员工信息
void PrintAllEmployee(const multimap<int, Employee> &m)
{
    for (multimap<int, Employee>::const_iterator cit = m.begin(); cit != m.end(); ++cit)
    {
        cout << cit->second.m_name << ": " << cit->second.m_age << " ";
        switch (cit->first)
        {
        case SALE_DEPATMENT:
            cout << "SALE DEPATMENT" << endl;
            break;
        case DEVELOP_DEPATMENT:
            cout << "DEVELOP DEPATMENT" << endl;
            break;
        case FINACIAL_DEPATMENT:
            cout << "FINACIAL DEPATMENT" << endl;
            break;
        default:
            break;
        }
    }
}

void test()
{
    vector<Employee> v;
    //创建员工vector
    CreateEmployees(v);

    //分配部门
    //设置随机数种子，随机分配部门
    srand((unsigned int)(time(NULL)));
    multimap<int, Employee> m;
    EmployeeByGroup(m, v);

    //打印所有员工信息
    PrintAllEmployee(m);
}

int main()
{
    test();
    // string name = "abc" + 'a';//"abc"为元素为char类型的数组，在表达式中隐式转换为指针，'a'类型为char，是一个整数类型，指向数组首元素（或者说第0个元素）的指针加上整数N，结果就是指向数组第N个元素的指针。——如果数组没有N个元素，结果是未定义的，然而编译器不一定能检查出这种情况
    // name += 'a';
    // cout<<name<<endl;
}
