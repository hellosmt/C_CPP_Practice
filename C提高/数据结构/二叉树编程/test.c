/*
 * @Author: Cement
 * @Date: 2019-10-29 15:29:13
 * @LastEditors: Cement
 * @LastEditTime: 2019-10-29 18:46:13
 * @Description: 统计叶子节点数目，计算二叉树高度， 二叉树拷贝与销毁
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//二叉树结点结构体
struct BiNode
{
    char data;
    struct BiNode *lchild;
    struct BiNode *rchild;
};

//统计叶子结点数目
//每次遍历的栈空间是独立的，不共享
void calculateLeafNum(struct BiNode *root, int *pNum)
{
    if (root == NULL)
    {
        return;
    }
    if (root->lchild == NULL && root->rchild == NULL)
    {
        ++(*pNum);
    }
    calculateLeafNum(root->lchild, pNum);
    calculateLeafNum(root->rchild, pNum);
}

//计算深度
int calculateDepth(struct BiNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lDepth = calculateDepth(root->lchild);
    int rDepth = calculateDepth(root->rchild);
    return lDepth > rDepth ? lDepth + 1 : rDepth + 1;
}

//二叉树拷贝
struct BiNode* copyBiTree(struct BiNode *root)
{
    if (root==NULL)
    {
        return NULL;
    }
    //先拷贝左子树
    struct BiNode* lNode = copyBiTree(root->lchild);
    //拷贝右子树
    struct BiNode* rNode = copyBiTree(root->rchild);
    //创建新节点
    struct BiNode* node = (struct BiNode*)malloc(sizeof(struct BiNode));
    node->data = root->data; 
    node->lchild = lNode;
    node->rchild = rNode;
    return node;
}

//销毁二叉树
void destroyBiTree(struct BiNode *root)
{
    if (root == NULL)
    {
        return ;
    }
    //销毁左子树
    destroyBiTree(root->lchild);
    //销毁右子树
    destroyBiTree(root->rchild);
    printf("%c being destroyed\n", root->data);
    free(root);
    root=NULL;
}

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
    struct BiNode nodeA = {'A', NULL, NULL};
    struct BiNode nodeB = {'B', NULL, NULL};
    struct BiNode nodeC = {'C', NULL, NULL};
    struct BiNode nodeD = {'D', NULL, NULL};
    struct BiNode nodeE = {'E', NULL, NULL};
    struct BiNode nodeF = {'F', NULL, NULL};
    struct BiNode nodeG = {'G', NULL, NULL};
    struct BiNode nodeH = {'H', NULL, NULL};

    nodeA.lchild = &nodeB;
    nodeA.rchild = &nodeF;

    nodeB.rchild = &nodeC;

    nodeC.lchild = &nodeD;
    nodeC.rchild = &nodeE;

    nodeF.rchild = &nodeG;

    nodeG.lchild = &nodeH;

    //一般很少用全局变量
    //计算叶子数量
    int num = 0;
    calculateLeafNum(&nodeA, &num);
    printf("leaf count:%d\n", num);
    //计算树高度
    printf("depth:%d\n", calculateDepth(&nodeA));
    //拷贝二叉树
    struct BiNode* newTree = copyBiTree(&nodeA);
    printf("===========newTree===========\n");
    recursion(newTree);
    
    printf("\n");
    //销毁
    destroyBiTree(newTree);

    //非递归遍历
    
}

int main()
{
    test();
}