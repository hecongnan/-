#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct QueueNode{
    ElemType data;
    struct QueueNode *next;
}QueueNode;

typedef struct Queue{
    QueueNode *front;
    QueueNode *rear;
}Queue;

//初始化
Queue* initQueue(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
    node->next = NULL;
    q->front = node;
    q->rear = node;
    return q;
}

//判段队列是否为空
int isEnpty(Queue *q){
    if(q->front == q->rear){
        return 1;
    }
    return 0;
}

//入队
void equeue(Queue *q,ElemType e){
    QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = e;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;
}

//出队
int dequeue(Queue *q,ElemType *e){
    QueueNode *node = q->front->next;
    *e = node->data;
    q->front->next = node->next;
    if(q->rear == node){
        q->rear = q->front;
    }
    free(node);
    return 1;
}

//获取队头元素
ElemType getfront(Queue *q){
    if(isEnpty(q)){
        printf("队列为空\n");
        return 0;
    }
    return q->front->next->data;
}