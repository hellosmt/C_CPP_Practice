/*
 * @Author: Cement
 * @Date: 2020-03-08 16:49:56
 * @LastEditors: Cement
 * @LastEditTime: 2020-03-13 12:49:35
 * @Description: 堆排序
 */

#include <vector>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::swap;
using std::vector;

// i为要调整的树的根节点下标
void adjust(vector<int> &arr, const int size, const int root)
{
    // 判断是否越界
    if (root >= size || root < 0)
    {
        return;
    }

    int l = 2 * root + 1, r = 2 * root + 2; //  左右孩子的下标

    //寻找三者中的最大值,maxI记录最大值的下标
    int maxI = root;
    if (l < size && arr[l] > arr[maxI]) // 第一个条件判断看是否越界
        maxI = l; 
    if (r < size && arr[r] > arr[maxI]) // 第一个条件判断看是否越界
        maxI = r; 

    if (maxI != root) // 表示有孩子比这个根节点大，则进行交换
    {
        swap(arr[root], arr[maxI]);
        // 递归调整孩子
        adjust(arr,  size,  maxI);
    }
}

void heap_sort(vector<int> &arr)
{
    int size = arr.size();
    if (size < 2)
    {
        return;
    }
    // 从最后一个节点的父节点开始作为一颗树调整为最大堆，依次遍历每一个为父节点的节点
    for (int i = size/2-1 ; i >= 0; i--)
    {
        adjust(arr, size, i);
    }

    // 上面构建大顶堆完成，下面开始进行堆排序
    // 把大顶堆的堆顶元素和最后一个元素交换（则最大元素放在了数组末尾）
    // 调整前[0，n-1]个元素使其再次成为一颗大顶堆，循环交换与调整步骤
    for (int i = size - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        adjust(arr, i, 0);
    }
    
}

int main()
{
    vector<int> arr{8,4,7,1,0,2,6,9};
    heap_sort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }   
}