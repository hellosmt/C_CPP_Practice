/*
 * @Author: sunmengtuo
 * @Date: 2019-11-08 09:13:47
 * @LastEditTime: 2019-11-08 10:38:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C_CPP\C++基础\异常\test.cpp
 */
#include <iostream>
using namespace std;
#include<stdexcept>
#include<string>

//编写自己的异常类
class myException:public exception
{
public:
    myException(string errorInfo)
    {
        this->m_errorInfo = errorInfo;
    }

    virtual ~myException()
    {
        
    }
    
    virtual const char* what()   //这里不能写const？？
    {
        return this->m_errorInfo.c_str();
    }

private:
    string m_errorInfo;
};


int myDivision(int a, int b)
{
    if (b == 0)
    {
        throw myException("division 0");
    }
    return a / b;
}

void test()
{
    try
    {
        myDivision(10, 0);
    }
    catch (int) //接收int类型异常
    {
        cout << "catch(int) error!" << endl;
    }
    catch (double) //接收double类型异常
    {
        cout << "catch(double) error!" << endl;
    }
    catch (myException &e) //接收自定义异常myException类型异常
    {
        cout << e.what() << endl;
    }
    catch (...) //接收其他类型异常
    {
        cout << "catch(...) error!" << endl;
    }
}

int main()
{
    test();
}