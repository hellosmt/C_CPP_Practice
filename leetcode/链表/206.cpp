/*
 * @Author: Cement
 * @Date: 2020-02-13 14:51:17
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-13 22:48:09
 * @Description: leetcode206-链表逆序-a  查
 */


struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){};
};

class Solution
{
private:
    /* data */
public:
    ListNode* reverseList(ListNode* head)
    {
        // 错 自己写的时候没有给指针赋值，野指针
        ListNode* new_head = nullptr;
        while (head)
        {
            ListNode* ptr = head->next;
            head->next = new_head;
            new_head  = head;
            head = ptr;
        }

        return new_head;
    }
};

