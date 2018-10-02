//
//  main.c
//  Huffman
//
//  Created by r0sev on 2018/10/2.
//  Copyright © 2018 Heapspray. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"

/*
 * 整体思路：
 * 1. 先统计每个字符的出现字数（频度），并创建一个频度数组，用于存放每个字符出现的次数，共256个ascii
 * 2. 根据频度数组probability 创建优先级队列，出现0次的就不入队了，其余的按递增顺序在队(ps:不如说链表了..)中排列
 * 3. 从队头开始取元素，每取两个创建合并为一个新的哈夫曼树节点，并打包好(封装合并了priority)后重新入队，直到队中只剩1个结点
 * 4. 创建哈夫曼树的根节点并指向(pQueue)queue中的'最后一个元素' 表现为：queue->first，因为每次插入删除都会操作first指针
 * 5. 根据已创建的Huffman树建立对应的Huffman表(Table)
 * 6.
 */
int main(int argc, const char * argv[]) {
   
//    char *string = "Northeastern University (NEU) is a public university in Shenyang, Liaoning province with strengths in engineering and architecture. It is known for its prominent role in the information technology industry.Having built China's first electronic analog computer, university research park, and university-run commercial enterprise, Northeastern is now part of a government plan to revitalize the Northeast China economy with a focus on high-tech manufacturing. Its alumni include the founder and CEO of Neusoft, the largest Chinese IT and software outsourcing corporation, the first Olympic athlete to represent China, in the 1932 Summer Olympics, and the founder of Amnesty International in Taiwan.With a total enrollment of over 20,000 students, Northeastern has received significant government funding through the 211 Project and 985 Project, initiatives which sought to elevate the research standards of rising Chinese universities. In 2017, Northeastern was selected by the Chinese Ministry of Education as a Class B institution in the Double First Class University Plan, a major government initiative to comprehensively develop a group of elite universities into \"world-class institutions\" by 2050.";
    char *string = "abcdefghijklmnopqrstu vwxyzABCDEFGHIJKLMNO PQRSTUVWXYZasd kljkfasdntaodsfgiuasdjHOIDJF ! ,.....,!!!LASK EHREO IUVOIH DGSLAD J F";
    Tree *codeTree = buildTree(string);     //可以是文件
    huffmanTable *codeTable = buildTable(codeTree);
    
    encode(codeTable, "I want to apply for Northeastern University! aka.NEU.");
    decode(codeTree, "0111111111010001110101011011011111111101111101100111111010101010110101011000101010011111100011101100101011111110100110101100101011110111101010110101000110101110010111101010001010111101101111110011010110110001110101100101000101011111100100011101111101001111000111111010110011110101101101001100010010011011011");
    
    return 0;
}
