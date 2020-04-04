/*
 * @Author: Cement
 * @Date: 2020-02-13 16:16:30
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-13 16:40:44
 * @Description: 
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int  get_list_length(ListNode *head)
{
    int length = 0;
    while (head)
    {
        head  = head->next;
        length++;
    }

    return length;
}

ListNode* forward_long_list(ListNode* head, int length)
{
    while (head && length)
    {
        head =  head->next;
        length--;
    }
    return head;
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length_A = get_list_length(headA);
        int length_B = get_list_length(headB);

        if (length_A > length_B)
        {
            headA = forward_long_list(headA, length_A-length_B);
        }
        else if(length_A < length_B)
        {
            headB = forward_long_list(headB, length_B-length_A);
        }

        while (headA && headB)
        {
            if(headA == headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        
        return nullptr;
        
    }
};