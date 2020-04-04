/*
 * @Author: Cement
 * @Date: 2020-02-12 16:01:48
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-12 16:50:42
 * @Description: leetcode547-朋友圈，使用并查集
 */

#include<vector>
using std::vector;

class DisjointSet
{
public:
    DisjointSet(int n): count_(n)
    {
        for(int i = 0 ; i < n; i++)
        {
            this->id_.push_back(i);  // 初始时每个元素各成一个集合，其父节点编号即为自己
            this->size_.push_back(1);      // 初始时每个元素各成一个集合，集合个数为1
        }
    }

    // 将元素i和元素j合并
    void Union(int i , int j)
    {
        if (i >= id_.size() || j >= id_.size())
        {
            return;
        }
        
        int set_i = Find(i);
        int set_j = Find(j);

        // i j已经在一个集合中，直接返回
        if ( set_i == set_j)
        {
            return;
        }

        // 将小的挂在大的树上面，使树尽量维持平衡
        if (this->size_[set_i] < this->size_[set_j])
        {
            this->id_[set_i] = set_j;
            // 大树新的size要加上小树的size
            this->size_[set_j] += this->size_[set_i];
        }
        else
        {
            this->id_[set_j] = set_i;
            this->size_[set_i] += this->size_[set_j];
        }

        this->count_--;
    }

    // 查找元素i
    int Find(int i) const
    {
        while (i != this->id_[i])
        {
            i =  this->id_[this->id_[i]];
        }
        
        return i;
    }

    int get_count() const
    {
        return this->count_;
    }

private:
    vector<int> id_;  // 存储元素i的父节点编号
    vector<int> size_;  // 元素i的孩子个数
    int count_;  // 集合的个数
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.size() == 0)
        {
            return 0;
        }
        DisjointSet s(M.size());
        for (int i = 0; i < M.size(); i++)
        {
            for(int j = i+1 ; j <M.size(); j++)
            {
                // i和j是朋友
                if (M[i][j])
                {
                    s.Union(i,j);
                }
            }
        }
        return s.get_count();
    }
};