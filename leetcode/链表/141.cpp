/*
 * @Author: Cement
 * @Date: 2020-02-13 16:55:27
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-13 17:09:31
 * @Description: 环形链表
 */

#include <set>

using std::set;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle1(ListNode *head)
    {
        if (!head)
        {
            return false;
        }
        set<ListNode*> s;
        while (head)
        {
            if (s.find(head) != s.end())
            {
                return true;
            }
            s.insert(head);
            head = head->next;
        }

        return false;
    }

    // 常量内存O(1)
    bool hasCycle2(ListNode *head)
    {
        if (!head)
        {
            return false;
        }

        ListNode* low = head;
        ListNode* fast = head->next;
        while (low && fast)
        {
            if (low == fast)
            {
                return true;
            }
            low = low->next;
            fast = fast->next->next;
        }
        return false;
    }
};