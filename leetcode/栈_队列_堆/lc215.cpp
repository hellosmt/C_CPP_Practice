/*
 * @Author: Cement
 * @Date: 2020-02-14 10:31:23
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-14 10:56:31
 * @Description: 查 没想到啊没想到，我想的竟然是先 去重再用堆
 */
#include<vector>
#include<queue>
#include<algorithm>

using std::priority_queue;
using std::vector;
using std::greater;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> small_heap;

        for (int i = 0; i < nums.size(); i++)
        {
            if (small_heap.size() < k)
            {
                small_heap.push(nums[i]);
            }

            else
            {
                if (small_heap.top()<nums[i])
                {
                    small_heap.pop();
                    small_heap.push(nums[i]);
                }   
            }
        }

        return small_heap.top();
    }
};