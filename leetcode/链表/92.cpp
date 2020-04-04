/*
 * @Author: Cement
 * @Date: 2020-02-13 15:16:50
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-13 16:10:58
 * @Description: leetcode92-反转m-n的链表元素 没做出来（m=1的情况考虑不出来） 查
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        ListNode* result = head;
        ListNode* pre_head = nullptr;
        int count = m-n+1;
        // head变为m号节点
        while (head && --count)
        {
            pre_head = head;
            head = head->next;
        }
        ListNode* new_head = nullptr;
        ListNode* modify_list_tail = head;
        while (count)
        {
            ListNode* next = head->next;
            head->next  = new_head;
            new_head = head;
            head =  next;
            count--;
        }

        modify_list_tail->next = head;

        if(pre_head)
        {
            pre_head->next = new_head;
        }

        else
        {
            result = new_head;
        }
        
        return result;
    }
};