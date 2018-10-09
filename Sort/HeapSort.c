#include <stdio.h>

//
//  main.c
//  BST-version2
//
//  Created by r0sev on 2018/10/6.
//  Copyright © 2018 Heapspray. All rights reserved.
//
//  Time Cost: HeapSort ===> O(NlogN)


void swap(int k[], int i, int j);
void HeapAdjust(int a[], int s, int n);

//1
//Based on array not Pointer(Single List)
void HeapSort(int a[], int count){
    
    // Both Big end Heap or Small end Heap are OK!
    
    for (int i = count/2 ; i > 0 ; i--)    //start from 'n/2'
    {
        /* code */
        HeapAdjust(a, i, count);
    }
    
    for (int i = count; i > 1 ; --i)
    {
        /* code */
        swap(a, 1, i);
 //       HeapSort(a, count - 1);            //注意这里使用了递归,也可以像底下这么写:
        HeapAdjust(a, 1, i - 1);
    }
    
}


//2 swap
void swap(int k[], int i, int j){
    int temp;
    
    temp = k[i];
    k[i] = k[j];
    k[j] = temp;
}

//3 HeapAdjust
void HeapAdjust(int a[], int s, int n){
    
    int temp = a[s];                        //temp is i's father node
    
    for (int i = 2*s ; i <= n; i*=2)
    {
        //count++;
        //i start from child node
        if (i < n && a[i] < a[i+1])            //i is not 'n' && rchild > lchild
        {
            /* code */
            i++;                            //make i to his rchild
        }
        
        if (temp >= a[i])
        {
            /* code */
            break;                            //jmp to line 60
        }
        
        a[s] = a[i];
        
        s = i;
        
    }
    //put value in the right position:
    a[s] = temp;
}

int main(int argc, char const *argv[])
{
    int a[] = {-1, 5, 2, 6, 0 ,3, 9, 1 ,7, 4};    //Do not use a[0]
    //Consider the number of root is '1' deliberately
    HeapSort(a, 9);
    
    for (int i = 1; i < 10; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

/* 关于 lldb 调试如何打印数组某范围的值:
 * 原文地址: https://segmentfault.com/q/1010000000741507
 
 (lldb) type summary add -s "${var[1023-1030]}" "int *"
 (lldb) frame variable hugeAry
 (int *) hugeAry = 0x0000000000cba010 [1023,1024,1025,1026,1027,1028,1029,1030]
 
 这个应该是修改了打印的格式来实现的。不过这个不是display，只是显示数组中的一片而已，不能在每次停下来的时候显示结果。
 */
