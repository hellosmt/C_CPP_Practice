/*
 * @Author: Cement
 * @Date: 2020-02-13 21:39:20
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-13 22:47:12
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
    ListNode *partition(ListNode *head, int x)
    {
        if (!head)
        {
            return head;
        }

        ListNode less_head(0);
        ListNode more_head(0);
        ListNode *less_ptr = &less_head;
        ListNode *more_ptr = &more_head;

        while (head)
        {
            if (head->val < x)
            {
                less_ptr->next = head;
                less_ptr = less_ptr->next;
            }
            else
            {
                more_ptr->next = head;
                more_ptr = more_ptr->next;
            }
            head = head->next;
        }

        less_ptr->next = more_head.next;
        more_ptr->next = nullptr; // 这一句忘了
        return less_head.next;
    }
};