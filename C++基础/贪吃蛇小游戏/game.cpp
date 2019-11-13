/*
 * @Author: Cement
 * @Date: 2019-11-12 17:59:57
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-13 21:49:43
 * @Description: 
 */
#include "wall.h"
#include "snake.h"
#include "food.h"
#include <conio.h>
#include <windows.h>

void test()
{
    Wall w;
    w.initWall();

    Food f(w);
    f.setFood();

    Snake s(w, f);

    s.initSnake();

    w.drawWall();
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
                    system("cls");
                    w.drawWall();
                    cout<<"Score: "<<s.getScore()<<endl;
                    Sleep(s.getSleepTime());
                }
                else
                {
                    isDead = true;
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