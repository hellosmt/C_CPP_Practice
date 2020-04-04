/*
 * @Author: Cement
 * @Date: 2020-02-28 00:37:08
 * @LastEditors: Cement
 * @LastEditTime: 2020-02-28 01:21:06
 * @Description: 
 */
#include<vector>
#include<iostream>
#include<string>

using std::vector;
using std::string;
using std::cout;

void generate(int left, int right, vector<string>& result, int n, string tmp)
{
    if (left==right&&left==n)
    {
        result.push_back(tmp);
        return;
    }

    if (left>n || right>n || left<right)
    {
        return;
    }
    generate(left+1, right, result, n, tmp+'(');
    generate(left, right+1, result, n, tmp+')');
}

vector<string> generateParenthesis(int n) {
    string tmp="";
    vector<string> result;
    generate(0, 0, result, n, tmp);
    return result;
}



int main()
{
    vector<string> result = generateParenthesis(2);
    cout<<result.size();
    return 1;
}