//
//  queue.h
//  Huffman
//
//  Created by r0sev on 2018/10/2.
//  Copyright © 2018 Heapspray. All rights reserved.
//

#ifndef queue_h
#define queue_h
#include "huffman.h"

#define TREENODE htNode*


typedef struct priorityQueueNode{
    TREENODE treeNode;
    unsigned int priority;          //aka. weight
    struct priorityQueueNode* next;
}pQueueNode;

typedef struct priorityQueue{
    unsigned int size;
    pQueueNode *first;
}pQueue;                            //链式队列

void InitQueue(pQueue **);
void enQueue(pQueue **, TREENODE, unsigned int priority);    //In this process it'll be sorted automatically
void deQueue(pQueue *, htNode *node);           //出队列创建子树

TREENODE getFromQueue(pQueue **queue);

#endif /* queue_h */
