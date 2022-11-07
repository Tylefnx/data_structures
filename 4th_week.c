#include <stdio.h>
#include <stdlib.h>
/*

// DELETE A NODE


struct node
{
    int data;
    struct node *next;
};

typedef struct node Node;

Node *createList();
Node *deleteFirst(Node *head);
Node *delete (Node *head, int x);
void deleteLast(Node *head);
void printList(Node *head);
Node *destroy(Node *head);

int main()
{
    Node *head = createList();
    head = destroy(head);
    printList(head);
}

Node *createList()
{
    Node *val1 = malloc(sizeof(Node));
    Node *val2 = malloc(sizeof(Node));
    Node *val3 = malloc(sizeof(Node));
    Node *val4 = malloc(sizeof(Node));
    Node *val5 = malloc(sizeof(Node));

    val1->data = 1;
    val2->data = 2;
    val3->data = 3;
    val4->data = 4;
    val5->data = 5;

    val1->next = val2;
    val2->next = val3;
    val3->next = val4;
    val4->next = val5;
    val5->next = NULL;

    return val1;
};

Node *deleteFirst(Node *head)
{
    Node *temp = head->next;
    free(head);
    head = temp;
    return head;
}

void printList(Node *head)
{
    for (Node *temp = head; temp != NULL; temp = temp->next)
        printf("%d\n", temp->data);
    return;
}
void deleteLast(Node *head)
{
    Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    Node *deleted = temp->next;
    free(deleted);
    temp->next = NULL;
    return head;
}

Node *delete (Node *head, int x)
{
    Node *temp;
    Node *deleted;

    if (head->data == x)
    {
        temp = head->next;
        free(head);
        head = temp;
        return head;
    }
    else
    {
        for (temp = head; temp->next != NULL; temp = temp->next)
        {
            if (temp->next->next == NULL && temp->next->data == x)
            {
                free(temp->next);
                temp->next = NULL;
                return head;
            }
            else if (temp->next->data == x)
            {
                deleted = temp->next;
                temp->next = deleted->next;
                free(deleted);
                return head;
            }
        }
    }
}

Node *destroy(Node *head)
{
    if (head == NULL)
        return NULL;
    destroy(head->next);
    free(head);
    return NULL;
}
*/
// DOUBLE LINKED LISTS

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

typedef struct node Node;
Node *createList();
Node *addFront(Node *head, int x);
Node *addLast(Node *head, int x);
Node *delete (Node *head, int x);
void printList(Node *head);

int main()
{
    Node *head = createList();
    head = delete (head, 5);
    printList(head);
}

Node *addFront(Node *head, int x)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = x;
    temp->next = head;

    if (head != NULL)
        head->prev = temp;
    head = temp;
    return head;
}

Node *addLast(Node *head, int x)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;

    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
    }
    else
    {
        Node *last = head;
        while (last->next != NULL)
            last = last->next;
        temp->prev = last;
        last->next = temp;
    }
    return head;
}

void printList(Node *head)
{
    for (Node *temp = head; temp != NULL; temp = temp->next)
        printf("%d\n", temp->data);
}

Node *createList()
{
    Node *val1 = malloc(sizeof(Node));
    Node *val2 = malloc(sizeof(Node));
    Node *val3 = malloc(sizeof(Node));
    Node *val4 = malloc(sizeof(Node));
    Node *val5 = malloc(sizeof(Node));

    val1->data = 1;
    val2->data = 2;
    val3->data = 3;
    val4->data = 4;
    val5->data = 5;

    val1->next = val2;
    val2->next = val3;
    val3->next = val4;
    val4->next = val5;
    val5->next = NULL;

    val5->prev = val4;
    val4->prev = val3;
    val3->prev = val2;
    val2->prev = val1;
    val1->prev = NULL;

    return val1;
};

Node *delete (Node *head, int x)
{
    if (head != NULL)
    {
        Node *temp = head;
        if (head->data == x)
        {
            head = head->next;
            free(temp);
            head->prev = NULL;
        }
        else
        {
            while (temp->data != x && temp != NULL)
                temp = temp->next;

            if (temp == NULL)
                return head;
            else
            {
                if (temp->next == NULL)
                {
                    temp->prev->next = NULL;
                    temp->next->prev = NULL;
                    return head;
                }

                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                return head;
            }
        }
    }
}

/*
// CIRCULAR LINKED LIST
struct node
{
    int data;
    struct node *next;
};

typedef struct node Node;

Node *createList()
{
    Node *val1 = malloc(sizeof(Node));
    Node *val2 = malloc(sizeof(Node));
    Node *val3 = malloc(sizeof(Node));
    Node *val4 = malloc(sizeof(Node));
    Node *val5 = malloc(sizeof(Node));

    val1->data = 1;
    val2->data = 2;
    val3->data = 3;
    val4->data = 4;
    val5->data = 5;

    val1->next = val2;
    val2->next = val3;
    val3->next = val4;
    val4->next = val5;
    val5->next = val1;

    return val1;
};

Node *addfront(Node *head, int x)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = x;
    if (head == NULL)
    {
        temp->next = temp;
        head = temp;
    }
    else
    {
        temp->next = head;
        Node *last = head;
        while (last->next != head)
            last = last->next;
        last->next = temp;
        head = temp;
    }
    return head;
}

void printList(Node* head){
    Node* temp = head;
    while(temp->next != head){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int main(){
    Node* head = createList();
    head = addfront(head, 31);
    printList(head);
}
*/