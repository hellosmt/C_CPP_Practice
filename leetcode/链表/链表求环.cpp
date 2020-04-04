/*
 * @Author: Cement
 * @Date: 2020-03-11 23:42:00
 * @LastEditors: Cement
 * @LastEditTime: 2020-03-12 00:04:27
 * @Description: 
 */

#include<iostream>
using std::cout;
using std::endl;
// 链表节点结构体
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};


ListNode* detectCycle(ListNode* head)
{
    if(head == nullptr)
    {
        return nullptr;
    }
    // 快慢指针
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast)
    {
        // 快指针先走一步
        fast = fast->next;
        
        if(fast==nullptr)
        {
            return nullptr;
        }
        // 快指针再走一步
        fast = fast->next;
        // 慢指针走一步
        slow = slow->next;

        // 快慢指针相遇表示有 环，求起始环节点
        if(fast==slow)
        {
            ListNode* tmp = head;
            while(tmp!=fast)
            {
                tmp = tmp->next;
                fast = fast->next;
            }
            return tmp;
        }
    }

    // 退出循环说明没有环
    return nullptr;
}

int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);
    ListNode g(7);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &c;

    ListNode* res = detectCycle(&a);
    if(res == nullptr)
    {
        cout<<"链表无环"<<endl;
    }
    else
    {
        cout<<res->val<<endl;
    }
    
    return 1;

}