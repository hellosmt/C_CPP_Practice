/*
 * @Author: Cement
 * @Date: 2019-11-13 09:55:05
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-13 10:21:22
 * @Description: 食物模块头文件
 */
#pragma once
#include <ctime>
#include <string>
#include "wall.h"

class Food
{
private:
    int m_x;
    int m_y;
    Wall &m_wall; //也需要维护一个wall的对象引用，因为在设置食物时需要调用它的setWall方法
public:
    // 随机设置食物
    void setFood();

    //构造函数
    Food(Wall &tempWall);
};
