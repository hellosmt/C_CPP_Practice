/*
 * @Author: Cement
 * @Date: 2020-03-06 17:44:58
 * @LastEditors: Cement
 * @LastEditTime: 2020-03-16 11:27:26
 * @Description: 选择排序，每次选择剩余数组中最小的那个放到前面
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::swap;
using std::vector;



void selection_sort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        // m为当前遍历到的最小值
        int m = arr[i];
        // index为 最小值的索引
        int index = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < m)
            {
                m = arr[j];
                index = j;
            }
        }
        swap(arr[index], arr[i]);
    }
}

#include<string>
using std::string;


int main()
{
    vector<int> arr{5, 4, 7, 2, 6, 11, 9, 8, 7, 84};

    selection_sort(arr);

    for (auto i = arr.begin(); i != arr.end(); i++)
    {
        cout << *i << " ";
    }
}