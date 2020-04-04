/*
 * @Author: Cement
 * @Date: 2020-02-13 22:04:12
 * @LastEditors  : Cement
 * @LastEditTime : 2020-02-13 22:47:25
 * @Description: 查
 */

#include <vector>
#include <map>

using std::map;
using std::vector;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        int i = 0;
        vector<Node *> node_vec;
        map<Node *, int> node_map;
        Node *ptr = head;

        while (ptr)
        {
            node_vec.push_back(new Node(ptr->val));
            node_map[ptr] = i;
            ptr = ptr->next;
            i++;
        }

        ptr = head;

        node_vec.push_back(0); // 这一步忘了，为最后一个节点的next着想

        for (int i = 0; i < node_vec.size() - 1; i++)
        {
            node_vec[i]->next = node_vec[i + 1];   // 前面不push0，这里i+1就会越界
            if (ptr->random)
            {
                int random_pos = node_map[ptr->random];
                node_vec[i]->random = node_vec[random_pos];
            }
            ptr = ptr->next;
        }

        return node_vec[0];
    }
};