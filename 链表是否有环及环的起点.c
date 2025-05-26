#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;

Node *findBegin(Node *head){
    Node *fast = head;
    Node *slow = head;
    while(fast !=NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            Node *p = fast;
            int count = 1;
            while(p != slow){
                p= p->next;
                count++;
            }
            fast = head;
            slow = head;
            for(int i=0;i<count;i++){
                fast = fast->next;
            }
            while(fast != slow){
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
    }
    return NULL;
}