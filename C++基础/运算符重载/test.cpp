/*
 * @Author: Cement
 * @Date: 2019-11-03 13:22:30
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-03 21:04:25
 * @Description: +、<<、 前置后置++、 关系运算符、智能指针、==、()
 */
#include<iostream>
#include<string>
using namespace std;

class Person
{
    friend ostream& operator<<(ostream& cout, Person &p);
private:
    int m_age;//年龄
public:
    Person();
    Person(int age);
    ~Person();

    //成员函数重载加号运算符
    void operator+(Person& p);

    //前置++运算符重载
    Person& operator++();

    //后置++运算符重载，使用占位符进行区分
    Person operator++(int);

    //重载比较运算符
    bool operator==(Person& p)
    {
        if (this->m_age == p.m_age )
        {
            return true;
        }
        return false;
    }

    //函数调用运算符重载
    void operator()()
    {
        cout<<"I am "<<this->m_age<<" years old"<<endl;
    }
    
    int get_age()
    {
        return this->m_age;
    }
};

//用来托管自定义类型的开辟在堆区的对象，让对象进行自动释放（程序员有时候忘记delete）
class SmartPointer
{
public:
    SmartPointer(Person* p)
    {
        this->p = p;
    }
    
    ~SmartPointer()
    {
        if (this->p!=NULL)
        {
            delete p;
            p = NULL;
        }
    }

    //重载->
    Person* operator->()
    {
        return this->p;
    }

    //重载*
    Person& operator*()
    {
        return *(this->p);
    }
private:
    Person *p;
};


//重载左移运算符
ostream& operator<<(ostream& cout, Person &p)
{
    cout<<p.m_age;
    return cout;
}

Person::Person()
{
    this->m_age=0;
}
    
Person::Person(int age)
{
    this->m_age = age;
}

Person::~Person()
{
    cout<<"=====deconstructor======="<<endl;
}

//加号运算符重载
void Person::operator+(Person& p)
{
    this->m_age = this->m_age+p.m_age;
}

//前置++运算符重载
Person& Person::operator++()
{
    ++this->m_age;
    return *this;
}

//后置++运算符重载，使用占位符进行区分
Person Person::operator++(int)
{
    //保存当前的对象
    Person tmp = *this;
    ++this->m_age;
    return tmp;
}

int main()
{
    Person p1  = Person(10);
    Person p2 = Person(20) ;
    //测试加号
    p1+p2;
    //测试<<
    cout<<"p1:"<<p1<<endl;
    //测试前置自增
    cout<<++(++p2)<<endl;
    cout<<"p2:"<<p2<<endl;
    //测试后置自增
    p1++;
    //cout<<p1++<<endl; //报错啦？？？

    //测试智能指针
    Person* p3 = new Person(100);//开辟在堆区
    SmartPointer sp = SmartPointer(p3);
    
    //如果想要使用sp->m_age,重载->
    cout<<"p3:"<<sp->get_age()<<endl;//应该是sp->->get_age(),编译器进行了优化
    
    //想要使用*取到实体，重载*
    cout<<"p3:"<<(*sp).get_age()<<endl;

    //测试比较运算符
    if (*p3==p2)
    {
        cout<<"p3 and p2 are same old"<<endl;
    }else
    {
        cout<<"p3 and p2 are not same old"<<endl;
    }
    
    //测试函数调用运算符
    p1();
    p2();
}