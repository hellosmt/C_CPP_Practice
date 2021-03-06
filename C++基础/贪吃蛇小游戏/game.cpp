/*
 * @Author: Cement
 * @Date: 2019-11-12 17:59:57
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-13 23:14:00
 * @Description: 
 */
#include "wall.h"
#include "snake.h"
#include "food.h"
#include <conio.h>
#include <windows.h>



//定位光标，不用清屏
//坐标系是反的
void gotoxy2(HANDLE hOut, int x, int y)
{
	COORD pos;
	pos.X = x;             //横坐标
	pos.Y = y;            //纵坐标
	SetConsoleCursorPosition(hOut, pos);
}
HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量


void test()
{
    Wall w;
    w.initWall();
    w.drawWall();


    Food f(w);
    f.setFood();

    Snake s(w, f);

    s.initSnake();

    gotoxy2(hOut2, 0, w.ROW);
    cout<<"Score: "<<s.getScore()<<endl;

    //记录一个是否死亡的状态变量
    bool isDead = false;

    //上一个按键值
    char preKey = (char)NULL;

    //接收用户输入
    while (!isDead)
    {
        char key = _getch();

        //第一次按键是向左时无效
        if (key == Snake::LEFT && preKey == (char)NULL)
        {
            continue;
        }

        do
        {
            //当本次按键为上下左右时才进入逻辑判断，其它按键一律强制变成上一次的按键值
            if (key == Snake::UP || key == Snake::DOWN || key == Snake::LEFT || key == Snake::RIGHT)
            {
                //本次与上次按键为冲突按键,则snake移动方向不变
                if ((key == Snake::UP && preKey == Snake::DOWN) ||
                    (key == Snake::DOWN && preKey == Snake::UP) ||
                    (key == Snake::LEFT && preKey == Snake::RIGHT) ||
                    (key == Snake::RIGHT && preKey == Snake::LEFT))
                {
                    key = preKey;
                }
                else
                {
                    preKey = key; //不是冲突按键，则可以更新按键
                }

                if (s.move(key) == true)
                {
                    //移动成功代码
                    //清屏
                    //system("cls");
                    //w.drawWall();
                    gotoxy2(hOut2, 0, w.ROW);
                    cout<<"Score: "<<s.getScore()<<endl;
                    Sleep(s.getSleepTime());
                }
                else
                {
                    isDead = true;
                    gotoxy2(hOut2, 0, w.ROW);
                    cout<<"Score: "<<s.getScore()<<endl;
                    cout << "GAME OVER!" << endl;
                    break;
                }
            }
            else
            {
                key = preKey;
            }

        } while (!_kbhit()); //_kbhit()当没有键盘输入时返回0
    }
}

int main()
{
    test();
    system("pause");
}