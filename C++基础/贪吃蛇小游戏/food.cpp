/*
 * @Author: Cement
 * @Date: 2019-11-13 09:55:11
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-13 23:11:52
 * @Description: 食物模块实现
 */
#include "food.h"
#include<windows.h>

//定位光标，不用清屏
void gotoxy1(HANDLE hOut, int x, int y)
{
	COORD pos;
	pos.X = x;             //横坐标
	pos.Y = y;            //纵坐标
	SetConsoleCursorPosition(hOut, pos);
}
HANDLE hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量

// 随机设置食物
void Food::setFood()
{
    //随机生成食物的位置
    srand((unsigned int)time(NULL));
    int x = rand() % (this->m_wall.ROW - 2) + 1;
    int y = rand() % (Wall::COL - 2) + 1;

    //如果该位置是snake的头和身，则重新生成
    while (this->m_wall.getWall(x, y) != ' ')
    {
        x = rand() % (this->m_wall.ROW - 2) + 1;
        y = rand() % (Wall::COL - 2) + 1;
    }

    this->m_x = x;
    this->m_y = y;

    //在墙上对应坐标显示食物标志
    this->m_wall.setWall(x, y, '#');
    gotoxy1(hOut1, y*2, x);
    cout<<'#';
}

Food::Food(Wall &tempWall) : m_wall(tempWall)
{
}