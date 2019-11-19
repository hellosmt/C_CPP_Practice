/*
 * @Author: Cement
 * @Date: 2019-11-16 16:40:37
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-16 22:44:47
 * @Description: 跟着侯捷老师的C++面向对象高级开发课程自己实现complex（复数类），注意点会进行注释
 */

//头文件卫士，防止头文件重复包含
#ifndef __COMPLEX__
#define __COMPLEX__


class Complex
{
private:
    double m_re;
    double m_im;
    
    friend Complex& __doapl (Complex& ths, const Complex& c);


public:
    //构造函数，使用默认参数和初始化列表
    Complex(double r = 0, double i = 0) : m_re(r), m_im(i)
    {
    }
    //提供上述使用了默认参数的构造函数之后，不可以再提供无参构造函数，否则使用Complex c = Complex()，编译器不知道调用哪一个，因为两个都满足条件，有二义性

    //这两个函数没有对数据进行修改，设置为const，很容易忘
    //如果没有写const，而用户定义了一个const Complex c，那么他就无法调用c.real(),因为c是一个常量，用户只想要拿到它的实数部分，按道理来说应该给通过的，但是real()没有声明为const，编译器认为你的real()可能会对c进行修改，所以编译器不让调用，用户就会觉得这个类设计得有问题，所以该加上const就要加上const，大气！
    double real() const
    {
        return this->m_re;
    }

    double imag() const
    {
        return this->m_im;
    }

    Complex& operator += (const Complex& c);
};


inline Complex& __doapl (Complex& ths, const Complex& c)
{
    ths.m_re += c.m_re;
    ths.m_im += c.m_im;
    return ths;
}

inline Complex& Complex::operator +=(const Complex& c)
{
    return __doapl(*this, c);
}

//重载+，根据client需要，有三种加法形式，复数+复数、复数+实数、实数+复数
//所以不能写为成员函数
inline Complex operator+ (const Complex& c1, const Complex& c2)
{
    //使用匿名对象
    return Complex(c1.real()+c2.real(), 
                    c1.imag()+c2.imag());
}

inline Complex operator+ (const Complex& c, const double b)
{
    //使用匿名对象
    return Complex(c.real()+b, 
                    c.imag());
}


inline Complex operator+ (const double b, const Complex& c )
{
    //使用匿名对象
    return Complex(c.real()+b, 
                    c.imag());
}


#endif
