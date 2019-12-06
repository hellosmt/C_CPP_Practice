/*
 * @Author: Cement
 * @Date: 2019-11-14 11:19:09
 * @LastEditors: Cement
 * @LastEditTime: 2019-12-06 23:42:22
 * @Description: 
 */

using namespace std;

// void test()
// {
//     std::vector<int, std::allocator<int>> v ;
//     v.push_back(0);
//     v.push_back(2);
//     v.push_back(2000);

//     //c++11??
//     //auto range-based for statement
//     for (auto i :v)
//     {
//         std::cout<<i<<" ";
//     }

//     std::cout<<std::endl;

//     for (auto &i:v)
//     {
//         i *= 3;
//     }

//     for (auto i:v)
//     {
//         std::cout<<i<<" ";
//     }

// }

// void test01()
// {
//     vector<int> v ;
//     cout<<v.max_size()<<endl;
//     for (int i = 0; i < 10; i++)
//     {
//         v.push_back(i);
//     }
//     find(v.begin(), v.end(), 7);

//     int i = 1000;
//     string(i);
// }

#include <iostream>
#include <vector>
#include <algorithm> //count_if()

namespace test001
{
void test()
{
    int a[6] = {6, 55, 78, 20, 41, 98};
    vector<int, allocator<int>> v(a, a + 6);
    //bind2nd就是将40和less()的第二个参数进行绑定，第一个参数就是v中的元素
    cout << count_if(v.begin(), v.end(), not1(bind2nd(less<int>(), 40))) << endl;
    //test range_based
    for (auto elem : v)
    {
        cout << elem << endl;
    }
}
} // namespace test001

#include <cstdlib> //RAND_MAX
long get_target_long()
{
    long target;
    cout << "target(0~" << RAND_MAX << "):";
    cin >> target;
    return target;
}

int compareLongs(const void *v1, const void *v2)
{
    return (*(long *)v1 - *(long *)v2);
}


string get_target_string()
{
    long target = 0;
    char buf[10] ;
    cout << "target(0~" << RAND_MAX << "):";
    cin >> target;
    snprintf(buf, 10, "%d", target);
    return string(buf);
}

#include <iostream>
#include <array>
#include <cstdlib> //srand()
#include <ctime>   //clock,time
const long ASIZE = 500000L;
namespace tt01
{
void test_array()
{

    array<int, ASIZE> c;
    clock_t timeStart = clock();
    for (long i = 0; i < ASIZE; i++)
    {
        c[i] = rand();
    }
    cout << "assign time:" << clock() - timeStart << " milli-seconds" << endl;
    cout << "array.data()=" << c.data() << endl; //c.data() 数组首地址
    cout << "array.size()=" << c.size() << endl;
    cout << "array.front()=" << c.front() << endl;
    cout << "array.back()=" << c.back() << endl;
    long target = get_target_long();
    timeStart = clock();
    ::qsort(c.data(), ASIZE, sizeof(long), compareLongs);
    long *pSearch = (long *)::bsearch(&target, c.data(), ASIZE, sizeof(long), compareLongs);
    if (pSearch)
    {
        cout << "found:" << *pSearch << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    cout << "qsort+bsearch:" << clock() - timeStart << " milli-seconds" << endl;
}
} // namespace tt01

#include<iostream>
#include<vector>
#include<string>
namespace tt02
{
void test_vector(long& elem_num)
{
    vector<string> c;
    char buf[10];
    for (long  i = 0; i < elem_num; i++)
    {
        snprintf(buf, 10, "%d", rand());
        c.push_back(string(buf));
    }
    cout<<"vector.front()="<<c.front()<<endl;
    cout<<"vector.back()="<<c.back()<<endl;
    cout<<"vector.size()="<<c.size()<<endl;
    cout<<"vector.capacity()="<<c.capacity()<<endl;
    cout<<"vector.max_size()="<<c.max_size()<<endl;
    cout<<"vector.data()="<<c.data()<<endl;
    string target = get_target_string();
    clock_t timeStart = clock();
    
    auto pIte = ::find(c.begin(), c.end(), target);
    
    cout<<"::find:"<<clock()-timeStart<<" milli-seconds"<<endl;
    if (pIte!=c.end())
    {
        cout<<"found:"<<*pIte<<endl;
    }else
    {
        cout<<"not found"<<endl;
    }
    
}
} // namespace tt02

int main()
{
    //设置随机数种子
    srand((unsigned int)(time(NULL)));
    //test01();
    //test001::test();
    //tt01::test_array();
    long a = 100000;
    tt02::test_vector(a);
}
