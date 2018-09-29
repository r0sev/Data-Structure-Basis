//
//  Stack.c
//  infixToPostfix
//
//  Created by r0sev on 2018/9/29.
//  Copyright © 2018 Heapspray. All rights reserved.
//

#include "Stack.h"

void InitStack( sqStack *s )
{
    s->base = (ElemType *)malloc( STACK_INIT_SIZE * sizeof(ElemType));
    if(!s->base)    //if failed malloc
        exit(0);
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;    //capacity of the stack
}

void PUSH(sqStack *s, ElemType e)
{
    if(s->top - s->base == s->stackSize){    //If stack is full
        s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
        if(!s->base)
            exit(0);
        
    }
    
    *(s->top) = e;
    s->top++;
    
}

void POP(sqStack *s, ElemType *e)
{
    if(s->top == s->base)
        return ;
    *e = *--(s->top);
}

long StackLen(sqStack s)
{
    return (s.top - s.base);
}




