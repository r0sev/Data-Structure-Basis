//
//  main.c
//  infixToPostfix
//
//  Created by r0sev on 2018/9/29.
//  Copyright © 2018 heapspray.cc. All rights reserved.
//

/*
 * Infix expression to postfix expression using Stack
 */

#include "Stack.h"
int main(int argc, const char * argv[]) {
    
    sqStack s;
    char c, e;
    
    InitStack( &s );
    
    printf("请输入中缀表达式，以#作为结束：");
    scanf("%c", &c);
    
    while( c != '#' )
    {
        //处理数字之间空格问题，确保10 5不会输出105，出现混淆
        while( c>='0' && c<='9' ){
            printf("%c", c);
            scanf("%c", &c);
            if( c<'0' || c>'9' )
                printf(" ");
        }
        
        //处理其他符号
        if( ')' == c )
        {
            POP(&s, &e);
            while( '(' != e ){
                printf("%c ", e);
                POP(&s, &e);
            }
        }
        else if( '+' == c || '-' == c ){
            if( !StackLen(s))
                PUSH(&s, c);
            else{
                do{
                    POP(&s, &e);
                    if( '(' == e )
                        PUSH(&s ,e);
                    else
                        printf("%c ", e);
                }while( StackLen(s) && '(' != e );
                    PUSH(&s, c);        //push在外等待的符号
            }
        }
        else if('*' == c || '/' == c || '(' == c)
            PUSH(&s, c);
        else if( '#' == c ){
            break;
        }
        else{
            printf("\n输入格式错误\n");
            return -1;
        }
        scanf("%c", &c);
    }
    while( StackLen(s) )
    {
        POP(&s, &e);
        printf("%c ", e);
    }
    
    printf("\n");
    return 0;
}

