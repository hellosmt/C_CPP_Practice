/*
 * @Author: Cement
 * @Date: 2019-10-30 08:20:24
 * @LastEditors: Cement
 * @LastEditTime: 2019-10-30 08:55:37
 * @Description: 插入排序实现
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void InsertSort(int nums[], int len)
{
    if (len <= 0)
    {
        return;
    }
    for (int i = 1; i < len; i++)
    {
        int *pCurrent = &nums[i];
        int temp = nums[i];
        //判断前面是不是比我大且我没有比到数组头（前面排好序的所有数都比我大）
        while (*(pCurrent - 1) > temp && pCurrent != nums)
        {
            //前面比我大的一个个往后挪
            *pCurrent = *(pCurrent - 1);
            pCurrent--;
        }
        *pCurrent = temp;
    }
}

int main()
{
    int nums[] = {2, 5, 4, 7, 10, 78, 45, 98, 100, 47, 32, 1};
    int len = sizeof(nums) / sizeof(int);
    InsertSort(nums, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", nums[i]);
    }

    return EXIT_SUCCESS;
}
