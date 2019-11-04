/*
 * @Author: Cement
 * @Date: 2019-11-02 13:15:24
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-02 13:48:39
 * @Description: 单例模式案例-打印机
 */
#include<iostream>
#include<string>
using namespace std;

class Printer
{
private:
    //默认构造函数和拷贝构造函数都应设为private
    Printer()
    {
        print_count=0;
    }

    Printer(const Printer &p){}

    static Printer * singlePrinter; //这里只是定义，还需要在类外进行初始化
    int print_count;

public:
    static Printer* getInstance() //这里不要忘记写上static
    {
        return singlePrinter;
    }

    void printText(string s)
    {
        cout<<print_count<<" print:"<<s<<endl;
    }
};

Printer* Printer::singlePrinter = new Printer;//对静态类成员进行初始化

int main()
{
    //拿到打印机
    Printer* p = Printer::getInstance();

    p->printText("入职报告");
    p->printText("加薪申请");
    p->printText("离职报告");
    p->printText("退休申请");

}