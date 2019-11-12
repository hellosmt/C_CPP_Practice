/*
 * @Author: Cement
 * @Date: 2019-11-12 08:58:27
 * @LastEditors: Cement
 * @LastEditTime: 2019-11-12 16:08:25
 * @Description: 学校演讲比赛练习
 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <deque>
#include <ctime>
#include <numeric>
using namespace std;

//选手类
class Speaker
{

public:
    Speaker()
    {
    }

    Speaker(string name)
    {
        this->m_name = name;
        for (int i = 0; i < 3; i++)
        {
            this->m_score[i] = 0;
        }
    }

    string m_name;  //选手姓名
    int m_score[3]; //选手比赛得分
};

//比赛，评委打分
//1.第几轮  2.本轮比赛选手的编号  3.本轮比赛选手编号和选手  4.本轮晋级选手编号容器
void contest(int index, vector<int> &v1, map<int, Speaker> &m, vector<int> &v2)
{
    cout << "=============Round " << index << "===============" << endl;

    //设置随机数种子
    srand((unsigned int)time(NULL));

    ////临时容器用于存放小组成绩，key为分数，value为编号，按照分数从大到小存储
    multimap<int, int, greater<int>> group_m;

    int num = 0;
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        num++;
        deque<int> d;
        //十个评委随机打分
        for (int i = 0; i < 10; i++)
        {
            d.push_back(rand() % 100 + 1);
        }
        //排序
        sort(d.begin(), d.end());
        //去掉最低分
        d.pop_front();
        //去掉最高分
        d.pop_back();
        //计算平均分
        int sum = 0;
        sum = accumulate(d.begin(), d.end(), 0);
        int score = sum / d.size();

        //给该名选手设置本轮分数
        m[*it].m_score[index - 1] = score;

        //放入小组临时容器中
        group_m.insert(make_pair(score, *it));

        //每6个人选出三个晋级
        if (num % 6 == 0)
        {
            //打印小组比赛成绩
            cout << "group result:" << endl;

            for (multimap<int, int, greater<int>>::iterator it = group_m.begin(); it != group_m.end(); it++)
            {
                cout << "Number:" << it->second << " Name:" << m[it->second].m_name << " Score:" << it->first << endl;
            }

            //从小组容器中选出前三名的编号放入本轮晋级容器v2中
            int count = 0;
            for (multimap<int, int, greater<int>>::iterator it = group_m.begin(); it != group_m.end(), count < 3; it++, count++)
            {
                v2.push_back(it->second);
            }

            //清空小组临时容器
            group_m.clear();
        }
    }
}

/**
 * @description: 打印每轮比赛晋级结果
 * @param int index 第几轮比赛, map<int, Speaker> &m, vector<int>& v
 * @return: 
 */
void print_result(int index, map<int, Speaker> &m, vector<int> &v)
{
    cout << "            Round " << index << " Winner" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " " << m[*it].m_name << endl;
    }
}

/**
 * @description: 给编号抽签，打乱顺序
 * @param： vector<int>& v 比赛选手编号容器
 * @return: 
 */
void speaker_draw(vector<int> &v)
{
    random_shuffle(v.begin(), v.end());
}

void test()
{
    //所有编号放在vector v1中
    vector<int> v1;
    for (int i = 0; i < 24; i++)
    {
        v1.push_back(100 + i);
    }

    //创建24个选手
    map<int, Speaker> m;
    string name_seed = "ABCDEFGHIJKLMNOPQRSTUVWX";
    for (int i = 0; i < 24; i++)
    {
        string name = "Speaker_";
        name += name_seed[i];
        Speaker s = Speaker(name);
        m.insert(make_pair(i + 100, s));
    }

    //第一轮抽签
    speaker_draw(v1);

    //第一轮晋级选手编号容器
    vector<int> v2;

    //第一轮比赛
    contest(1, v1, m, v2);

    //打印第一轮晋级名单
    print_result(1, m, v2);

    //第二轮抽签
    speaker_draw(v2);

    //第二轮晋级选手编号容器
    vector<int> v3;

    //第二轮比赛
    contest(2, v2, m, v3);

    //打印第二轮晋级名单
    print_result(2, m, v3);

    //第三轮抽签
    speaker_draw(v3);

    //第三轮晋级选手编号容器
    vector<int> v4;

    //第三轮比赛
    contest(3, v3, m, v4);

    //打印第三轮晋级名单
    print_result(3, m, v4);
}

int main()
{
    test();
}