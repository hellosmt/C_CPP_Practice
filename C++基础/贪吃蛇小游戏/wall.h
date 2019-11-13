/*
 * @Author: Cement
 * @Date: 2019-11-12 18:01:54
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-13 20:52:04
 * @Description: 
 */
#ifndef _WALL_HEAD
#define _WALL_HEAD

#include <iostream>
using namespace std;

class Wall
{
public:
    enum
    {
        ROW = 24,
        COL = 48
    };

    //初始化墙壁
    void initWall();

    //画墙
    void drawWall();

    //设置某点
    void setWall(int x, int y, char c);

    //获取某点
    char getWall(int x, int y);

private:
    char m_wall[ROW][COL];
};

#endif
