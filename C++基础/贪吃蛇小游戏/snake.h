/*
 * @Author: Cement
 * @Date: 2019-11-13 08:48:27
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-13 20:39:28
 * @Description: 
 */
#pragma once

#include <iostream>
#include "wall.h"
#include "food.h"
//#include <string>
//using namespace std;

class Snake
{
private:
    bool isLoop;
    struct Point
    {
        int x; //记录坐标而不是char字符
        int y;
        struct Point *pNext;
    };

    Point *m_head; //头结点
    Wall &m_wall;  //添加节点时需要使用到wall的setPoint，维护一个wall对象,引用是为了让外部传一个wall对象进来，而不是snake自己创建的一个wall对象
    Food &m_food;

public:
    enum e
    {
        UP = 'w',
        DOWN = 's',
        LEFT = 'a',
        RIGHT = 'd'
    };

    // 构造函数
    Snake(Wall &tempWall, Food &tempFood);

    //初始化snake
    void initSnake();

    //添加身子
    void addPoint(int x, int y);

    //删除尾节点
    void deleteTailPoint();

    //根据用户按下的键进行相应的移动
    //返回值告诉外界是否移动成功，外界可以根据该bool值继续游戏或者是游戏结束
    bool move(char key);

    //销毁snake
    void destorySnake();
};
