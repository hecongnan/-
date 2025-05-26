//中缀表达式转后缀表达式
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

typedef enum {
    LEFT_PARE, RIGHT_PARE,
    ADD, SUB, MUL, DIV, MOD,
    EOS, NUM
} contentType;

// 修改表达式，保证括号匹配
char expr[] = "x/(i-j)*y";

// 初始化
typedef struct {
    ElemType *data;
    int top;
} Stack;

Stack* initStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
    s->top = -1;
    return s;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

// 进栈
int push(Stack *s, ElemType e) {
    if (s->top == MAXSIZE - 1) {
        printf("栈满了\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = e;
    return 1;
}

// 出栈
int pop(Stack *s, ElemType *e) {
    if (isEmpty(s)) {
        return 0;
    }
    *e = s->data[s->top];
    s->top--;
    return 1;
}

// 获取栈顶元素
int getTop(Stack *s, ElemType *e) {
    if (isEmpty(s)) {
        return 0;
    }
    *e = s->data[s->top];
    return 1;
}

contentType getToken(char *symbol, int *index) {
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

int print_token(contentType token) {
    switch (token) {
        case ADD:
            printf("+");
            break;
        case SUB:
            printf("-");
            break;
        case MUL:
            printf("*");
            break;
        case DIV:
            printf("/");
            break;
        case MOD:
            printf("%%");
            break;
        default:
            return 0;
    }
    return 1;
}

void postfix(Stack *s) {
    int in_Stack[] = {0, 19, 12, 12, 13, 13, 13, 0};
    int out_Stack[] = {20, 19, 12, 12, 13, 13, 13, 0};
    contentType token;
    int index = 0;
    char symbol;
    // 初始化栈底元素
    push(s, (ElemType)EOS);
    token = getToken(&symbol, &index);
    while (token != EOS) {
        if (token == NUM) {
            printf("%c", symbol);
        } else if (token == LEFT_PARE) {
            push(s, (ElemType)token);
        } else if (token == RIGHT_PARE) {
            ElemType e;
            while (getTop(s, &e) && (contentType)e != LEFT_PARE) {
                if (pop(s, &e)) {
                    print_token((contentType)e);
                }
            }
            // 弹出左括号
            if (getTop(s, &e) && (contentType)e == LEFT_PARE) {
                pop(s, &e);
            }
        } else {
            ElemType e;
            while (getTop(s, &e) && in_Stack[token] <= out_Stack[(contentType)e] && (contentType)e != LEFT_PARE) {
                if (pop(s, &e)) {
                    print_token((contentType)e);
                }
            }
            push(s, (ElemType)token);
        }
        token = getToken(&symbol, &index);
    }
    // 弹出栈中剩余的运算符
    ElemType e;
    while (getTop(s, &e) && (contentType)e != EOS) {
        if (pop(s, &e)) {
            print_token((contentType)e);
        }
    }
}

int main() {
    Stack *s = initStack();
    postfix(s);
    printf("\n");
    free(s->data);
    free(s);
    return 0;
}