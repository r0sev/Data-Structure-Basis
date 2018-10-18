//
//  main.c
//  sort_tree
//
//  Created by r0sev on 2018/10/18.
//  Copyright © 2018 Heapspray. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define NOTFOUND 0
#define FOUND      1

//typedef int ElemType; //数据类型

typedef struct BiThreadTreeNode{
    int  data;
    struct BiThreadTreeNode *lChild;
    struct BiThreadTreeNode *rChild;
}BiThreadTreeNode, *Tree;

//position 返回插入点
void searchTree(Tree *T, int element, BiThreadTreeNode **position){
    //printf("%x \n",*T);
    if (*T == NULL)                                         //只有可能在第一次执行
    {
        //Test : printf("Tree is NULL,So I create Root Node Here.\n");
        *T = (Tree)malloc(sizeof(BiThreadTreeNode));
        (*T)->data = element;
        (*T)->lChild = (*T)->rChild = NULL;
        *position = *T;
        return;
    }
    
    if ((*T)->lChild == NULL && (*T)->rChild == NULL)       //没找到就返回其理论父节点的指针
    {
        *position = *T;
        return;
    }
    
    if ((*T)->data < element)                            //找右子树
    {
        *position = *T;
        if ((*T)->rChild != NULL)
            searchTree(&((*T)->rChild), element, position);
    } else if ((*T)->data > element){                    //找左子树
        *position = *T;
        if ((*T)->lChild != NULL)
            searchTree(&((*T)->lChild), element, position);
    } else {
        //position = *T;
        printf("Found the same value.\n");
    }
    return;
}


void CreateSortTree(Tree *T, int a[], int len){
    
    BiThreadTreeNode *position = NULL;
    BiThreadTreeNode *node;
    printf("\n建立二叉排序树中... 请稍后...\n\n");
    for (int i = 0; i < len; ++i)
    {
        searchTree(T, a[i], &position);     //5 1 6 3 2 7 4 9 8 10
        
        if (position->data < a[i])
        {
            node = (BiThreadTreeNode *)malloc(sizeof(BiThreadTreeNode));
            node->data = a[i];
            node->lChild = node->rChild = NULL;
            position->rChild = node;
        }else if (position->data > a[i]){
            node = (BiThreadTreeNode *)malloc(sizeof(BiThreadTreeNode));
            node->data = a[i];
            node->lChild = node->rChild = NULL;
            position->lChild = node;
        }else{                                //if (position->data == a[i])
            continue;                         //找到了，就不进行插入！
        }
    }
}

void InOrderTraverse(Tree T){
    if (T)
    {
        InOrderTraverse(T->lChild);
        printf("%d ", T->data);
        InOrderTraverse(T->rChild);
    }
}

void PreOrderTraverse(Tree T){
    if (T)
    {
        printf("%d ", T->data);
        PreOrderTraverse(T->lChild);
        PreOrderTraverse(T->rChild);
    }
}

void PostOrderTraverse(Tree T){
    if (T)
    {
        PostOrderTraverse(T->lChild);
        PostOrderTraverse(T->rChild);
        printf("%d ", T->data);
    }
}

int main(){
    
    Tree T = NULL;
    int a[] = {5,1,6,3,2,7,4,9,8,10};
    CreateSortTree(&T, a, 10);
    
    /**
     * 遍历一下试试：
     * 中序会输出有序序列
     */
    
    printf("中序遍历：");
    InOrderTraverse(T);
    printf("\n");
    
    printf("先序遍历：");
    PreOrderTraverse(T);
    printf("\n");
    
    printf("后序遍历：");
    PostOrderTraverse(T);
    printf("\n\n");
    
    return 1;
}



