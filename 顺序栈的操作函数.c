#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElemType;
#define maxsize 100

typedef struct Stack{
    ElemType data[maxsize];
    int top;
}Stack;

void initStack(Stack *s) {
    s->top = -1;
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
    if(s->top ==maxsize -1){
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

//动态内存分配

typedef struct{
    ElemType *data;
    int top;
}STack;
STack* initSTack(){
    STack *s =  (Stack*)malloc(sizeof(STack));
    s->data =  (ElemType*)malloc(sizeof(ElemType)*maxsize);
    s->top = -1;
    return s;
}