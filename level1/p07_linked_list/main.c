#include<stdio.h>
#include <stdlib.h>

//定义链表节点
typedef struct Node{
    int data;
    struct Node *next;
}Node;

//创建一个新的节点
Node *createNode(int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    if (newNode==NULL){
        printf("内存分配失败");
        exit(1);
    }   
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
//头插
void inserthead(Node **head,int value){
    Node *newNode=createNode(value);
    newNode->next=*head;
    *head=newNode;
}
//尾插
void inserttail(Node **head,int value){
    Node *newNode=createNode(value);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    Node *p=*head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=newNode;
}
int deletevalue(Node **head,int value){
    if(*head==NULL){
        return 0;
    }
    Node *p=*head;
    Node *q=NULL;
    while(p!=NULL && p->data!=value){
        q=p;
        p=p->next;
    }
    if (p==NULL){
        return 0;
    }
    if (q==NULL){
        *head=p->next;
    }else{
        q->next=p->next;
    }
    free (p);
    return 1;
}    
void printlist(Node *head){
    Node *p=head;
    while (p!=NULL){
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL\n");
}

void freeList(Node **head) {
    Node *p = *head;
    while (p != NULL) {
        Node *temp = p;
        p = p->next;
        free(temp);
    }
    *head = NULL;
}
void reverselist(Node **head){
    Node *prev=NULL;
    Node *cur=*head;
    Node *next=NULL;
    while (cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    *head=prev;
}

int findfirst(Node *head ,int target){
    int index=1;
    Node *p=head;
    while(p!=NULL){
        if (p->data==target)return index;
        p=p->next;
        index++;
    }
    return -1;
}

int findnext(Node *head,int target,int lastindex){
    int index=1;
    Node *p=head;
    while(p!=NULL && index<=lastindex){
        p=p->next;
        index++;
    }
    while(p!=NULL){
        if(p->data==target)return index;
        p=p->next;
        index++;
    }
    return -1;
}








int main() {
    Node *head = NULL;  

    
    inserttail(&head, 10);
    inserthead(&head, 5);
    inserttail(&head, 20);
    inserthead(&head, 5);
    inserttail(&head, 30);

   
    

    printf("链表内容：");
    printlist(head);     

    
    reverselist(&head);
    printf("反转后的链表：");
    printlist(head);
    int first = findfirst(head, 5);
    printf("第一个值为5的序号: %d\n", first);
    if (first != -1) {
        printf("下一个值为5的序号: %d\n", findnext(head, 5, first));
    }     

    
    freeList(&head);
    printf("释放后 head = %p\n", (void*)head); 

    return 0;
}


