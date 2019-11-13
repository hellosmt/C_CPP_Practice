/*
 * @Author: Cement
 * @Date: 2019-11-13 09:55:11
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-13 10:17:57
 * @Description: 食物模块实现
 */
#include"food.h"



 // 随机设置食物
void Food:: setFood()
{
    //随机生成食物的位置
    srand((unsigned int)time(NULL));
    int x = rand()%(this->m_wall.ROW-2)+1;
    int y = rand()%(Wall::COL-2)+1;

    //如果该位置是snake的头和身，则重新生成
    while (this->m_wall.getWall(x, y)!=' ')
    {
        x = rand()%(this->m_wall.ROW-2)+1;
        y = rand()%(Wall::COL-2)+1;
    }
    
    this->m_x=x;
    this->m_y=y;

    //在墙上对应坐标显示食物标志
    this->m_wall.setWall(x,y,'#');
}

Food:: Food(Wall& tempWall):m_wall(tempWall)
{
    
}