/*
 * @Author: Cement
 * @Date: 2019-11-07 19:13:42
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-07 19:48:42
 * @Description: 类模板应用-数组封装测试
 */
#include "MyArray.hpp"

/*
问题总结：
1.拷贝构造函数的参数没写const
2.重载赋值运算符时忘记判断原始数据是否为空
3.构造自定义数据类型数组，如Person类时，一定要提供Person类的默认构造函数
4.构造函数加上explicit 防止隐式转换
*/

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

//int类型数组打印
void printIntArray(MyArray<int> &arr)
{
    for (int i = 0; i < arr.getSize(); ++i)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

//Person类型数据打印
void printPersonArray(MyArray<Person> &arr)
{
    for (int i = 0; i < arr.getSize(); ++i)
    {
        cout << arr[i].m_name << ":" << arr[i].m_age << endl;
    }
}

void test()
{
    cout << "==========IntArray Test===========" << endl;
    MyArray<int> arr1 = MyArray<int>(10);
    for (int i = 0; i < arr1.getCapacity(); ++i)
    {
        arr1.push_back(i + 1);
    }
    printIntArray(arr1);

    cout << "==========PersonArray Test===========" << endl;
    MyArray<Person> arr2 = MyArray<Person>(3);
    Person p1 = Person("Linux", 24);
    Person p2 = Person("cpp", 15);
    Person p3 = Person("c", 88);

    arr2.push_back(p1);
    arr2.push_back(p2);
    arr2.push_back(p3);

    printPersonArray(arr2);
}

int main()
{
    test();
}
