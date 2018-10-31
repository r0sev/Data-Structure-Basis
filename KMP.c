//
//  main.c
//  KMP
//
//  Created by r0sev on 2018/10/31.
//  Copyright © 2018 Heapspray. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 模式串对应的next 数组生成函数 */
void get_next(char pattern[], int next[], int n){
    /* 默认开头是0, 直接写上 */
    next[0] = 0;
    int i = 1;
    int len = 0;
    
    while(i<n){
        /* 如果第i个字符和已经匹配上的len个字符的后面那个字符相等 */
        if(pattern[i] == pattern[len]){
            next[i] = next[i-1] + 1;
            len++;
        }else{
            /* 前后缀已经不相等了,已匹配长度清0 --- 重新从pattern[0]开始匹配前后缀 */
            len = 0;
            next[i] = len;
        }
        i++;
    }
    /* 将next数组整体往后偏移一位，并补上-1 */
    for(i = n-1; i > 0; i--){
        next[i] = next[i-1];
    }
    next[0] = -1;
}

int KMP(char text[], int tlen, char pattern[], int plen, int next[]){
    int i = 0, j = 0;
    
    while(i < tlen && j < plen){
        /* 处理一下越界问题 */
        if(j == -1){
            i++;
            j++;
        }
        /* 如果当前字符匹配 */
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    /* 返回符合人类习惯的'位置' 而不是数组下标(实际上是匹配成功位置的下标+1) */
    return i-j+1;
}

int main(int argc, char *argv[]) {

    //char text[] = "BBBBABABCABCDBACBBACBADABC";        //location : 7
    //char pattern[] = "ABCABCDBAC";
    
    char text[] = "Hello, I Think LB is a nice girl.abcabcabcabcd You guys should love him!";
    char pattern[] = "abcd";                            //location : 43
    
    int next[10];
    int flocation = 0;
    
    int tlen = (int)strlen(text);
    int plen = (int)strlen(pattern);
    printf("%d\n",tlen);
    
//    /* Test if next array is working properly */
//            ABABCABCDBACBBACBADABC
//    next =  0001230010        After Offset: -1 0 0 0 1 2 3 0 0 1
//            ABCABCDBAC
//
    get_next(pattern, next, plen);
    
//    for(int i = 0; i < plen; i++)
//        printf("next[%d] = %d\n", i, next[i]);
//    printf("\n");
    
    printf("\nStart Matching Using KMP...\n");
    flocation = KMP(text, tlen, pattern, plen, next);
    printf("\nThe first location of '%s' is %d\n\n", pattern , flocation);

    return 0;
}

