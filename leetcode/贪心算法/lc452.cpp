/*
 * @Author: Cement
 * @Date: 2020-02-16 13:49:12
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-16 14:04:21
 * @Description: 查 
 */

#include <vector>
#include <algorithm>
using std::sort;
using std::vector;

bool cmp(const vector<int> &p1, const vector<int> &p2)
{
    return p1[0] < p2[0];
}

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() <= 1)
        {
            return points.size();
        }
        
        sort(points.begin(), points.end(), cmp);

        int result = 1;
        int shoot_begin = points[0][0];
        int shoot_end = points[0][1];

        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] >= shoot_end)
            {
                result++;
                shoot_begin = points[i][0];
                shoot_end = points[i][1];
            }
            
            else
            {
                shoot_begin = points[i][0];
                shoot_end = shoot_end < points[i][1] ? shoot_end : points[i][1];
            }
        }
        return result;
    }
};