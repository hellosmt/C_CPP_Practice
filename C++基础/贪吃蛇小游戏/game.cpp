/*
 * @Author: Cement
 * @Date: 2019-11-12 17:59:57
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-13 10:20:04
 * @Description: 
 */
#include "wall.h"
#include"snake.h"
#include"food.h"


void test()
{
    Wall w;
    w.initWall();

    Snake s(w);

    s.initSnake();

    Food f(w);
    f.setFood();

    w.drawWall();
}

int main()
{
    test();
}