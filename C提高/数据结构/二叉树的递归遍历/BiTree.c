/*
 * @Author: Cement
 * @Date: 2019-10-29 15:05:10
 * @LastEditors: Cement
 * @LastEditTime: 2019-10-29 15:28:33
 * @Description: 二叉树的递归遍历简单实现
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//二叉树结点结构体
struct BiNode
{
    char data;
    struct BiNode* lchild;
    struct BiNode* rchild;
};

//先序遍历
void recursion(struct BiNode* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c ", root->data);
    //递归遍历左子树
    recursion(root->lchild);
    //递归遍历右子树
    recursion(root->rchild);
}


void test()
{
    struct BiNode nodeA={'A', NULL,NULL};
    struct BiNode nodeB={'B', NULL,NULL};
    struct BiNode nodeC={'C', NULL,NULL};
    struct BiNode nodeD={'D', NULL,NULL};
    struct BiNode nodeE={'E', NULL,NULL};
    struct BiNode nodeF={'F', NULL,NULL};
    struct BiNode nodeG={'G', NULL,NULL};
    struct BiNode nodeH={'H', NULL,NULL};

    nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeF;

	nodeB.rchild = &nodeC;
	
	nodeC.lchild = &nodeD;
	nodeC.rchild = &nodeE;

	nodeF.rchild = &nodeG;

	nodeG.lchild = &nodeH;
    recursion(&nodeA);
}

int main()
{
    test();
}