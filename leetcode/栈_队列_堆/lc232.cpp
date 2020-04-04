/*
 * @Author: Cement
 * @Date: 2020-02-14 09:35:55
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-14 09:44:46
 * @Description: 
 */
#include<stack>
using std::stack;

class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        stack<int> temp_stack;
        while (!data_stack_.empty())
        {
            temp_stack.push(data_stack_.top());
            data_stack_.pop();
        }

        data_stack_.push(x);
        while (!temp_stack.empty())
        {
            data_stack_.push(temp_stack.top());
            temp_stack.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int x = data_stack_.top();
        data_stack_.pop();
        return x;
    }

    /** Get the front element. */
    int peek()
    {
        return data_stack_.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return data_stack_.empty();
    }

private:
    stack<int> data_stack_;

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */