#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
#define MAXBUFFER 10

typedef double ElemType;
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;

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

int StackLen(sqStack s)
{
    return (s.top - s.base);
}





int main()
{
    char c;
    sqStack s;
    double d,e;                             //为了支持小数
    char str[MAXBUFFER];
    
    InitStack(&s);
    printf("请按逆波兰表达式输入，数据与运算符之间用空格隔开，以#结束：");
    scanf("%c", &c);
    
    while (c != '#') {
        //手动加一个缓冲区处理代码，将操作数从char组合成带小数点的double字面值
        int i = 0;
        while ( isdigit(c) || c == '.' ) {
            str[i++] = c;
            str[i] = '\0';
            if (i >= MAXBUFFER) {
                printf("出错，输入的单个数据太大！\n");
                exit(-2);
            }
            scanf("%c", &c);
            if (c == ' ') {
                d = atof(str);
                PUSH(&s, d);
                i = 0;                      //重新设置i,因为一个操作数的录入已结束
            }
        }
        
        if (c == '+' || c=='-' || c=='*' || c=='/') {
            POP(&s, &e);
            POP(&s, &d);
            switch (c) {
                case '+':
                    PUSH(&s, d+e);
                    break;
                case '-':
                    PUSH(&s, d-e);
                    break;
                case '*':
                    PUSH(&s, d*e);
                    break;
                case '/':
                    if (e != 0)
                        PUSH(&s, d/e);
                    else{
                        printf("出错，除数为0\n");
                        exit(-1);
                    }
                    break;
                default:
                    break;
            }
        }
        scanf("%c", &c);
    }
    POP(&s, &d);            //再次使用一次d吧
    printf("\n结果为：%.3f\n", d);

    return 1;
}



