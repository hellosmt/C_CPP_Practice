/*
 * @Author: Cement
 * @Date: 2019-11-01 10:53:10
 * @LastEditTime: 2019-11-01 11:41:48
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C\C_CPP\C++基础\面向对象设计案例-圆与点的关系\test.cpp
 */
//设计一个圆形类（AdvCircle），和一个点类（Point），计算点和圆的关系。


#include<iostream>
using namespace std;

class Point
{
public:
    void setX(int x)
    {
        p_x = x;
    }

    void setY(int y)
    {
        p_y = y;
    }

    int getX()
    {
        return p_x;
    }

    int getY()
    {
        return p_y;
    }
    
private:
    int p_x;//x坐标
    int p_y;//y坐标
};

class Circle
{
public: 
    void setR(int r)
    {
        c_r = r;
    }

    void setCenter(Point c)
    {
        c_center = c;
    }

    int getR()
    {
        return c_r;
    }

    Point getCenter()
    {
        return c_center;
    }
    
private:
    int c_r;//半径
    Point c_center;//圆心
};

//全局函数判断圆心与点的位置关系
void isInCircle(Circle c, Point p)
{   
    
    int r_square = c.getR()^2;//半径的平方
    int distance = (c.getCenter().getX()-p.getX())^2+(c.getCenter().getY()-p.getY())^2;//距离的平方
    if (r_square<distance)
    {
       cout<<"out"<<endl;
    }
    else if (r_square==distance)
    {
       cout<<"on"<<endl;
    }
    else
    {
       cout<<"in"<<endl;
    }
    
}

int main ()
{
    Circle c ;
    c.setR(5);
    Point p1, p2;
    p1.setX(2);
    p1.setY(3);
    p2.setX(2);
    p2.setY(5);
    c.setCenter(p1);
    isInCircle(c, p2);
}