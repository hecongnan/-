#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct stack {
    ElemType data;
    struct stack *next;
}Stack;

//初始化
Stack* initStack(){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = 0;
    s->next = NULL;
    return s;
}

//判断栈是否为空
int isEmpty(Stack *s){
    if (s->next == NULL) {
        return 1; //栈空
    }
    return 0; //栈不空
}

//入栈
int push(Stack *s,ElemType e){
    Stack *p = (Stack*)malloc(sizeof(Stack));
    p->data = e;
    p->next = s->next;
    s->next = p;
    return 1;
}

//出栈
int pop(Stack *s,ElemType *e){
    if (isEmpty(s)) {
        return 0; //栈空
    }
    Stack *p = s->next;
    *e = p->data;
    s->next = p->next;
    free(p);
    return 1;
}

//获取栈顶元素
int getTop(Stack *s,ElemType *e){
    if (isEmpty(s)) {
        return 0; //栈空
    }
    *e = s->next->data;
    return 1;
}