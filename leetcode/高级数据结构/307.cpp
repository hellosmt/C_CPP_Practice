/*
 * @Author: Cement
 * @Date: 2020-02-12 10:39:57
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-12 16:00:05
 * @Description: leetcode307，构建线段树
 */

#include <vector>
using std::vector;

// 构建线段树
void build_segement_tree(int pos, vector<int> &nums, vector<int> &values, int left, int right)
{
    if (left == right)
    {
        values[pos] = nums[left];
        return;
    }
    // 将[left, right]区间分为两半
    int mid = (left + right) / 2;
    // 构建左边的线段树
    build_segement_tree(pos * 2 + 1, nums, values, left, mid);
    // 构建右边的线段树
    build_segement_tree(pos * 2 + 2, nums, values, mid + 1, right);
    // 举例：区间[0,5]的元素和=[0,2]+[3,5],若某节点在values数组中坐标为i,则左孩子坐标为2*i+1，右孩子坐标为2*i+2
    values[pos] = values[pos * 2 + 1] + values[pos * 2 + 2];
}

// 更新线段树
void update_segment_tree(vector<int>& values, int pos, int left, int right, int index, int new_value)
{
    //  到叶子结点且是要更新的那个点
    if (left == right && left == index)
    {
        values[pos] = new_value;
        return;
    }

    int mid = (left + right) / 2;
    // index在左子树里面
    if (index <= mid)
    {
        update_segment_tree(values, pos * 2 + 1, left, mid, index, new_value);
    }
    // index在右子树里面
    else
    {
        update_segment_tree(values, pos * 2 + 2, mid + 1, right, index, new_value);
    }

    // 因为有点的值更新了，所以区间的值也要更新
    values[pos] = values[pos * 2 + 1] + values[pos * 2 + 2];
}

// 求和
// 当前线段的左端点left  右端点right
// 待求和区间的左端点qleft 右端点qright
int sum_range_segment_tree(vector<int> &values, int pos, int left, int right, int qleft, int qright)
{
    // 当前访问到的区间与查询区间没有交集，返回0
    if (right < qleft || left > qright)
    {
        return 0;
    }
    // 当前访问到的区间全部被覆盖在查询区间内，直接返回这个区间对应的区间和
    if (left >= qleft && right <= qright)
    {
        return values[pos];
    }

    // 当前访问到的区间与查询区间部分有交集，返回左子树的访问值和右子树的访问值
    int mid = (left + right) / 2;
    return sum_range_segment_tree(values, pos * 2 + 1, left, mid, qleft, qright) + sum_range_segment_tree(values, pos * 2 + 2, mid + 1, right, qleft, qright);
}

class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return;
        }

        int n = nums.size() * 4; // 线段树的长度一般为nums长度的4倍，肯定能装下
        for (int i = 0; i < n; i++)
        {
            this->values_.push_back(0); // 先全部初始化为0
        }

        this->right_end_ = nums.size() - 1; // 线段的右端点，即nums的长度-1

        build_segement_tree(0, nums, values_, 0, this->right_end_); // 构建线段树，即计算values_数组
    }

    void update(int i, int val)
    {
        update_segment_tree(this->values_, 0, 0, this->right_end_, i, val);
    }

    int sumRange(int i, int j)
    {
        return sum_range_segment_tree(this->values_, 0, 0, this->right_end_, i, j);
    }

private:
    vector<int> values_; // 存放线段树上每个节点的值，即线段树
    int right_end_;      // 线段的右端点
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */