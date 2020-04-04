/*
 * @Author: Cement
 * @Date: 2020-02-24 17:45:55
 * @LastEditors: Cement
 * @LastEditTime: 2020-02-24 17:55:12
 * @Description: 
 */
#include <iostream>

using std::cout;
using std::endl;

namespace tt01
{
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

void PreOrder(TreeNode* root)
{
    if (!root)
    {
        return ;
    }
    cout<<root->data<<endl;
    PreOrder(root->left);
    PreOrder(root->right);
    
}

void test1()
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    a.left=&b;
    a.right=&c;
    b.left=&d;
    d.right=&e;
    c.right=&f;
    PreOrder(&a);
} 
} // namespace tt01

int main()
{
    tt01::test1();
}