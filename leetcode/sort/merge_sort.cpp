/*
 * @Author: Cement
 * @Date: 2020-03-06 19:37:31
 * @LastEditors: Cement
 * @LastEditTime: 2020-03-06 20:30:51
 * @Description: 归并排序
 */
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::swap;
using std::vector;

void merge(const vector<int> &a, const vector<int> &b, vector<int>& res)
{
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size())
    {
        if(a[i]<=b[j])
        {
            res.push_back(a[i]);
            i++;
        }
        else
        {
            res.push_back(b[j]);
            j++;
        }
    }

    if (i==a.size())
    {
        while (j<b.size())
        {
            res.push_back(b[j]);
            ++j;
        }
    }
    
    else
    {
        while(i<a.size())
        {
            res.push_back(a[i]);
            ++i;
        }
    }

}

void merge_sort( vector<int>& arr)
{
    if (arr.size() < 2)
    {
        return ;
    }
    int mid = arr.size() / 2;
    vector<int> a(arr.begin(), arr.begin()+mid);
    vector<int> b(arr.begin()+mid, arr.end());

    merge_sort(a);
    merge_sort(b);
    arr.clear();
    merge(a, b, arr);
}

int main()
{
    vector<int> arr{5, 4, 7, 2, 6, 11, 9, 8, 7, 84};

    merge_sort(arr);

    for (auto i = arr.begin(); i != arr.end(); i++)
    {
        cout << *i <<  " ";
    }
}