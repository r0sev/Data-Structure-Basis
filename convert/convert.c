//
//  main.c
//  convert
//
//  Created by r0sev on 2018/9/24.
//  Copyright © 2018 SpaceX. All rights reserved.
//  进制转换

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int toTen(char [], int system);
void convert(int m, int system);

int main(int argc, const char * argv[]) {
    
    if (argc != 5) {
        printf("example: 1001 2 -t 10 --> 将1001从二进制转化为10机制 \n");
        exit(1);
    }
    
    char *from = (char *)argv[1];
    int origin, to, real;
    
    origin = atoi(argv[2]);
    to = atoi(argv[4]);
    
    real = toTen(from, origin);
    convert(real, to);
    printf("\n");
//    printf(" \t --- *** 进制转换 ***--- \n");
//    printf(" 使用方式: fromNumber system -t system \n");
//    scanf("%c", &d);
//    char *a = "ff";
//    printf("%d\n", toTen(a, 16));
    return 0;
}

int toTen(char a[], int system){
    unsigned long len;                  //strlen返回 unsigned long 型
    int sum = 0,num=0;
    len = strlen(a);
    
    for (int i = 0; i<len; i++) {
        if (a[i] >= '0' && a[i] <= '9') {
            num = a[i] - '0';
        }else if(a[i] >= 'a' && a[i] <= 'f'){
            num = a[i] - 'a' + 10;
        }else if(a[i] >= 'A' && a[i] <= 'F'){
            num = a[i] - 'A' + 10;
        }
        sum = sum * system + num;
    }
    return sum;
}

void convert(int m, int toSystem){
    int n;
    if (m) {
        convert(m/toSystem, toSystem);
        n = m % toSystem;
        if (n < 10) {
            printf("%d",n);
        }else{
            printf("%c", n + 55);
        }
    }
  
}




