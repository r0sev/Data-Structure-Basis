//
//  main.c
//  DualListDemo
//
//  Created by r0sev on 2018/9/27.
//  Copyright © 2018 SpaceX. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct DualLinkList{
    char data;
    struct DualLinkList* prior;
    struct DualLinkList* next;
}Node, *DualList;


void InitDualList(DualList *L){
    DualList p = NULL;
    int content = 'A';
    Node* temp = NULL;
    for (; content < 'Z' + 1; content++) {
        temp = (Node *)malloc(sizeof(Node));
        if (temp == NULL) {
            printf("malloc error in line 26.\n");
            return;
        }
        if (NULL != p) { //此时p已经经过了一次下面的else分支，已经指向了一个具体的结点，故有了data,next等属性，可以直接交换了
            temp->data = content;
            temp->next = *L;
            temp->prior = p;
            p->next = temp;
            //p->prior = temp;
            p = temp;
        }else{ //如果是第一次就直接令p = temp;因为此前p还只是空指针(暂时没有指向结点)，还没有data,prior,next等
            temp->data = content;
            temp->next = temp->prior = temp;
            p = temp;
            *L = p;
        }
        (*L)->prior = p;                //上述过程并没有将第一个节点的prior指向最后一个，所以这里要补上！
    }
}

void testPrint(DualList L){
    DualList p = L;
    if (p != NULL) {
        do{
            printf("%c", (*p).data);
            p = p->next;
        }while (p!= L);         //while (p != NULL && p!= L);
    }
    printf("\n");
}

void printStringInLocation(int location , DualList L){
    DualList p = L;
    if (location >= 0) {
        while (location-- &&  p!=NULL) {
            p = p->next;
        }
    }else{
        //location = -1 * location;
        while (location++ &&  p!=NULL) {
            p = p->prior;
        }
    }
    testPrint(p);
}


int main(int argc, const char * argv[]) {
    int location = 0;
    DualList L = NULL;
    InitDualList(&L);
    scanf("%d", &location);
    printStringInLocation(location, L);
    //testPrint(L);
    return 0;
}


