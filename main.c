//
//  main.c
//  fibonacci-iterative
//
//  Created by r0sev on 2018/9/22.
//  Copyright © 2018 SpaceX. All rights reserved.
//

/*
 * 关于使用迭代实现斐波那契数列的思维方式：
 * 幻想有两个'指针', current 和 f0
 * 例如:         0         1       1      2 3 5 8 13 21 34
 *              ^         ^
 *           current      f0
 *              ^         ^
 *              f0     current
 *                        ^       ^
 *                        f0     current
 * 按定义，从第三个数开始时，current = 前面的数 + 前面的前面的数
 */

#include <stdio.h>

void fib_iterative(int m){
    
    int f0 = 1;
    int tmp = 0;
    int current = 0;
    
    if (m < 1) {
        printf("error\n");
    }else if(m == 1){
        printf("%d\n", current);
    }else{
        while(m--) {
            printf("%d ", current);     //0 1 1 2
            tmp = current;              //前一层current
            current += f0;              //现在的current
            f0 = tmp;
        }
    }
}

int main(int argc, const char * argv[]) {
    int fib = 0;

    printf("你想看多长的Fibonacci数列：");
    scanf("%d", &fib);

    fib_iterative(fib);
    
    printf("\n");
    return 0;
}
