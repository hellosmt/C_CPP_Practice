/*
 * @Author: Cement
 * @Date: 2019-11-14 11:19:09
 * @LastEditors: Cement
 * @LastEditTime: 2019-12-16 10:22:06
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
    char buf[10];
    cout << "target(0~" << RAND_MAX << "):";
    cin >> target;
    snprintf(buf, 10, "%d", target);
    return string(buf);
}

int compareStrings(const void *v1, const void *v2)
{
    if (*(string *)v1 > *(string *)v2)
    {
        return 1;
    }
    if (*(string *)v1 < *(string *)v2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
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

    cout << "============test_array============" << endl;

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

#include <iostream>
#include <vector>
#include <string>
#include <cstdio> //snprintf()
namespace tt02
{
void test_vector(const long &elem_num)
{
    cout << "============test_vector============" << endl;

    vector<string> c;
    char buf[10];
    clock_t timeStart = clock();
    for (long i = 0; i < elem_num; i++)
    {
        //有可能空间不够，push_back不进去，所以进行try
        try
        {
            snprintf(buf, 10, "%d", rand());
            //每个string是一个指针大小，这里是用char[]来初始化一个匿名的string对象
            c.push_back(string(buf));
        }
        catch (const exception &e)
        {
            std::cerr << e.what() << '\n';
            abort(); //退出程序
        }
    }
    cout << "milli-seconds=" << clock() - timeStart << endl;
    cout << "vector.front()=" << c.front() << endl;
    cout << "vector.back()=" << c.back() << endl;
    cout << "vector.size()=" << c.size() << endl;
    cout << "vector.capacity()=" << c.capacity() << endl;
    cout << "vector.max_size()=" << c.max_size() << endl;
    cout << "vector.data()=" << c.data() << endl;
    string target = get_target_string();

    auto pIte = ::find(c.begin(), c.end(), target);

    cout << "::find:" << clock() - timeStart << " milli-seconds" << endl;
    if (pIte != c.end())
    {
        cout << "found:" << *pIte << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    timeStart = clock();
    ::sort(c.begin(), c.end());
    string *pItem = (string *)bsearch(&target, c.data(), c.size(), sizeof(string), compareStrings);
    cout << "qsort+bsearch:" << clock() - timeStart << " milli-seconds" << endl;
    if (pItem != NULL)
    {
        cout << "found:" << *pItem << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    c.clear();
}
} // namespace tt02

#include <iostream>
#include <list>
#include <cstdlib> //rand()
#include <ctime>
#include <cstdio> //snprintf()

namespace tt03
{
void test_list(const long &num_elem)
{
    cout << "============test_list============" << endl;
    list<string> c;

    char buf[10];
    clock_t timeStart = clock();
    for (long i = 0; i < num_elem; i++)
    {
        try
        {
            snprintf(buf, 10, "%d", rand());
            c.push_back(string(buf));
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            abort();
        }
    }
    cout << "milli-seconds=" << clock() - timeStart << endl;
    cout << "list.size()=" << c.size() << endl;
    cout << "list.front()=" << c.front() << endl;
    cout << "list.back()=" << c.back() << endl;
    cout << "list.max_size()=" << c.max_size() << endl; //384307168202282325 这个属性代表什么

    string target = get_target_string();

    timeStart = clock();
    list<string>::iterator pItem = ::find(c.begin(), c.end(), target);

    cout << "::find()=" << clock() - timeStart << " milli-seconds" << endl;
    if (pItem != c.end())
    {
        cout << "found:" << *pItem << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    timeStart = clock();

    //自带sort()
    c.sort();
    cout << "list.sort()=" << clock() - timeStart << " milli-seconds" << endl;

    c.clear();
}
} // namespace tt03

#include <ext/slist> //非标准库的
#include <iostream>
#include <string>
#include <cstdio>  //snprintf()
#include <cstdlib> //rand()
namespace tt04
{
void test_slist(const long &num_elem)
{
    cout << "============test_slist============" << endl;

    //在__gnu_cxx命名空间下
    __gnu_cxx::slist<string> c;
}
} // namespace tt04

#include <iostream>
#include <string>
#include <deque>
#include <ctime>
#include <exception>
namespace tt05
{
void test_deque(const long &num_elem)
{
    cout << "============test_deque============" << endl;

    deque<string> c;

    clock_t timeStart = clock();
    char buf[10];
    for (long i = 0; i < num_elem; i++)
    {
        try
        {
            snprintf(buf, 10, "%d", rand());
            c.push_back(string(buf));
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            abort();
        }
    }
    cout << "milli-seconds:" << clock() - timeStart << endl;
    cout << "deque.size()" << c.size() << endl;
    cout << "deque.front()" << c.front() << endl;
    cout << "deque.back()" << c.back() << endl;
    cout << "deque.max_size()" << c.max_size() << endl;

    string target = get_target_string();
    timeStart = clock();
    auto pItem = ::find(c.begin(), c.end(), target);
    cout << "::find(),milli seconds=" << clock() - timeStart << endl;
    if (pItem != c.end())
    {
        cout << "found:" << *pItem << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    timeStart = clock();
    ::sort(c.begin(), c.end());
    cout << "::sort(),milli seconds=" << clock() - timeStart << endl;
    c.clear();
}
} // namespace tt05

#include <iostream>
#include <cstdlib>
#include <set>
#include <string>
#include <ctime>
namespace tt06
{
void test_multiset(const long &num_elem)
{
    cout << "============test_multiset============" << endl;

    multiset<string> c;
    char buf[10];
    clock_t timeStart = clock();

    for (long i = 0; i < num_elem; i++)
    {
        snprintf(buf, 10, "%d", rand());
        c.insert(string(buf));
    }

    cout << "milli-seconds:" << clock() - timeStart << endl;
    cout << "multiset.size()=" << c.size() << endl;
    cout << "multiset.max_size()=" << c.max_size() << endl;
    string target = get_target_string();
    timeStart = clock();
    auto pItem = ::find(c.begin(), c.end(), target);
    cout << "::find() milli-seconds=" << clock() - timeStart << endl;
    if (pItem != c.end())
    {
        cout << "found:" << *pItem << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    timeStart = clock();
    pItem = c.find(target);
    cout << "multiset.find() milli-seconds=" << clock() - timeStart << endl;
    if (pItem != c.end())
    {
        cout << "found:" << *pItem << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    c.clear();
}
} // namespace tt06

#include <iostream>
#include <map>
#include <string>
#include <cstdlib>

namespace tt07
{
void test_multimap(const long &num_elem)
{
    cout << "============test_multimap============" << endl;

    multimap<long, string> c;
    char buf[10];
    clock_t timeStart = clock();
    for (long i = 0; i < num_elem; i++)
    {
        snprintf(buf, 10, "%d", rand());
        //不能使用[]来插入
        c.insert(pair<long, string>(i, (buf)));
    }
    cout << "milli-second:" << clock() - timeStart << endl;
    cout << "multimap.size()=" << c.size() << endl;
    cout << "multimap.max_size()=" << c.max_size() << endl;

    long target = get_target_long();
    // timeStart = clock();
    // auto pItem = ::find(c.begin(), c.end(), target);
    // cout<<"::find() milli-seconds="<<clock()-timeStart<<endl;
    // if (pItem != c.end())
    // {
    //     cout << "found:" << (*pItem).second << endl;
    // }
    // else
    // {
    //     cout << "not found" << endl;
    // }
    timeStart = clock();
    auto pItem = c.find(target);
    cout << "multimap.find() milli-seconds=" << clock() - timeStart << endl;
    if (pItem != c.end())
    {
        cout << "found:" << (*pItem).second << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    c.clear();
}
} // namespace tt07

#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <ctime>
namespace tt08
{
void test_unordered_map(const long &num_elem)
{
    cout << "============test_unordered_map============" << endl;

    unordered_map<long, string> c;
    for (long i = 0; i < num_elem; i++)
    {
        /* code */
    }
    char buf[10];
    clock_t timeStart = clock();
    for (long i = 0; i < num_elem; i++)
    {
        snprintf(buf, 10, "%d", rand());
        //不能使用[]来插入
        c.insert(pair<long, string>(i, (buf)));
    }
    cout << "milli-second:" << clock() - timeStart << endl;
    cout << "unordered_map.size()=" << c.size() << endl;
    cout << "unordered_map.max_size()=" << c.max_size() << endl;
    cout << "unordered_map.bucket_count()=" << c.bucket_count() << endl;
    cout << "unordered_map.max_bucket_count()=" << c.max_bucket_count() << endl;
    cout << "unordered_map.load_factor()=" << c.load_factor() << endl;
    cout << "unordered_map.max_load_factor()=" << c.max_load_factor() << endl;

    for (int j = 0; j < 20; j++)
    {
        cout << "bucket j has " << c.bucket_size(j) << " elements" << endl;
    }

    long target = get_target_long();
    timeStart = clock();
    auto pItem = c.find(target);

    cout << "unordered_map.find() milli-seconds=" << clock() - timeStart << endl;
    if (pItem != c.end())
    {
        cout << "found:" << (*pItem).second << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    c.clear();
}
} // namespace tt08

#include <iostream>
#include <unordered_set>
#include <string>
#include <cstdlib>
#include <ctime>
namespace tt09
{
void test_unordered_set(const long &num_elem)
{
    cout << "============test_unordered_set============" << endl;

    unordered_set<string> c;
    for (long i = 0; i < num_elem; i++)
    {
        /* code */
    }
    char buf[10];
    clock_t timeStart = clock();
    for (long i = 0; i < num_elem; i++)
    {
        snprintf(buf, 10, "%d", rand());
        //不能使用[]来插入
        c.insert(string(buf));
    }
    cout << "milli-second:" << clock() - timeStart << endl;
    cout << "unordered_set.size()=" << c.size() << endl;
    cout << "unordered_set.max_size()=" << c.max_size() << endl;
    cout << "unordered_set.bucket_count()=" << c.bucket_count() << endl;
    cout << "unordered_set.max_bucket_count()=" << c.max_bucket_count() << endl;
    cout << "unordered_set.load_factor()=" << c.load_factor() << endl;
    cout << "unordered_set.max_load_factor()=" << c.max_load_factor() << endl;

    for (int j = 0; j < 20; j++)
    {
        cout << "bucket j has " << c.bucket_size(j) << " elements" << endl;
    }

    string target = get_target_string();
    timeStart = clock();
    auto pItem = c.find(target);

    cout << "unordered_set.find() milli-seconds=" << clock() - timeStart << endl;
    if (pItem != c.end())
    {
        cout << "found:" << (*pItem) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    c.clear();
}
} // namespace tt09

#include <iostream>
#include <list>
#include <string>
#include <vector>
namespace tt10
{
void test_iterator_traits()
{
    list<string> c;
    cout << typeid(list<string>::iterator::value_type).name() << endl; //NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE

    vector<int> v;
    for (int i = 0; i < 30; i++)
    {
        v.push_back(i);
        cout << v.size() << endl;
        cout << v.capacity() << endl
             << endl;
    }

    cout << sizeof(v) << endl;     //24 三个指针大小 start finish end_of_storage
    cout << sizeof(int *) << endl; //8
    v.clear();
}
} // namespace tt10

#include <iostream>
#include <set>
#include <functional> //_Identity less
namespace tt11
{
void test_RB_tree()
{
    //G2.9 vs. G4.9 :
    //rb_tree => _Rb_tree,
    //identity<> => _Identity<>
    //insert_unique() => _M_insert_unique()
    //insert_equal() => _M_insert_equal()

    cout << "\ntest_Rb_tree().......... \n";

    _Rb_tree<int, int, _Identity<int>, less<int>> my_tree;
    cout << my_tree.empty() << endl; //1
    cout << my_tree.size() << endl;  //0

    my_tree._M_insert_unique(1);
    my_tree._M_insert_unique(5);
    my_tree._M_insert_unique(3);
    my_tree._M_insert_unique(8);
    my_tree._M_insert_unique(5);
    my_tree._M_insert_unique(1);

    cout << my_tree.empty() << endl;  //0
    cout << my_tree.size() << endl;   //4
    cout << my_tree.count(1) << endl; //1

    my_tree._M_insert_equal(1);
    my_tree._M_insert_equal(1);
    cout << my_tree.empty() << endl;  //0
    cout << my_tree.size() << endl;   //6
    cout << my_tree.count(1) << endl; //3

    my_tree.clear();
}

} // namespace tt11

#include <ext/pool_allocator.h>
int main()
{
    //设置随机数种子
    srand((unsigned int)(time(NULL)));
    //test01();
    //test001::test();
    //tt01::test_array();
    long a = 100000;
    //tt02::test_vector(a);
    //tt03::test_list(a);
    //tt04::test_slist(a);
    // tt05::test_deque(a);
    // tt06::test_multiset(a);
    // tt07::test_multimap(a);
    // tt08::test_unordered_map(a);
    // tt09::test_unordered_set(a);
    // tt10::test_iterator_traits();
    tt11::test_RB_tree();
}
