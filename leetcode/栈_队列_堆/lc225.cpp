/*
 * @Author: Cement
 * @Date: 2020-02-14 09:19:52
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-14 09:35:04
 * @Description: 
 */

#include<queue>
using std::queue;

class MyStack
{
public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        queue<int> temp_queue;
        temp_queue.push(x);
        while (!data_queue_.empty())
        {
            temp_queue.push(data_queue_.front());
            data_queue_.pop();
        }

        while (!temp_queue.empty())
        {
            data_queue_.push(temp_queue.front());
            temp_queue.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int x = data_queue_.front();
        data_queue_.pop();
        return x;
    }

    /** Get the top element. */
    int top()
    {
        return data_queue_.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return data_queue_.empty();
    }

private:
    queue<int> data_queue_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */