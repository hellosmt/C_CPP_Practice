/*
 * @Author: Cement
 * @Date: 2020-02-15 23:21:15
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-16 11:33:22
 * @Description: 查 没有想到的点：递增和递减都是取得最后一个，状态的转换意味着长度可以增加
 */

#include<vector>
#include<stack>
using std::stack;
using std::vector;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size()<2)
        {
            return nums.size();
        }

        static const int BEGIN = 0;
        static const int UP =1;
        static const int DOWN =2;
        int state = BEGIN;
        int max_length = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            switch (state)
            {
            case BEGIN:
                if (nums[i]>nums[i-1])
                {
                    max_length++;
                    state =UP;
                }
                else if(nums[i] < nums[i-1])
                {
                    max_length++;
                    state=DOWN;
                }
                break;
                
            case UP:
                if (nums[i] < nums[i-1])
                {
                    max_length++;
                    state=DOWN;
                }
                break;

            case DOWN:
                if (nums[i] > nums[i-1])
                {
                    max_length++;
                    state=UP;
                }
                break;
            default:
                break;
            }
        }
        return max_length;
        
    }
};