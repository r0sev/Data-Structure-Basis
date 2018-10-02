//
//  queue.c
//  Huffman
//
//  Created by r0sev on 2018/10/2.
//  Copyright © 2018 Heapspray. All rights reserved.
//

#include "queue.h"
#include "huffman.h"



void InitQueue(pQueue **queue){
    (*queue) = (pQueue *)malloc(sizeof(pQueue));
    (*queue)->first = NULL;
    (*queue)->size = 0;
}

void enQueue(pQueue **queue, TREENODE treeNode, unsigned int priority){
    if ((*queue)->size == ASCII_SIZE) {
        printf("\nError: queue is full!\n");
        return;
    }
    pQueueNode *queueNode = (pQueueNode*)malloc(sizeof(pQueueNode));
    queueNode->priority = priority;
    queueNode->treeNode = treeNode;
    
    if ((*queue)->size == 0 || (*queue)->first == NULL) {       //若是一个空队列
        queueNode->next = NULL;
        (*queue)->first = queueNode;
        (*queue)->size = 1;
    }else{                                                     //如果不是空队列
        //这里面有两种情况 1.< 2.>
        if (priority <= (*queue)->first->priority) {
            //头插法，插到第一个队列结点前,,,其实这样好像单链表了...
            queueNode->next = (*queue)->first;
            (*queue)->first = queueNode;
            (*queue)->size++;
            return;
        }else{
            //第二种可能，比第一个队列结点优先级要大，则往后遍历，插入适当位置
            pQueueNode* iterator = (*queue)->first;             //或qQN *p; 用于遍历的指针
            while (iterator->next != NULL) {
                if (priority <= iterator->next->priority) {
                    queueNode->next = iterator->next;
                    iterator->next = queueNode;
                    (*queue)->size++;
                    return;
                }
                iterator = iterator->next;
            }
            //out of while():
            if (iterator->next == NULL) {                       //比最后一个结点的优先级还大，就插入最后面
                queueNode->next = NULL;
                iterator->next = queueNode;
                (*queue)->size++;
                return;
            }
        }
    }
}

void deQueue(pQueue *, htNode *node);           //出队列创建子树

TREENODE getFromQueue(pQueue **queue){
    
    TREENODE targetNode = NULL;
    
    if ((*queue)->size > 0) {
        targetNode = (*queue)->first->treeNode;
        (*queue)->first = (*queue)->first->next;
        (*queue)->size--;
    }else
        printf("\nQueue is empty.\n");
    
    return targetNode;
}
