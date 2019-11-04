/*
 * @Author: Cement
 * @Date: 2019-11-02 22:25:13
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-02 22:46:46
 * @Description: 
 */
#include"MyArray.h"
#include<string>
using namespace std;

void test()
{
    MyArray arr1 = MyArray();
    MyArray* arr2 = new MyArray(arr1);   //调用拷贝构造
    MyArray arr3 = *arr2;  //这种也是调用拷贝构造
    MyArray arr4 = arr1;  //这种也是调用拷贝构造

    MyArray* arr5 = arr2;  //这个是定义一个指针指向arr2，不是拷贝构造创建对象！！！

    for (int i = 0; i < 10; i++)
    {
        arr2->push_back(i);
    }

    arr1.set_data(0,1000);

    //打印
    for (int i = 0; i < arr2->get_size(); i++)
    {
        cout<<arr2->get_data(i)<<endl;
    }
    
    
}


int main()
{
    test();
}