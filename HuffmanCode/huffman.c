//
//  huffman.c
//  Huffman
//
//  Created by r0sev on 2018/10/2.
//  Copyright © 2018 Heapspray. All rights reserved.
//

#include "huffman.h"
#include "queue.h"
#include <string.h>


Tree *buildTree(char *string){
    
    int *probability = (int *)malloc(sizeof(int) * ASCII_SIZE);
    for (int i = 0; i < ASCII_SIZE; i++) {
        probability[i] = 0;               //Initialize the probability[]
    }
    //统计字符出现次数
    for (int j = 0; string[j] != '\0'; j++) {
        probability[ (unsigned)string[j] ]++;
    }
    
    pQueue *huffmanQueue;           //创建优先级队列，从小到大排列
    InitQueue(&huffmanQueue);
    
    for (int k = 0 ; k < ASCII_SIZE; k++) {
        //如果某个字符出现过，则根据其权值（出现次数/频率）为其创建队列结点，并插入优先级队列
        if (probability[k] != 0) {
            htNode *tnode = (htNode *)malloc(sizeof(htNode));
            tnode->left = NULL;
            tnode->right = NULL;
            tnode->symbol = (char)k;        //ascii
            
            enQueue(&huffmanQueue, tnode, probability[k]);
        }
    }//创建队列结束
    
    free(probability);      //节省一点空间
    
    //生成哈夫曼树
    while (huffmanQueue->size != 1) {                         //最终队列只会剩下一个结点，即哈夫曼树的根!
        
        int priority = huffmanQueue->first->priority;
        priority += huffmanQueue->first->next->priority;
        
        htNode* left = getFromQueue(&huffmanQueue);
        htNode* right = getFromQueue(&huffmanQueue);
        
        htNode* newNode = (htNode *)malloc(sizeof(htNode));
        newNode->left = left;
        newNode->right = right;
        
        enQueue(&huffmanQueue, newNode, priority);              //新结点重新入队
    }
    
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = getFromQueue(&huffmanQueue);
    
    return tree;
}

huffmanTable *buildTable(Tree *huffmanTree){
    huffmanTable *table = (huffmanTable *)malloc(sizeof(huffmanTable));
    table->first = table->last = NULL;
    
    char code[256];
    int k = 0;
    
    traverseTree(huffmanTree->root, &table, k, code);       //遍历Huffman树的过程中更新table，k=0往左，k=1往右遍历
    return table;
    
}


//这是一个递归定义的遍历树 来创建对应表的功能函数
void traverseTree(htNode *treeNode, huffmanTable **table, int k, char code[256]){
    
    if (treeNode->left == NULL && treeNode->right == NULL) {
        code[k] = '\0';                      //因为进入这个分支即是叶子节点了，到了递归的结束条件
        tNode *tableNode = (tNode *)malloc(sizeof(tNode));
        tableNode->code = (char *)malloc(sizeof(char) * (strlen(code)+1));
        strcpy(tableNode->code, code);       //从code数组将数据拷贝到表节点的code域中
        tableNode->symbol = treeNode->symbol;
        tableNode->next = NULL;
        
        
        if ((*table)->first == NULL) {
            (*table)->first = tableNode;
            (*table)->last = tableNode;
        }else{
            (*table)->last->next = tableNode;
            (*table)->last = tableNode;
        }
    }
    
    if (treeNode->left != NULL) {
        code[k] = '0';
        traverseTree(treeNode->left, table, k+1, code);
    }
    
    if (treeNode->right != NULL) {
        code[k] = '1';
        traverseTree(treeNode->right, table, k+1, code);
    }
}

void encode(huffmanTable *table, char *stringToEncode){
    int i = 0;
    tNode *p = table->first;
    while (stringToEncode[i] != '\0' && p) {
        
        if (p->symbol == stringToEncode[i]) {
            printf("%s ", p->code);
            i++;
            p = table->first;
            continue;
        }
        p = p->next;
    }
    printf("\n<--- Encode DONE! --->\n");
}



void decode(Tree *tree, char *stringToDecode){
    //??
    /* 写到decode这里我懵逼了，，，难不成要用KMP算法去匹配？？这不太麻烦了嘛。。。
     * 转念一想，终于知道为什么视频说要用遍历树的方式去decode了，0往左走，1往右走，省去了写KMP这个大老虎
     */
    int i = 0;
    htNode* twig = tree->root;                                                                   // twig小树枝 O(∩_∩)O
    
    printf("\n<--- Start Decode ---> \n");
    while (stringToDecode[i] != '\0') {

        if ('0' == stringToDecode[i] && twig->right != NULL && twig->left != NULL) {             // 0往左遍历
            twig = twig->left;
            i++;
            continue;                                                                            // 继续比较下一个0/1
        }else if('1' == stringToDecode[i] && twig->right != NULL && twig->left != NULL){
            twig = twig->right;
            i++;
            continue;
        }
        printf("%c",twig->symbol);
        twig = tree->root;
    }
    printf("\n<--- Decode DONE! --->\n");
    printf("\n\n");
}


