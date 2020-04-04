/*
 * @Author: Cement
 * @Date: 2020-02-14 09:54:51
 * @LastEditors: Cement
 * @LastEditTime: 2020-03-06 12:41:17
 * @Description: 查，没有立马想出来
 */
#include <stack>
using std::stack;
class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        data_.push(x);
        if (state_.empty() || x <= state_.top())
        {
            state_.push(x);
        }
        else
        {
            state_.push(state_.top());
        }
    }

    void pop()
    {
        data_.pop();
        state_.pop();
    }

    int top()
    {
        return data_.top();
    }

    int getMin()
    {
        return state_.top();
    }

private:
    stack<int> data_;
    stack<int> state_;
};

    void page_fault_test()
    {
        vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
        int block_num = 3;
        pair<int, int> result = fifo_test(pages, block_num);
        cout<< "缺页次数 ："<<result.first<<endl<<"置换次数为："<<result.second;
    }    

    pair<int, int> fifo_test(const vector<int>& pages, const int block_num)
    {
        if (pages.size()==0 || block_num==0)
        {
            return pair<int,int>(-1,-1);
        }
        
        set<int> sorted;
        int fault_count = 0;
        int exchange = 0;
        queue<int> q;
        for (int i = 0; i < pages.size(); i++)
        {
            //发生缺页
            if (sorted.find(pages[i])==sorted.end())
            {
                fault_count++;
                // 满了需要置换
                if (q.size()>=block_num)
                {
                    // 弹出前面第一个
                    q.pop();
                    exchange++;
                    
                }
                q.push(pages[i]); 
            }
        }
        return pair<int, int>(fault_count,exchange);
        
    }

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */