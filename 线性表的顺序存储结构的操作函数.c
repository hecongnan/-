#include <stdio.h>
#include <stdlib.h>

typedef enum Status{
    success,fail,fatal,range_error
}Status;

typedef struct Sqlist{
    int *elem;
    int length;
    int list_size;
}Sqlist,*Ptr,*SqlistPtr;


Status List_Init(SqlistPtr L){
    Status s = fail;
    if(L == NULL){
        L->elem = (int *)malloc(11*sizeof(int));
        if(L->elem){
            L->length = 0;
            L->list_size = 10;
            s = success;
        }
    }
    return s;
}

void List_Destory(SqlistPtr L){
    if(L->elem){
        free(L->elem);
        L->elem = NULL;
    }
}

void List_Clear(SqlistPtr L){
    if(L){
        L->length = 0;
    }
}
int List_Empty(SqlistPtr L){
    return L->length == 0;
}

int List_Size(SqlistPtr L){
    return L->length;
}

Status List_Retrival(SqlistPtr L,int pos,int *elem){
    Status s = range_error;
    if(L){
        if(pos >=1 && pos <= L->length){
            *elem = L->elem[pos];
            s = success;
        }
    }
    return s;
}

Status List_Locate(SqlistPtr L,int elem,int *pos){
    Status s = range_error;
    int i = 1;
    if(L){
        for(i=1;i<=L->length;i++){
            if(L->elem[i] == elem){
                *pos = i;
                s = success;
                break;
            }
        }
    }
    return s;
}

Status List_Insert(SqlistPtr L,int pos,int elem){
    Status s = range_error;
    if(L){
        if(pos >= 1 && pos <= L->length+1){
            if(L->length < L->list_size){
                int i=0;
                for(i=L->length ;i>=pos;--i){
                    L->elem[i+1] = L->elem[i];
                }
                L->elem[i] = elem;
                L->length++;
                s = success;
            }
        }
    }
    return s;
}

Status List_Delete(SqlistPtr L,int pos,int *elem){
    Status s = range_error;
    if(L){
        if(pos >= 1 && pos <= L->length){
            int i = 0;
            for(i=pos;i<L->length;++i){
                L->elem[i-1] = L->elem[i];
            }
            L->length--;
            s = success;
        }
    }
    return s;
}

Status List_Prior(SqlistPtr L,int pos,int *elem){
    Status s = range_error;
    if(L){
        if(pos > 1 && pos <= L->length){
            *elem = L->elem[pos-1];
            s = success;
        }
    }
    return s;
}

Status List_Next(SqlistPtr L,int pos,int *elem){
    Status s = range_error;
    if(L){
        if(pos >= 1 && pos < L->length){
            *elem = L->elem[pos+1];
            s = success;
        }
    }
    return s;
}