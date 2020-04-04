/*
 * @Author: Cement
 * @Date: 2020-02-16 14:04:08
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-16 14:34:27
 * @Description: 查 没有想到的点：用最大堆来存储路上经过的加油站油量
 */

#include<vector>
#include<queue>
using std::vector;
using  std::priority_queue;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int result = 0;
        priority_queue<int> Q;
        vector<int> end;
        end.push_back(target);
        end.push_back(0);
        //stations.push_back(vector<int>(target, 0)); 这样写 不可以 这是放了target个0进去
        stations.push_back(vector<int>(end));
        
        for (int i = 0; i < stations.size(); i++)
        {
            int distance = 0;
            if (i == 0)
            {
                distance = stations[i][0];
            }
            
            else
            {
                distance = stations[i][0] - stations[i-1][0];
            }

            while (startFuel <  distance && !Q.empty())
            {
                startFuel += Q.top();
                result++;
                Q.pop();
            }
            if (Q.empty() && startFuel <  distance)
            {
                return -1;
            }
            startFuel -= distance;
            Q.push(stations[i][1]);
        }
        return result;
    }
};