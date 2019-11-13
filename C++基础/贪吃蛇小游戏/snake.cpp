/*
 * @Author: Cement
 * @Date: 2019-11-13 08:48:22
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-13 23:16:31
 * @Description: 
 */
#include "snake.h"
#include<windows.h>

//定位光标，不用清屏
//坐标系是反的
void gotoxy(HANDLE hOut, int x, int y)
{
	COORD pos;
	pos.X = x;             //横坐标
	pos.Y = y;            //纵坐标
	SetConsoleCursorPosition(hOut, pos);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量

//构造函数
Snake::Snake(Wall &tempWall, Food &tempFood) : m_wall(tempWall), m_food(tempFood)
{
    //头指向空
    this->m_head = NULL;
    this->isLoop = false;
}

//初始化snake
void Snake::initSnake()
{
    //先销毁原先的snake，考虑游戏被重玩
    destorySnake();

    //添加节点
    addPoint(5, 3);
    addPoint(5, 4);
    addPoint(5, 5);
}

//添加身子
void Snake::addPoint(int x, int y)
{
    //创建新节点
    Point *pNew = new Point;
    pNew->x = x;
    pNew->y = y;
    pNew->pNext = NULL;

    //如果原先头结点不为空
    if (this->m_head != NULL)
    {
        //原来的头显示为身子=
        this->m_wall.setWall(this->m_head->x, this->m_head->y, '=');
        gotoxy(hOut,this->m_head->y*2, this->m_head->x);
        cout<<'=';
    }

    //将新节点显示为头@，将头结点指向新节点
    this->m_wall.setWall(x, y, '@');
    gotoxy(hOut, y*2,x);
    cout<<'@';
    pNew->pNext = this->m_head;
    this->m_head = pNew;
}

//销毁snake
void Snake::destorySnake()
{
    Point *pCurrent = this->m_head;
    while (pCurrent != NULL)
    {
        this->m_head = this->m_head->pNext;
        delete pCurrent;
        pCurrent = this->m_head;
    }
}

//删除尾节点
void Snake::deleteTailPoint()
{
    //两个节点以上才做删除操作
    if (this->m_head == NULL || this->m_head->pNext == NULL)
    {
        return;
    }

    Point *pCurrent = this->m_head->pNext;
    Point *pPrev = this->m_head;
    while (pCurrent->pNext != NULL)
    {
        pPrev = pCurrent;
        pCurrent = pCurrent->pNext;
    }

    //将尾节点所在位置设置成' '
    this->m_wall.setWall(pCurrent->x, pCurrent->y, ' ');
    gotoxy(hOut,  pCurrent->y*2,pCurrent->x);
    cout<<' ';

    delete pCurrent;
    pCurrent = NULL;
    pPrev->pNext = NULL;
}

//根据用户按下的键进行相应的移动
//返回值告诉外界是否移动成功，外界可以根据该bool值继续游戏或者是游戏结束
bool Snake::move(char key)
{
    int x = this->m_head->x;
    int y = this->m_head->y;

    switch (key)
    {
    case UP:
        x--;
        break;
    case DOWN:
        x++;
        break;
    case LEFT:
        y--;
        break;
    case RIGHT:
        y++;
        break;
    }

    //如果头下一步是尾巴，循环样，则不应该死亡
    Point *pCurrent = this->m_head->pNext;
    Point *pPrev = this->m_head;
    while (pCurrent->pNext != NULL)
    {
        pPrev = pCurrent;
        pCurrent = pCurrent->pNext;
    }
    if (x == pCurrent->x && y == pCurrent->y)
    {
        this->isLoop = true;
    }
    else
    {
        //snake头移动后的点为墙*或者为身子=，则返回false，移动失败
        if (this->m_wall.getWall(x, y) == '*' || this->m_wall.getWall(x, y) == '=')
        {
            //在死亡时再多走一步，即头到墙里面去
            addPoint(x, y);
            deleteTailPoint();
            //显示给用户
            system("cls");
            this->m_wall.drawWall();

            return false;
        }
    }

    //snake头移动后的点为食物#，则添加节点，返回true
    if (this->m_wall.getWall(x, y) == '#')
    {
        this->addPoint(x, y);

        //生成新食物
        this->m_food.setFood();
    }

    //snake头移动后的点为' '，则添加节点，删除尾部，返回true
    else
    {
        this->addPoint(x, y);
        this->deleteTailPoint();

        //如果是循环的话则将头重新绘制出来
        if (this->isLoop)
        {
            this->m_wall.setWall(x, y, '@');
            gotoxy(hOut, y*2, x);
            cout<<'@';  
        }
    }
    return true;
}

//获取身段长度
int Snake::getSize()
{
    int size = 0;
    Point* pCurrent = this->m_head;
    while (pCurrent!=NULL)
    {
        ++size;
        pCurrent= pCurrent->pNext;
    }

    return size;
}

 //获取SleepTime
int Snake::getSleepTime()
{
    int sleepTime = 300;
    if (this->getSize()>5 && this->getSize()<=10)
    {
        sleepTime=200;
    }
    if (this->getSize()>=10 )
    {
        sleepTime=100;
    }
    return sleepTime;
}

//获取分数
int Snake::getScore()
{
    int score = (this->getSize()-3)*100;//初始身段长为2，所以减去2
    return score;
}