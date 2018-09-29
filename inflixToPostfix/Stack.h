//
//  Stack.h
//  infixToPostfix
//
//  Created by r0sev on 2018/9/29.
//  Copyright © 2018 Heapspray. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
#define MAXBUFFER 10

typedef char ElemType;
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;

void InitStack( sqStack *s );
void PUSH(sqStack *s, ElemType e);

void POP(sqStack *s, ElemType *e);
long StackLen(sqStack s);



#endif /* Stack_h */
