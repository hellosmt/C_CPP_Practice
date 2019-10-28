/*
 * @Author: sunmengtuo
 * @Date: 2019-10-25 15:40:02
 * @LastEditTime: 2019-10-26 14:51:25
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \CODE\C-CPP\C提高\数据结构\动态数组\test.c
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct DynamicArray
{
    void **arr;
    int capacity;
    int size;
};

//初始化
int Init_DynamicArray(struct DynamicArray *array, int capacity)
{
    if (capacity < 0)
    {
        return -1;
    }
    array = (struct DynamicArray *)malloc(sizeof(struct DynamicArray));
    array->capacity = capacity;
    array->size = 0;
    array->arr = (void **)malloc(sizeof(void *) * capacity);
}

//插入数据
void Insert_DynamicArray(struct DynamicArray *array, int pos, void *data)
{
    if (array == NULL || data == NULL)
    {
        return;
    }

    if (pos < 0 || pos > array->size)
    {
        pos = array->size;
    }

    //数组大小超出容量
    if (array->size >= array->capacity)
    {
        int newCapacity = array->capacity * 2;
        void **newArr = (void **)malloc(sizeof(void *) * newCapacity);
        memcpy(newArr, array->arr, sizeof(void *) * array->size);
        free(array->arr);
        array->arr = newArr;
        array->capacity = newCapacity;
    }
    //最后一个开始往后挪，腾出pos位置
    for (int i = array->size - 1; i >= pos; i--)
    {
        array->arr[i + 1] = array->arr[i];
    }
    array->arr[pos] = data;

    array->size++;
}

//遍历
void Foreach_DynamicArray(struct DynamicArray *array, void (*_callback)(void *))
{
    if (array == NULL)
    {
        return;
    }
    if (_callback == NULL)
    {
        return;
    }
    for (int i = 0; i < array->size; i++)
    {
        _callback(array->arr[i]);
    }
}

//删除指定位置元素
void DeleteByPos_DynamicArray(struct DynamicArray *array, int pos)
{
    if (array == NULL || pos < 0 || pos > array->size - 1)
    {
        return;
    }
    //后一个覆盖前一个元素
    for (int i = pos; i < array->size; ++i)
    {
        array->arr[i] = array->arr[i + 1];
    }
    --array->size;
}

//根据值来删除元素,我们是不知道客户具体存放的是什么数据类型，所以需要客户自己提供回调函数来告诉我们两个元素是否相等
void DeleteByValue_DynamicArray(struct DynamicArray *array, void *data, int (*_compare)(void *, void *))
{
    if (NULL == array || NULL == data || NULL == _compare)
    {
        return;
    }
    for (int i = 0; i < array->size; ++i)
    {
        //判断是否是要删除的元素
        if (_compare(array->arr[i], data))
        {
            DeleteByPos_DynamicArray(array, i);
            break;
        }
    }
}

//销毁
void Destroy_DynamicArray(struct DynamicArray *array)
{
    if (NULL == array)
    {
        return;
    }
    if (array->arr != NULL)
    {
        free(array->arr);
        array->arr = NULL;
    }
    free(array);
    array = NULL;
}

struct Person
{
    char name[20];
    int age;
};

void myPrint(void *data)
{
    struct Person *p = (struct Person *)data;
    printf("%s:%d\n", p->name, p->age);
}

int myCompare(void *data1, void *data2)
{
    struct Person *p1 = (struct Person *)data1;
    struct Person *p2 = (struct Person *)data2;
    return strcmp(p1->name, p1->name) == 0 && p1->age == p2->age;
}

int main()
{
    struct DynamicArray array;
    Init_DynamicArray(&array, 5);

    struct Person p1 = {"aaa", 20};
    struct Person p2 = {"bbb", 18};
    struct Person p3 = {"ccc", 25};
    struct Person p4 = {"ddd", 30};
    struct Person p5 = {"eee", 90};
    struct Person p6 = {"fff", 80};
    Insert_DynamicArray(&array, 0, &p1);
    Insert_DynamicArray(&array, 1, &p2);
    Insert_DynamicArray(&array, 2, &p3);
    Insert_DynamicArray(&array, 3, &p4);

    Foreach_DynamicArray(&array, myPrint);
    printf("=====================\n");
    Insert_DynamicArray(&array, 0, &p5);
    Foreach_DynamicArray(&array, myPrint);
    printf("=====================\n");
    Insert_DynamicArray(&array, 3, &p6);
    Foreach_DynamicArray(&array, myPrint);

    DeleteByPos_DynamicArray(&array, 2);
    printf("=====================\n");
    Foreach_DynamicArray(&array, myPrint);

    DeleteByValue_DynamicArray(&array, &p6, myCompare);
    printf("=====================\n");
    Foreach_DynamicArray(&array, myPrint);

    Destroy_DynamicArray(&array);
}