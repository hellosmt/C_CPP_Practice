/*
 * @Author: Cement
 * @Date: 2019-11-13 08:48:22
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-13 09:46:49
 * @Description: 
 */
#include"snake.h"

//构造函数
Snake::Snake(Wall& tempWall):m_wall(tempWall)
{
    //头指向空
    this->m_head=NULL;
}

//初始化snake
void Snake::initSnake()
{
    //先销毁原先的snake，考虑游戏被重玩
    destorySnake();

    //添加节点
    addPoint(5,3);
    addPoint(5,4);
    addPoint(5,5);
}

//添加身子
void Snake::addPoint(int x, int y)
{
    //创建新节点
    Point* pNew = new Point;
    pNew->x=x;
    pNew->y=y;
    pNew->pNext=NULL;

    //如果原先头结点不为空
    if (this->m_head!=NULL)
    {
        //原来的头显示为身子=        
        this->m_wall.setWall(this->m_head->x, this->m_head->y,'=');
    }

    //将新节点显示为头@，将头结点指向新节点
    this->m_wall.setWall(x,y,'@');
    pNew->pNext=this->m_head;
    this->m_head=pNew;
}

//销毁snake
void Snake::destorySnake()
{
    Point* pCurrent = this->m_head;
    while (pCurrent!=NULL)
    {
        this->m_head=this->m_head->pNext;
        delete pCurrent;
        pCurrent=this->m_head;
    }
}