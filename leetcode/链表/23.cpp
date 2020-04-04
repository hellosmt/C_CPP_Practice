/*
 * @Author: Cement
 * @Date: 2020-02-13 22:35:12
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-13 22:52:59
 * @Description: 查 分治思想，合并k个已排序的链表，除暴力求解外还有两种方法，我只想到分治,且得有lc21的前提
 */

#include <vector>
using std::vector;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
        {
            return nullptr;
        }
        
        if (lists.size() == 2)
        {
            return mergeTwoLists(lists[0], lists[1]);
        }

        if (lists.size() == 1)
        {
            return lists[0];
        }

        int mid = lists.size() / 2;

        vector<ListNode *> left_lists;
        vector<ListNode *> right_lists;

        for (int i = 0; i < mid; i++)
        {
            left_lists.push_back(lists[i]);
        }
        for (int i = mid ; i < lists.size(); i++)
        {
            right_lists.push_back(lists[i]);
        }

        return mergeTwoLists(mergeKLists(left_lists), mergeKLists(right_lists));
    }

private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode new_head(0);
        ListNode *ptr = &new_head;

        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                ptr->next = l1;
                l1 = l1->next;
            }
            else
            {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }

        if (l1)
        {
            ptr->next = l1;
        }
        else
        {
            ptr->next = l2;
        }

        return new_head.next;
    }
};