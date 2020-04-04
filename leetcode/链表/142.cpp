/*
 * @Author: Cement
 * @Date: 2020-02-13 21:05:30
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-13 22:47:52
 * @Description: 查
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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *meet = nullptr;

        while (fast)
        {
            // 各走一步
            slow = slow->next;
            fast = fast->next;
            if (fast)
            {
                fast = fast->next;
            }
            else
            {
                return nullptr;
            }

            if (fast == slow)
            {
                meet = fast;
                break;
            }
        }

        if (!meet)
        {
            return nullptr;
        }

        while (meet != head)
        {
            meet = meet->next;
            head = head->next;
        }

        return meet;
    }
};