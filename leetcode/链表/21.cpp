/*
 * @Author: Cement
 * @Date: 2020-02-13 22:22:27
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-13 22:31:40
 * @Description: 
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode new_head(0);
        ListNode* ptr =&new_head;

        while (l1&&l2)
        {
            if(l1->val<=l2->val)
            {
                ptr->next=l1;
                l1=l1->next;
            }
            else
            {
                ptr->next=l2;
                l2=l2->next;
            }
            ptr=ptr->next;
        }

        if (l1)
        {
            ptr->next=l1;
        }
        else
        {
            ptr->next=l2;
        }

        return new_head.next;
    }
};