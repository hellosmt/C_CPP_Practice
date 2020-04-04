/*
 * @Author: Cement
 * @Date: 2020-02-14 10:17:33
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-14 10:28:53
 * @Description: 
 */
#include<vector>
#include<stack>

using std::stack;
using std::vector;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j = 0;
        for (int i = 0; i < pushed.size(); i++)
        {
            s.push(pushed[i]);

            while (!s.empty() && popped[j] == s.top())
            {
                s.pop();
                j++;
            }
        }

        if (s.empty())
        {
            return true;
        }
        
        return false;
    }
};