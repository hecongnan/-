#include <stdio.h>
#include <stdlib.h>

#define ILMSize 10
#define MaxSize 100

struct IndexItem {
    IndexKeyType index;//IndexKeyType是事先定义的索引值类型
    int start;
    int length;
};

typedef struct IndexItem indexlist[ILMSize];//ILMSize是事先定义的整型常量，大于等于索引项m

typedef struct ElemType mainlist[MaxSize];//MaxSize为事先定义的整型常量，大于等于主表中的元素个数n
int Indsch(mainlist A,indexlist B,int m,IndexKeyType K1,KeyType K2){//K1为索引项，K2为要查找的数
    int i,j;
    for(i=0;i<m;i++)
        if(K1 == B[i].index)
        break;
    if(i == m){
        return -1;
    }
    j = B[i].start;
    while(j < B[i].start + B[i].length){
        if(K2 == A[j].key) break;
        else j++;
    }
    if(j < B[i].start + B[i].length){
        return j;
    } else return -1;
}