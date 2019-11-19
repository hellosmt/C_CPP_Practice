/*
 * @Author: Cement
 * @Date: 2019-11-18 10:58:58
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-18 20:20:36
 * @Description: String类测试文件
 */
#include"String.h"
using namespace std;

inline ostream& operator<<(ostream& cout, const String& s)
{
    cout<<s.get_str();
    return cout;
}

int main()
{
    String s1();
    cout<<s1<<endl;
    String s2("hello");
    cout<<s2<<endl;
    String s3 = s2;
    cout<<s3<<endl;
    String s4(s2);
    cout<<s4;
    s3 = s3;
}