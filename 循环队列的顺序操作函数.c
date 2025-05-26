#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct{
    ElemType *data;
    int front;
    int rear;
}Queue;

//初始化
Queue* initQueue(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->data = (ElemType*)malloc(sizeof(ElemType));
    q->front = 0;
    q->rear = 0;
    return q;
}

//判断队列是否为空
int isEmpty(Queue *Q){
    if(Q->front == Q->rear){
        return 1;
    } else{
        return 0;
    }
}

//入队
int equeue(Queue *Q,ElemType e){
    if((Q->rear + 1) % MAXSIZE == Q->front){
        printf("队列已满\n");
        return 0;
    } else{
        Q->data[Q->rear] = e;
        Q->rear = (Q->rear + 1) % MAXSIZE;
        return 1;
    }
}

//出队
int dequeue(Queue *Q,ElemType *e){
    if(Q->front == Q->rear){
        printf("队列为空\n");
        return 0;
    } else{
        *e = Q->data[Q->front];
        Q->front = (Q->front + 1) % MAXSIZE;
        return 1;
    }
}

//获取队头元素
int getHead(Queue *Q,ElemType *e){
    if(Q->front == Q->rear){
        printf("队列为空\n");
        return 0;
    } else{
        *e = Q->data[Q->front];
        return 1;
    }
}