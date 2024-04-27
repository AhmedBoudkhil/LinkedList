#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;


node *createNewNode(int data){
    node *newNode = malloc(sizeof(node));
    newNode->data  = data;
    newNode->link  = NULL;
    return newNode;
}
void addFirst(node **head, node *newNode){
    newNode->link = *head;
    *head = newNode;
    retur head;
}

node *addlast(node *head, node *newNode){
    node *tmp = head;
    while(tmp->link != NULL){
        tmp = tmp->link;
    }
    tmp->link = newNode;
}

node *AddNewNode(node *head,node *newNode,int pos){
    node *tracker  = head;
    pos -= 1;
    while(pos != 1){
        tracker = tracker->link;
        pos--;
    }
    newNode->link = tracker->link;
    tracker->link = newNode;

    
}
void printLinkedList(node *first){
    node *tmp = first;
    
    while(tmp != NULL){
        printf("data : %d \n",tmp->data);
        tmp = tmp->link;
    }
}
int main() {
    int pos = 1;
    
    node *first,*second,*last;
    first = createNewNode(10);
    second = createNewNode(20);
    last = createNewNode(30);
    
    first->link = second;
    second->link = last;
    last ->link = NULL;
    
    node *newFuckinNode = createNewNode(999);
    
    if(pos == 1){
        addFirst(&first,newFuckinNode);
    }else{
        AddNewNode(first,newFuckinNode,pos);
    }
    printLinkedList(first);
    
    
    return 0;
}
