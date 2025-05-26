#include <stdio.h>
#include <stdlib.h>

typedef enum Status{
    success,fail,fatal,range_error
}Status;

typedef struct Node{
    int elem;
    struct Node *next;
}Node,*Ptr;

typedef Ptr *SqlistPtr;

Status List_Init(SqlistPtr L){
    Status s = fail;
    Ptr p;
    if(*L == NULL){
        p = (Ptr)malloc(sizeof(Node));
        if(p == NULL) return s;
        *L = p;
        (*L)->next = NULL;
        s = success;
    }
    return s;
}

void List_Destory(SqlistPtr L){
    Ptr p;
    if(*L){
        p = (*L)->next;
        while(p){
            (*L)->next = p->next;
            free(p);
            p = (*L)->next;
        }
        free(*L);
        *L = NULL;
    }
}

void List_Clear(SqlistPtr L){
    Ptr p;
    if(*L){
        p = (*L)->next;
        while(p){
            (*L)->next = p->next;
            free(p);
            p = (*L)->next;
        }
    }
}

int List_Empty(SqlistPtr L){
    return (*L)->next == NULL;
}

int List_Size(SqlistPtr L){
    int size = 0;
    Ptr p = (*L)->next;
    while(p){
        size++;
        p = p->next;
    }
    return size;
}

Status List_Retrival(SqlistPtr L,int pos,int *elem){
    Status s = range_error;
    int i = 0;
    Ptr p = (*L)->next;
    while(p && i<pos){
        ++i;
        p = p->next;
    }
    if(p && i == pos){
        *elem = p->elem;
        s = success;
    }
    return s;
}

Status List_Locate(SqlistPtr L,int elem,int *pos){
    Status s = fail;
    Ptr p = (*L)->next;
    int i = 1;
    while(p){
        if(p->elem == elem){
            s = success;
            *pos = i;
            break;
        }
        p = p->next;
        i++;
    }
    return s;
}

Status List_find(SqlistPtr L,int pos,Ptr *pAddr){
    Status s = fail;
    Ptr p = (*L)->next;
    int i = 1;
    while(p && i < pos){
        p = p->next;
        i++;
    }
    if(p && i == pos){
        *pAddr = p;
        s = success;
    }
    return s;
}

Status List_Insert(SqlistPtr L,int pos,int elem){
    int i = 1;
    Status s = fail;
    Ptr p,q=NULL;
    if(pos > 1){
        s = List_find(L,pos-1,&q); // 调用 List_find 查找 pos-1 的位置
        if(s == success){
            p = (Ptr)malloc(sizeof(Node));
            if(p){
                p->elem = elem;
                p->next = q->next; // 将新节点的 next 指向 q 的 next
                q->next = p; // 将 q 的 next 指向新节点
                s = success;
            }
        }
    }
    else if (pos == 1){
        p = (Ptr)malloc(sizeof(Node));
        if(p){
            p->elem = elem;
            p->next = (*L)->next; // 将新节点的 next 指向 (*L)->next
            (*L)->next = p; // 将 (*L)->next 指向新节点
            s = success;
        }
    }
    return s;
}

Status List_delete(SqlistPtr L,int pos){
    Status s = fail;
    int i = 1;
    Ptr p,q=NULL;
    s = List_find(L,pos-1,&q);
    if(s == success){
        p = q->next;
        if(p){
            q->next = p->next;
            free(p);
            p = NULL;
            s = success;
        }
    }
    return s;
}

Status List_Prior(SqlistPtr L,int pos,int *elem){
    Status s;
    Ptr p,q=NULL;
    s = List_find(L,pos-1,&q);
    if(s == success){
        *elem = q->elem;
        s = success;
    }
    return s;
}

Status List_Next(SqlistPtr L,int pos,int *elem){
    Status s;
    Ptr q=NULL;
    s = List_find(L,pos,&q);
    if(s == success){
        if(q->next){
            *elem = q->next->elem;
            s = success;
        }
        else{
            s = fail;
        }
    }
    return s;
}

void List_Print(SqlistPtr L){
    Ptr p = (*L)->next;
    int i = 1;
    while(p){
        printf("%d ",p->elem);
        p = p->next;
        if(i++ % 10 == 0) printf("\n");
    }
}

Status List_Update(SqlistPtr L, int pos, int new_elem) { // 更新指定位置的元素
    Status s = fail;
    Ptr p = (*L)->next;
    int i = 1;
    while(p && i < pos) {
        p = p->next;
        i++;
    }
    if(p && i == pos) {
        p->elem = new_elem;
        s = success;
    }
    return s;
}

Status List_Reverse(SqlistPtr L) {  // 单链表逆置
    Status s = fail;
    Ptr prev = NULL;
    Ptr curr = (*L)->next;
    Ptr next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    (*L)->next = prev;
    s = success;
    return s;
}

int main() {
    SqlistPtr L = (SqlistPtr)malloc(sizeof(Ptr));
    if (L == NULL) {
        printf("Failed to allocate memory for L\n");
        return 1;
    }
    int choice, elem, pos, retrieved_elem;
    Status s;

    // 初始化链表
    s = List_Init(L);
    if (s == fail) {
        printf("链表初始化失败!\n");
        free(L); // 释放L的内存
        return 1;
    }

    // 输入元素，-1 结束
    printf("请输入元素，输入 -1 结束：\n");
    while (1) {
        while (scanf("%d", &elem)!= 1) {
            while (getchar()!= '\n'); // 清空输入缓冲区
            printf("输入错误，请重新输入元素：\n");
        }
        if (elem == -1) {
            break;
        }
        s = List_Insert(L, List_Size(L)+1, elem);
        if (s == fail) {
            printf("插入元素失败!\n");
            free(L); // 释放L的内存
            return 1;
        } 
    }

    // 打印链表
    List_Print(L);

    // 操作菜单
    while (1) {
         printf("\n请选择操作：\n");
        printf("1. 插入元素\n");
        printf("2. 删除元素\n");
        printf("3. 查找元素\n");
        printf("4. 查找元素位置\n");
        printf("5. 更新元素\n");
        printf("6. 查找前驱元素\n");
        printf("7. 查找后继元素\n");
        printf("8. 反转链表\n");
        printf("9. 清空链表\n");
        printf("10. 检查链表是否为空\n");
        printf("11. 销毁链表\n");
        printf("12. 退出\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("请输入要插入的位置和元素：\n");
                if (scanf("%d %d", &pos, &elem)!= 2) {
                    while (getchar()!= '\n'); // 清空输入缓冲区
                    printf("输入错误，请重新输入要插入的位置和元素：\n");
                    continue;
                }
                s = List_Insert(L, pos, elem);
                if (s == success) {
                    printf("插入成功!\n");
                } else {
                    printf("插入失败，可能是位置不合法或内存不足等原因，请检查!\n");
                }
                break;
            case 2:
                printf("请输入要删除的元素位置：\n");
                if (scanf("%d", &pos)!= 1) {
                    while (getchar()!= '\n'); // 清空输入缓冲区
                    printf("输入错误，请重新输入要删除的元素位置：\n");
                    continue;
                }
                s = List_delete(L, pos);
                if (s == success) {
                    printf("删除成功!\n");
                } else {
                    printf("删除失败，可能是位置不合法，请检查!\n");
                }
                break;
            // 其他case语句类似地进行输入验证和错误提示的修改

            case 12:
                List_Destory(L);
                return 0;
            default:
                printf("无效的选择，请重新输入!\n");
                break;
        }
        // 打印链表
        List_Print(L);
    }

    List_Destory(L); // 确保链表被销毁
    return 0;
}