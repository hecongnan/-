#include <stdio.h>
#include <stdlib.h>


typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next,*prev;
}Node;

//初始化
Node* initlist(){
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    head->prev = NULL;
    return head;
}

//头插法
int insertHead(Node *L,ElemType e){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->prev = L;
    p->next = L->next;
    if(L->next != NULL){
        L->next->prev = p;
    }
    L->next = p;
    return 1;
}

//尾插法
Node *insertTail(Node *tail,ElemType e){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->prev = tail;
    tail->next = p;
    p->next = NULL;
    return p;
}

//在特定位置插入
int insertNode(Node *L,ElemType e,int pos){
    Node *p = L;
    int i = 0;
    while(i < pos-1){
        p = p->next;
        i++;
        if (p == NULL){
            return 0;
        }
    }
    Node *q = (Node*)malloc(sizeof(Node));
    q->data = e;
    q->prev = p;
    q->next = p->next;
    p->next->prev = q;
    p->next = q;
    return 1;
}

//删除节点
int deleteNOde(Node *L,int pos){
    Node *p = L;
    int i = 0;
    while(i< pos-1){
        p = p->next;
        i++;
        if(p == NULL){
            return 0;
        }
    }
    if (p->next == NULL){
        return 0;
    }
    Node *q = p->next;
    p->next = q->next;
    q->next->prev = p;
    free(q);
    return 1;
}