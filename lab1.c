#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}; // Creating a simple node structure

typedef struct node Node; // This is for calling the struct data as a Node instead of calling struct node autistically.

// Creating prototype functions
Node *createList(); // List creating function
void addFront(Node *head, Node *node); 
Node* addBack(Node *head, Node *node); // Returning a head value because head value is being updated.

void main() {
    Node *head = createList();

    Node* node = malloc(sizeof(Node));
    node->data = 35;
    
    int ch;
    
    printf("1-) Add Front\n2-)Add Back\n3-)Print\n4-)Print Reverse\n\nEnter your choice: ");
    scanf("%d", &ch);

    switch (ch) {
    case 1:
        addFront(head,node);
        break;
    case 2:
        addBack(head,node);
        break;
    case 3:
        printList(head);
        break;
    case 4:
        printReverse(head);
        break;
    default:
        break;
    }


    head = addBack(head, node);
    
    printList(head); 
}

Node *createList() {
    Node *head = malloc(sizeof(Node));
    Node *node1 = malloc(sizeof(Node));
    Node *node2 = malloc(sizeof(Node));
    Node *node3 = malloc(sizeof(Node));

    head->data = 31;
    head->next = node1;

    node1->data = 32;
    node1->next = node2;

    node2->data = 33;
    node2->next = node3;

    node3->data = 34;
    node3->next = NULL;
    
    return head;
}

void addFront(Node *head, Node *node) {
    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = node;
}

Node* addBack(Node *head, Node *node) {
    node->next = head;
    return node;
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void printReverse(Node *head) {
    Node* temp = head;
    if (temp != NULL){
        printReverse(temp->next);
        printf("%d\n", temp->data);
    } else return;
}