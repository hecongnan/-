#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int front;
    int rear;
}Queue;

//初始化
void initQuene(Queue *Q){
    Q->front = 0;
    Q->rear = 0;
}

//判断队列是否为空
int isEmtpy(Queue *Q){
    if(Q->front == Q->rear){
        return 1;
    }else{
        return 0;
    }
}

//出队
ElemType deQueue(Queue *Q){
    if (Q->front == Q->rear) {
        printf("队列为空，无法出队\n");
        return 0; // 返回一个错误值
    }
    ElemType e = Q->data[Q->front];
    Q->front++;
    return e;
}

//队列数据前移
int moveQueue(Queue *Q){
    if (Q->front>0){
        int step = Q->front;
        for(int i = Q->front;i<Q->rear;i++){
            Q->data[i-step] = Q->data[i];
        }
        Q->front = 0;
        Q->rear = Q->rear - step;
        return 1;
    }
    else{
        return 0;
    }
}

//入队
int equeue(Queue *Q,ElemType e){
    if(Q->rear == MAXSIZE){
        if(!queueFull(Q)){
            return 0;
        }
    }
    Q->data[Q->rear] = e;
    Q->rear++;
    return 1;
}

//获取队头数据
int getHead(Queue *Q,ElemType *e){
    if(Q->front == Q->rear){
        printf("队列为空，无法获取队头数据\n");
        return 0; // 返回一个错误值
    }
    *e = Q->data[Q->front];
    return 1;
}

//获取队列长度
int getLength(Queue *Q){
    return Q->rear - Q->front;
}