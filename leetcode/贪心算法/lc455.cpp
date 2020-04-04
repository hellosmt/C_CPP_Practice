/*
 * @Author: Cement
 * @Date: 2020-02-15 23:04:44
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-15 23:08:44
 * @Description: 
 */

#include<vector>
#include<algorithm>
using std:: sort;
using std:: vector;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0 ;
        int j =0;
        int count=0;
        while (i < g.size() && j < s.size())
        {
            if (g[i] <= s[j])
            {
                count++;
                i++;
            }

            j++;
        }

        return count;
        
    }
};