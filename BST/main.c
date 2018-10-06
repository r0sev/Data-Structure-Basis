//
//  main.c
//  BST-version2
//
//  Created by r0sev on 2018/10/6.
//  Copyright © 2018 Heapspray. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct BST_Node{
    DataType data;
    struct BST_Node *lchild, *rchild;
}BST_T, *BST_P;

BST_P SearchMin(BST_P p){
    if (!p) {
        return NULL;        //  if tree is empty
    }
    //递归法
    if (p->lchild == NULL) {
        return p;
    }
    else
        return SearchMin(p->lchild);
    
    
//    //迭代法
//    while (p->lchild) {
//        p = p->lchild;
//    }
//    return p;
}

BST_P SearchMax(BST_P p){
    if (!p) {
        return NULL;
    }
    if (!p->rchild) {
        return p;
    }else
        return SearchMax(p->rchild);
}

//非递归版
BST_P Search_BST(BST_P tp, DataType key){
    BST_P p = tp;
    while (p) {
        if (p->data == key) {
            return p;
        }
        p = (key > p->data) ? p->rchild : p->lchild;
    }
    return NULL;
}

//递归版查找
BST_P SearchBST(BST_P tp, DataType key)
{
    if (!tp) {
        return NULL;
    }
    if (key > tp->data) {
        return SearchBST(tp->rchild, key);
    }else if (key < tp->data){
        return SearchBST(tp->lchild, key);
    }else           //key == tp->data
        return tp;
}

void InsertBST(BST_P *T, DataType a){
    //初始化插入结点
    BST_P p = (BST_P)malloc(sizeof(BST_T));
    if (!p) {
        return;
    }
    
    p->data = a;
    p->lchild = p->rchild = NULL;
    
    //若为空树
    if (*T == NULL) {
        *T = p;
        return;
    }
    
    //是否存在该值,存在则返回
    if ( SearchBST(*T, a) != NULL ) {
        return;
    }
    
    //否则进行插入
    BST_P tnode = NULL, troot = *T;
    while (troot) {
        tnode = troot;
        troot = (a < troot->data) ? troot->lchild : troot->rchild;
    }
    //找到了要插入结点的父节点位置----->tnode
    if (a < tnode->data) {
        tnode->lchild = p;
    }else{
        tnode->rchild = p;
    }
}

void CreateBST(BST_P *T, int a[] , int n){
    for (int i = 0; i < n ; i++) {
        InsertBST(T, a[i]);
    }
}

void DeleteBSTNode(BST_P *t, DataType data){
    BST_P p = *t, parent = NULL, s=NULL;
    
    if (!p) {
        return;     //empty
    }
    
    if (p->data == data) {
                                            /* leaf node */
        if (!p->rchild && !p->lchild) {     //if rchild = lchild == NULL
            *t = NULL;
        }else if(!p->rchild && p->lchild){  //only if one child is NULL
            *t = p->lchild;
        }else if(!p->lchild && p->rchild){
            *t = p->rchild;
        }else{                              //Both children not null
            s = p->rchild;
            if (!s->lchild) {               //if s does not have lchild
                s->lchild = p->lchild;
            }else{
                /* find the smallest node in the left subtree of s */
                while (s->lchild)
                {
                    /* record the parent node of s */
                    parent = s;
                    s = s->lchild;
                }
                parent->lchild = s->rchild;
                s->lchild = p->lchild;
                s->rchild = p->rchild;
            }
            *t = s;
        }
        free(p);
    }
    else if (data > p->data) //向右找
        DeleteBSTNode(&(p->rchild), data);
    else if(data < p->data)
        DeleteBSTNode(&(p->lchild), data);
    
}

void PreOrderTraverse(BST_P T){
    if (T) {
        printf("%d ", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void MidOrderTraverse(BST_P T){
    if (T) {
        MidOrderTraverse(T->lchild);
        printf("%d ", T->data);
        MidOrderTraverse(T->rchild);
    }
}


void PostOrderTraverse(BST_P T){
    if (T) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%d ", T->data);
    }
}


int main(int argc, const char * argv[]) {
    //
    
    int arr[] = { 17,12,19,10,15,18,25,8,11,13,16,22};
    
    BST_P root = NULL;
    
    //创建二叉排序树
    CreateBST(&root, arr, 12);
    printf("\nCreate BST: ");
    printf("\npre order traverse: ");
    PreOrderTraverse(root);
    printf("\npost order traverse: ");
    PostOrderTraverse(root);
    printf("\n");
    
    //在二叉排序树中查找节点12.
    BST_P result = Search_BST(root, 12);
    printf("\nSearch Data: ");
    printf( "查找结果：\n 指针： 0x%x \n指针的值： %d ",&result, result->data);
    
    //在二叉排序树中插入9
    InsertBST(&root, 9);
    printf("\nInsert Data: ");
    printf("\npre order traverse: ");
    PreOrderTraverse(root);
    printf("\npost order traverse: ");
    PostOrderTraverse(root);
    printf("\n");
    
    //删除二叉排序树中的节点12
    DeleteBSTNode(&root, 12);
    printf("\nDelete Data: ");
    printf("\npre order traverse: ");
    PreOrderTraverse(root);
    printf("\npost order traverse: ");
    PostOrderTraverse(root);
    printf("\n");
    
    
    //
    return 0;
}
