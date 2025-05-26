//链表重新排序
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}Node;

void reOrderList(Node *head){
    Node *fast = head->next;
    Node *slow = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *first = NULL;
    Node *second = slow->next;
    slow->next = NULL;
    Node *third = NULL;
    while(second != NULL){
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    } 
    Node *p1 = head->next;
    Node *q1 = first;
    Node *p2, *q2;
    while(p1 !=NULL && q1 !=NULL){
        p2 = p1->next;
        q2 = q1->next;
        p1->next = q1;
        q1->next = p2;
        p1 = p2;
        q1 = q2;
    }
}