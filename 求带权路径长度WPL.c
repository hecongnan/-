#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 100

typedef int ElemType;

typedef struct TreeNode {
    ElemType weight;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

typedef TreeNode* BiTree;

int idx = 0;
int weight[] = {100,42,15,-1,-1,27,-1,-1,58,28,13,5,-1,-1,8,-1,-1,15,-1,-1,30,-1,-1};

void createBiTree(BiTree *T){
    ElemType ch;
    ch = weight[idx++];
    if(ch == -1){
        *T = NULL;
    }
    else{
        *T = (BiTree)malloc(sizeof(TreeNode));
        (*T)->weight = ch;
        createBiTree(&(*T)->left);
        createBiTree(&(*T)->right);
    }
}

int wpl(BiTree T){
    if(T == NULL){
        return 0;
    }
    BiTree queue[MAXSIZE];
    int front =0;
    int rear = 0;
    int wpl = 0;
    int depth = 0;
    queue[rear] = T;
    rear++;
    while(rear!=front){
        int count = rear - front;   
        while(count>0){
            BiTree curr = queue[front];
            front++;
            if(curr->left == NULL && curr->right == NULL){
                wpl += depth * curr->weight;
            }
            if(curr->left != NULL){
                queue[rear] = curr->left;
                rear++;
            }
            if(curr->right != NULL){
                queue[rear] = curr->right;
                rear++;
            }
            count--;
        }
        depth++;
    }
    return wpl;
}

int main(){
    BiTree T;
    createBiTree(&T);
    int w = wpl(T);
    printf("WPL: %d\n", w);
    return 0;
}