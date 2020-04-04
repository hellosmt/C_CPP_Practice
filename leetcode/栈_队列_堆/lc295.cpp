/*
 * @Author: Cement
 * @Date: 2020-02-14 11:08:26
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-14 11:52:43
 * @Description: 查
 */
#include <vector>
#include <queue>
#include <algorithm>

using std::greater;
using std::less;
using std::priority_queue;
using std::vector;

class MedianFinder
{
public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (small_heap.empty())
        {
            small_heap.push(num);
            return;
        }
        if (small_heap.size() == big_heap.size())
        {
            if (num < big_heap.top())
            {
                big_heap.push(num);
            }
            else
            {
                small_heap.push(num);
            }
        }

        else if (small_heap.size() > big_heap.size())
        {
            if (num<small_heap.top())
            {
                big_heap.push(num);
            }
            else
            {
                big_heap.push(small_heap.top());
                small_heap.pop();
                small_heap.push(num);
            }
        }
        
        else if (small_heap.size() < big_heap.size())
        {
            if (num > big_heap.top())
            {
                small_heap.push(num);
            }
            else
            {
                small_heap.push(big_heap.top());
                big_heap.pop();
                big_heap.push(num);
            }
        }
        
        // if (num >= small_heap.top())
        // {
        //     if (small_heap.size() > big_heap.size())
        //     {
        //         big_heap.push(small_heap.top());
        //         small_heap.pop();
        //     }
        //     small_heap.push(num);
        // }
        // else if( num <= big_heap.top())
        // {
        //     if (big_heap.size() > small_heap.size())
        //     {
        //         small_heap.push(big_heap.top());
        //         big_heap.pop();
        //     }

        //     big_heap.push(num);
        // }

        // else if(big_heap.top() < num < small_heap.top())
        // {
        //     if (big_heap.size() <= small_heap.size())
        //     {
        //         big_heap.push(num);
        //     }
        //     else
        //     {
        //         small_heap.push(num);
        //     }
        // }
    }

    double findMedian()
    {
        if (big_heap.size() > small_heap.size())
        {
            return big_heap.top();
        }
        else if (big_heap.size() < small_heap.size())
        {
            return small_heap.top();
        }

        return (small_heap.top() + big_heap.top()) / 2.0;
    }

private:
    priority_queue<int> big_heap;
    priority_queue<int, vector<int>, greater<int>> small_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */