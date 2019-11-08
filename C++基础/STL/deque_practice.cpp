/*
 * @Author: Cement
 * @Date: 2019-11-08 21:59:05
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-08 23:25:00
 * @Description: STL中deque的小练习——评委打分
 */

/*
	有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
	//1. 创建五名选手，放到vector中
	//2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
	//3. sort算法对deque容器中分数排序，pop_back pop_front去除最高和最低分
	//4. deque容器遍历一遍，累加分数，累加分数/d.size()
	//5. person.score = 平均分
*/

#include <iostream>
#include <deque>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

class Player
{
public:
    Player(char name)
    {
        cout<<"constructor()"<<endl;
        this->m_score = 0;
        this->m_name = name;
    }

    Player(const Player& p)
    {
        cout<<"copy constructor()"<<endl;
        this->m_name = p.m_name;
        this->m_score = p.m_score;
    }

    void setScore(int score)
    {
        this->m_score = score;
    }

    int gerScore()
    {
        return this->m_score;
    }

    string getName()
    {
        return this->m_name;
    }

    ~Player()
    {
        cout<<"deconstructor()"<<endl;
    }

private:
    int m_score;
    string m_name;
};

void PrintPlayer(Player *p)
{
    cout << p->getName() << ":" << p->gerScore() << endl;
}

void test()
{
    //设置随机数种子
    srand((unsigned int)time(NULL));

    vector<Player *> v;
    //1.创建五名选手，放到vector中
    char name = 'A';
    for (int i = 0; i < 5; i++)
    {
        Player *p = new Player(name);
        v.push_back(p);
        name++;
    }

    //2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
    deque<int> d_scores;
    for (vector<Player *>::iterator it = v.begin(); it != v.end(); it++)
    {
        //是个评委打分，分数放入deque中
        for (int i = 0; i < 10; ++i)
        {
            //随机打分
            int score = rand() % 10 + 1;

            //放入deque
            d_scores.push_back(score);
        }

        //3. sort算法对deque容器中分数排序，pop_back pop_front去除最高和最低分
        sort(d_scores.begin(), d_scores.end()); //排序
        d_scores.pop_front();                   //去掉最低分
        d_scores.pop_back();                    //去掉最高分

        //4. deque容器遍历一遍，累加分数，累加分数/d.size()
        int score_total = 0; //总分
        for (deque<int>::iterator dit = d_scores.begin(); dit != d_scores.end(); ++dit)
        {
            score_total += (*dit); //累加
        }
        //设置分数
        (*it)->setScore(score_total / d_scores.size());
    }

    //遍历打印分数
    for (vector<Player *>::iterator it = v.begin(); it != v.end(); it++)
    {
        PrintPlayer(*it);
    }

    //释放对象
    for (vector<Player *>::iterator it = v.begin(); it != v.end(); it++)
    {
        delete *it;
    }
}

void CreatPerson(vector<Player>& v)
{
    Player p = Player('A');
    v.push_back(p); //如果p是开辟在栈上的，这里是会使用拷贝构造的！原先的p在这个函数退出时被销毁
    cout<<"========="<<endl;
}

void test1()
{
    
    vector<Player> v ;
    CreatPerson(v);
    cout<<"!!!!!!!!!"<<endl;
}

int main()
{
    test();
    //test1();
}
