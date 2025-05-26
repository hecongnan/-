//后缀表达式求值
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

typedef enum {
    LEFT_PARE,RIGHT_PARE,
    ADD, SUB, MUL, DIV,MOD,
    EOS,NUM
}contentType;

char expr[] = "82/2+56*-";

//初始化
typedef struct{
    ElemType *data;
    int top;
}Stack;

Stack* initStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
    s->top = -1;
    return s;
}

int isEmpty(Stack *s){
    if (s->top == -1){
        printf("栈为空");
        return 1;
    }
    else {
        return 0;
    }
}

//进栈
int push(Stack *s,ElemType e){
    if(s->top ==MAXSIZE -1){
        printf("栈满了\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = e;
    return 1;
}

//出栈
ElemType pop(Stack *s,ElemType *e){
    if (s->top == -1){
        printf("栈为空\n");
        return 0;
    }
    *e = s->data[s->top];
    s->top--;
    return 1;
}

//获取栈顶元素
int getTop(Stack *s,ElemType *e){
    if(s->top == -1){
        printf("栈为空\n");
        return 0;
    }
    *e = s->data[s->top];
    return 1;
}

contentType getToken(char *symbol,int *index){
    *symbol = expr[*index];
    (*index)++;
    switch (*symbol) {
        case '+':
            return ADD;
        case '-':
            return SUB;
        case '*':
            return MUL;
        case '/':
            return DIV;
        case '%':
            return MOD;
        case '(':
            return LEFT_PARE;
        case ')':
            return RIGHT_PARE;
        case '\0':
            return EOS;
        default:
                return NUM;
    }
}

int eval(Stack *s){
    char symbol;
    int op1 = 0, op2 = 0;
    int index = 0;
    contentType token;
    token = getToken(&symbol, &index);
    ElemType result = 0;
    while(token != EOS){
        if(token == NUM){
            push(s,symbol - '0');
        }
        else {
            pop(s,&op2);
            pop(s,&op1);
            switch (token) {
                case ADD:
                    push(s,op1 + op2);
                    break;
                case SUB:
                    push(s,op1 - op2);
                    break;
                case MUL:
                    push(s,op1 * op2);
                    break;
                case DIV:
                    push(s,op1 / op2); 
                    break;
                case MOD:
                    push(s,op1 % op2);
                    break;
                default:
                    break;
            }
        }
        token = getToken(&symbol, &index);
    }
    pop(s,&result);
    printf("表达式的值为：%d\n", result);
    return 1;
}

int main(){
    Stack *s = initStack();
    eval(s);
    return 0;
}