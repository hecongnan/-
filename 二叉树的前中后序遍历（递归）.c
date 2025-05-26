#include stdio.h
#include stdlib.h

typedef char ElemType;

typedef struct TreeNode {
    ElemType data;
    TreeNode lchild;
    TreeNode rchild;
}TreeNode;

typedef TreeNode BiTree;

char str[] = ABDH#K###E##CFI###G#J##;
int idex = 0;

二叉树的创建
void createTree(BiTree T){
    ElemType ch;
    ch = str[idex++];
    if(ch == '#'){
        T = NULL;
    } else {
        T = (BiTree)malloc(sizeof(TreeNode));
        (T)-data = ch;
        createTree(&(T)-lchild);
        createTree(&(T)-rchild);
    }
}

二叉树的遍历-前序遍历
void preorder(BiTree T){
    if(T == NULL){
        return;
    }
    printf(%c , T-data);
    preorder(T-lchild);
    preorder(T-rchild);
}

二叉树的遍历-中序遍历
void inOrder(BiTree T){
    if (T == NULL){
        return;
    }
    inOrder(T-lchild);
    printf(%c , T-data);
    inOrder(T-rchild);
}

二叉树的遍历-后序遍历
void postOrder(BiTree T){
    if (T == NULL){
        return;
    }
    postOrder(T-lchild);
    postOrder(T-rchild);
    printf(%c , T-data);
}

int main() {
    BiTree T;
    createTree(&T);
    printf(前序遍历：);
    preorder(T);
    printf(n中序遍历：);
    inOrder(T);
    printf(n后序遍历：);
    postOrder(T);
    printf(n);
    return 0;
}