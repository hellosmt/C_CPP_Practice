/*
 * @Author: Cement
 * @Date: 2019-11-12 18:01:48
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-13 20:39:20
 * @Description: 
 */
#include "wall.h"

//初始化墙壁
void Wall::initWall()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1)
            {
                this->m_wall[i][j] = '*';
            }
            else
            {
                this->m_wall[i][j] = ' ';
            }
        }
    }
}

//画墙
void Wall::drawWall()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << this->m_wall[i][j] << " ";
        }

        if (i == 5)
        {
            cout << "created by Cement";
        }
        if (i == 6)
        {
            cout << "UP:w";
        }
        if (i == 7)
        {
            cout << "DOWN:s";
        }
        if (i == 8)
        {
            cout << "LEFT:a";
        }
        if (i == 9)
        {
            cout << "RIGHT:d";
        }
        cout << endl;
    }
}

//设置某点
void Wall::setWall(int x, int y, char c)
{
    this->m_wall[x][y] = c;
}

//获取某点
char Wall::getWall(int x, int y)
{
    return this->m_wall[x][y];
}
