/*
 * @Author: Cement
 * @Date: 2020-03-06 16:39:08
 * @LastEditors: Cement
 * @LastEditTime: 2020-03-06 17:21:30
 * @Description: 快排 不稳定
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::swap;
using std::vector;

int partition1(vector<int>& arr, int beg, int end){
	int pivot = arr[beg];
	int l=beg+1, r=end;
	while(l<=r){
		if(arr[l]<pivot) l++;
		else if(arr[r]>pivot) r--;
		else if(arr[l]>=pivot && arr[r]<=pivot){
			swap(arr[l++], arr[r--]);
		}
	}
	swap(arr[r], arr[beg]);
	return r;
}
 
int partition2(vector<int>& arr, int beg, int end){
	int pivot = arr[beg];
	int index = beg+1;
	for(int i=index;i<=end;i++){
		if(arr[i]<pivot){
			swap(arr[i], arr[index++]);
		}
	}
	swap(arr[beg],arr[index-1]);
	return index-1;
}
 
void quick(vector<int>& arr, int beg, int end){
	if(beg<end){
		int pivot = partition1(arr,beg,end);
		// int pivot = partition2(arr,beg,end);
		quick(arr, beg, pivot-1);
		quick(arr, pivot+1, end);
	}
 
}

int main()
{
    vector<int> arr{5, 4, 7, 2, 6, 11, 9, 8, 7, 84};

    quick(arr, 0, arr.size() - 1);

    for (auto i = arr.begin(); i != arr.end(); i++)
    {
        cout << *i << endl;
    }
}