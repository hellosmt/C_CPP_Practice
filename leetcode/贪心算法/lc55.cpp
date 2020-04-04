/*
 * @Author: Cement
 * @Date: 2020-02-16 11:31:50
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-16 11:46:27
 * @Description: 查 没有想到的点：当当前的index>能到达的最远index时就代表了不能跳
 */

#include <vector>
using std::vector;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        vector<int> max_index;

        for (int i = 0; i < nums.size(); i++)
        {
            max_index.push_back(i + nums[i]);
        }

        int jump = 0;
        int max = max_index[0];
        while (jump < nums.size() && jump <= max)
        {
            if (max < max_index[jump])
            {
                max = max_index[jump];
            }
            jump++;
        }
        if (jump == nums.size())
        {
            return true;
        }

        return false;
    }
};