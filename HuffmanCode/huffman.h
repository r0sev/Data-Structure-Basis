//
//  huffman.h
//  Huffman
//
//  Created by r0sev on 2018/10/2.
//  Copyright © 2018 Heapspray. All rights reserved.
//

#ifndef huffman_h
#define huffman_h
#include <stdlib.h>
#include <stdio.h>
#define ASCII_SIZE 256                    //ASCII has 256 elements


typedef struct huffmanTreeNode htNode;
typedef struct huffmanTreeNode{
    char symbol;
    htNode *left, *right;
}htNode;

typedef struct huffmanTree{
    htNode *root;
}Tree;

typedef struct huffmanTableNode{
    char symbol;                        // 'a' 'I' or 'F' etc
    char *code;                         //aka. '00100010'
    struct huffmanTableNode *next;
}tNode;

typedef struct huffmanTable{
    tNode *first;
    tNode *last;
}huffmanTable;


Tree *buildTree(char *inputString);
huffmanTable *buildTable(Tree *huffmanTree);
void traverseTree(htNode *treeNode, huffmanTable **table, int k, char code[256]);
void encode(huffmanTable *table, char *stringToEncode);
void decode(Tree *tree, char *stringToDecode);


#endif /* huffman_h */
