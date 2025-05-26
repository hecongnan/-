双指针定位倒数第k个节点
int findNodeFS(Node L,int k)
{
    Node fast = L-next;
    Node slow = L-next;
    for(int i=0;ik;i++){
        if(fast == NULL) return 0;
        fast = fast-next;
    }
    while(fast != NULL){
        fast = fast-next;
        slow = slow-next;
    }
    if(slow == NULL) return 0;
    return slow-data;
}