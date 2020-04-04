/*
 * @Author: Cement
 * @Date: 2020-02-16 10:59:14
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-16 11:33:57
 * @Description: 查 没有想到的点：全部
 */

#include <string>
#include<vector>
using std::vector;
using std::string;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int> s;
        string result = "";

        for (int i = 0; i < num.length(); i++)
        {
            int number = num[i] - '0';
            while (s.size() !=0 && k>0 && s[s.size() - 1] > number)
            {
                s.pop_back();
                k--;
            }

            if (number!=0 || s.size() != 0)
            {
                s.push_back(number);
            }
        }

        while (s.size() != 0 && k)
        {
            s.pop_back();
            k--;
        }
        
        for (int  i = 0; i < s.size(); i++)
        {
            result.append(1, '0'+s[i]);   // 在字符串末尾添加num个字符
        }
        
        if (result ==  "")
        {
            result = "0";
        }
        
        
        return  result;
    }
};