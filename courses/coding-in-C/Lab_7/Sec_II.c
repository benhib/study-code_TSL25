#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    double value;
    struct Node *pNext;
} Node;


void free_List(Node *pHead) {
    while (pHead != NULL) {
        Node *pNode = pHead->pNext ;
        pHead = pNode->pNext;
        free(pNode);
    }
}

 Node * new_Node(double val) {
     Node *pNode = malloc(sizeof pNode);

    if(!pNode) {
        printf("Failed to allocate memory.\n");
        
    }
    pNode -> value = val;
    pNode -> pNext = NULL;

    return pNode;
}

void insert_Into(Node *pNode, Node *pAppend) {
    if (pNode == NULL || pAppend == NULL) {
        printf("Error: One of the nodes is NULL.\n");
        return;
    }
    Node *pTemp = pNode->pNext;
    pNode->pNext = pAppend;
    pAppend->pNext = pTemp;
}

void print_List( Node *pHead) {
    while (pHead != NULL)
    {
        printf("Value: %f\n", pHead->value);
        pHead = pHead->pNext;
    }
    
}

int main() {
    srand(time(NULL));
    Node *phead = new_Node(0);
    for (int i = 50; i >0; i--) {
        insert_Into(phead, new_Node(i));
    }
    
    int arr[51];

    for (int i = 0; i < 50; i++) {
        arr[i] = rand();
    }
    
    for (int i = 4; i < 51; i++) {
        arr[i] = arr[i+1];
    }

    arr[3] = rand();

    

    insert_Into(phead->pNext, new_Node(100));
    
    print_List(phead);

    for (int i = 0; i < 51; i++)
    {
        printf("Array Value: %i\n", arr[i]);
    }
    

    free_List(phead);
}
