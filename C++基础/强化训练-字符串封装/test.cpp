/*
 * @Author: sunmengtuo
 * @Date: 2019-11-04 19:52:58
 * @LastEditTime: 2019-11-05 17:38:40
 * @LastEditors: Cement
 * @Description: In User Settings Edit
 * @FilePath: \C_CPP\C++基础\强化训练-字符串封装\test.cpp
 */
#include"MyString.h"

void test()
{
    MyString s1 = MyString("hello world!");
    MyString s2 = MyString(s1);
    cout<<s1<<endl<<s2<<endl;

    if (s1==s2)
    {
        cout<<"s1==s2"<<endl;
    }
    

    s2 = "chase the sun";
    s1 = s1+s2;
    cout<<s1<<endl<<s2<<endl;

    cout<<"s1[6]:"<<s1[6]<<endl;
    
}

int main()
{
    test();
}