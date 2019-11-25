/*
 * @Author: Cement
 * @Date: 2019-11-20 16:26:32
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-21 17:55:58
 * @Description: P1-转换函数示例
 */

using namespace std;
//-------------------------------------------------------------

//P1-转换函数示例
//-------------------------------------------------------------
#include <iostream>

namespace test01
{
//分数类
class Fraction
{
public:
    Fraction(int a, int b) : m_numerator(a), m_denominator(b) {}

    //转换函数
    //这个函数代表可以把Fraction类的对象转换成double类型，没有参数也不用写返回类型
    //因为它肯定返回的就是double类型，不可能是其他类型，所以编译器干脆不让你写，怕你写错
    //const不要忘记
    operator double() const
    {
        return (double)m_numerator / m_denominator;
    }

private:
    int m_numerator;   //分子
    int m_denominator; //分母
};

void conversion_function_test()
{
    Fraction f(3, 5);
    //本来0.4+f为double+Fraction，但是并没有重载+运算符使得两个加数分别为double和Fraction
    //所以编译器会找看有没有其他方法
    //因为我们定义了转换函数，使得Fraction类型可以转换成double类型，所以这里的f被转换成double类型，就是0.4+0.6=1
    float r = 0.4 + f;
    cout << r << endl;
}
} // namespace test01

//P2:none-explicit-one-argument-ctor示例
//-------------------------------------------------------------
#include <iostream>

namespace test02
{
//分数类
class Fraction
{
public:
    //none-explicit-one-argument-ctor，分母默认为1，所以你可以只传一个参数进来
    //因此编译器就可以将int数字转换成Fraction类型，也就是隐式类型转换
    //所以当构造函数可以只传一个参数进来进行构造时，最好要加上explicit关键字，防止隐式类型转换
    Fraction(int a, int b = 1) : m_numerator(a), m_denominator(b) {}

    operator double() const
    {
        return (double)m_numerator / m_denominator;
    }

    Fraction operator+(const Fraction &f)
    {
        return Fraction(this->m_numerator + f.m_numerator, this->m_denominator + f.m_denominator);
    }

private:
    int m_numerator;   //分子
    int m_denominator; //分母
};

void conversion_function_test()
{
    Fraction f(3, 5);

    //出现二义性
    //因为f可以通过operator double转换成double再和4相加
    //4又可以通过none-explicit-one-argument-ctor进行隐式转换成Fraction类型和f相加（我们有重载+运算符使得两个分数类型可以相加）
    //因此编译器有两条路可以走，出现二义性
    //Fraction f1 = f + 4;
}
} // namespace test02

//P15:reference示例
//-------------------------------------------------------------
#include <iostream>

namespace test03
{
void reference_test()
{
    cout << "test_reference()" << endl;

    int x = 0;
    int *p = &x;
    int &r = x;                                //r代表x r=x=0
    cout << "x:" << x << endl;                 //0
    cout << "p:" << p << endl;                 //0x23fe04
    cout << "r:" << r << endl;                 //0
    cout << "&x:" << &x << endl;               //0x23fe04
    cout << "&r:" << &r << endl;               //0x23fe04 和&x是一样的，但其实是假象
    cout << "sizeof(x):" << sizeof(x) << endl; //4
    cout << "sizeof(r):" << sizeof(r) << endl; //4 和sizeof(x)是一样的，但其实是假象，r本质是一个指针，但它代表了x，所以大小和地址和x都是一样的是很合理的

    typedef struct Stag
    {
        int a, b, c, d;
    } S;

    S s = {1, 2, 3, 4};
    S &sr = s;
    cout << "sizeof(s):" << sizeof(s) << endl;   //16
    cout << "sizeof(sr):" << sizeof(sr) << endl; //16
    cout << "&s:" << &s << endl;                 //0x23fdf0
    cout << "&sr:" << &sr << endl;               //0x23fdf0
}

} // namespace test03

//P14:variadic_templates示例
//-------------------------------------------------------------
#include <iostream>
namespace test04
{
void print()
{
}

//可变模板
template <typename T, typename... Types>
void print(const T &arg1, const Types &... args)
{
    cout<<sizeof...(args)<<endl;//sizeof...(args)得到args里面参数的个数
    cout << arg1 << endl;
    print(args...);
}

void variadic_templates_test()
{
    cout << "variadic_templates_test()" << endl;
    print(4,"cpp", 1.2);
}
} // namespace test04

int main(int argc, char **argv)
{
    //测试编译器支持到c++多新的特性98、11还是14
    cout << __cplusplus << endl; //199711 or 201103 or 201402

    //test01::conversion_function_test();
    //test02::conversion_function_test();
    //test03::reference_test();
    test04::variadic_templates_test();
}
