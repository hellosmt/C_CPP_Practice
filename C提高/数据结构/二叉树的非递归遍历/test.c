/*
 * @Author: Cement
 * @Date: 2019-10-29 18:14:07
 * @LastEditors: Cement
 * @LastEditTime: 2019-10-29 18:41:13
 * @Description: 二叉树的非递归遍历实现，用到顺序栈
 */
#include"SeqStack.h"
#include<stdbool.h>

//二叉树结点结构体
struct BiNode
{
    char data;
    struct BiNode* lchild;
    struct BiNode* rchild;
};

struct Info
{
    struct BiNode* node;
    bool flag;
};

struct Info* createInfo(struct BiNode* node)
{
    if (node==NULL)
    {
        return NULL;
    }
    struct Info* info = (struct Info*)malloc(sizeof(struct Info));
    info->node=node;
    info->flag = false;
    return info;
}

void noRecursion(struct BiNode* root)
{
    if (root==NULL)
    {
        return;
    }
    SeqStack s = Init_SeqStack();
    struct Info* info1 = createInfo(root);
    Push_SeqStack(s, info1);

    while (GetSize_SeqStack(s)!=0)
    {
        //获得栈顶元素
        struct Info* info=Top_SeqStack(s) ;
        if (info->flag)
        {
            printf("%c ",info->node->data);
            Pop_SeqStack(s);
            free(info);
            info=NULL;
            continue;
        }
        Pop_SeqStack(s);
        //将右结点压入栈
        Push_SeqStack(s, createInfo(info->node->rchild));
        //将左节点压入栈
        Push_SeqStack(s, createInfo(info->node->lchild));
        //修改flag
        info->flag = true;
        Push_SeqStack(s, info);
    }
    Destroy_SeqStack(s);
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
    noRecursion(&nodeA);
}

int main()
{
    test();
}