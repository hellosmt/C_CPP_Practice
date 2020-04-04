/*
 * @Author: Cement
 * @Date: 2020-03-06 17:35:47
 * @LastEditors: Cement
 * @LastEditTime: 2020-03-06 19:37:22
 * @Description:插入排序 把当前
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::swap;
using std::vector;

void insert_sort(vector<int>& arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int tmp = arr[i];
        int j = i-1;
        for (; j>=0 && tmp < arr[j] ; --j)
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = tmp;
    }
}


int main()
{
    vector<int> arr{5, 4, 7, 2, 6, 11, 9, 8, 7, 84};

    insert_sort(arr);

    for (auto i = arr.begin(); i != arr.end(); i++)
    {
        cout << *i <<  " ";
    }
}