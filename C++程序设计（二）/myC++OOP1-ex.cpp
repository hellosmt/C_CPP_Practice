/*
 * @Author: Cement
 * @Date: 2019-12-03 17:51:07
 * @LastEditors: Cement
 * @LastEditTime: 2019-12-04 13:41:00
 * @Description: 
 */
using namespace std;

//composite模式
#include <iostream>
#include <vector>
#include <iterator>

namespace test01
{
class Component
{
private:
    int value;

public:
    Component(int v) : value(v) {}
    virtual void add() {}
    int getValue() const
    {
        return this->value;
    }
};

class Composite : public Component
{
private:
    vector<Component *> v;

public:
    Composite(int v) : Component(v) {}
    virtual void add(Component *c)
    {
        v.push_back(c);
    }
    void printVector() //这里加上const会报错 怎么改
    {
        for (vector<Component *>::iterator it = this->v.begin(); it < this->v.end(); it++)
        {
            cout << (*it)->getValue() << endl;
        }
    }
};

class Primitive : public Component
{

public:
    Primitive(int v) : Component(v) {}
};

void test_composite()
{
    Primitive p1 = Primitive(1);
    Composite c = Composite(2);
    Composite c1 = Composite(3);
    c.add(&p1);
    c.add(&c1);
    c.printVector();
}

} // namespace test01

int main()
{
    test01::test_composite();
}