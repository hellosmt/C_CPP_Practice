/*
 * @Author: Cement
 * @Date: 2019-11-02 22:01:20
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-02 22:36:59
 * @Description: 
 */
#include"MyArray.h"
#include<string>
using namespace std;

MyArray::MyArray()
{
    cout<<"default constructor"<<endl;
    this->m_capacity= 100;
    this->m_size = 0;
    this->pAddress = new int[this->m_capacity];
}

MyArray::MyArray(int capacity)
{
    cout<<"parameter constructor"<<endl;
    this->m_capacity= capacity;
    this->m_size = 0;
    this->pAddress = new int[this->m_capacity];
}

MyArray::MyArray(const MyArray& arr)
{
    cout<<"copy constructor"<<endl;
    this->m_capacity = arr.m_capacity;
    this->m_size = arr.m_size;
    this->pAddress = new int[this->m_capacity];
    memcpy(this->pAddress,arr.pAddress,this->m_size*sizeof(int));
}

MyArray::~MyArray()
{
    
    if (this->pAddress!=NULL)
    {
        delete[] this->pAddress;
        this->pAddress = NULL;
    }
}

void MyArray::push_back(int data)
{
    this->pAddress[this->m_size]=data;
    ++this->m_size;
}

//根据索引获取值
int MyArray::get_data(int index)
{
    return this->pAddress[index];
}


//根据索引设置值
void MyArray::set_data(int  index, int data)
{
    this->pAddress[index] = data;
}

int MyArray::get_size()
{
    return this->m_size;
}
