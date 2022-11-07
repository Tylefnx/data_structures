#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 10;
/*
Queues (FIFO)

The basic operations on a queue
are enqueue which inserts on element
at the end of the queue (called rear)
and dequeue which deletes (and returns)
the element at the start of the queue
(known as front)

*/

// Implementation of Queue Data Structure
//  1-) Linked List Implementaion
/*
typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct
{
    int cnt;
    Node *front;
    Node *rear;
} Queue;

void initialize(Queue *q)
{
    q->cnt = 0;
    q->front = q->rear = NULL;
}

int isFull(Queue *q)
{
    if (q->cnt == 10)
        return 1;
    else
        return 0;
}

int isEmpty(Queue *q)
{
    if (q->cnt == 0)
        return 1;
    else
        return 0;
}

void enqueue(Queue *q, int x)
{
    if (isFull(q))
        printf("Queue is full");
    else
    {
        Node *temp = malloc(sizeof(Node));
        temp->data = x;
        temp->next = NULL;

        if (isEmpty(q))
            q->front = q->rear = temp;
        else {
            q->rear->next = temp;
            q->rear = temp;
        }
        ++(q->cnt);
    }
}

int dequeue(Queue *q){
    if (isEmpty(q)){
        printf("Its empty u blind fuq");
        return -100;
    }
    else {
        int x = q->front->data;
        Node *temp = q->front;
        q->front = q->front->next;
        free(temp);
        --(q->cnt);
        return x;
    }
}

int main(void)
{
    Queue *q = malloc(sizeof(Queue));
    initialize(q);
    enqueue(q, 31);
    enqueue(q, 30);
    enqueue(q, 29);
    enqueue(q, 28);
    printf("%d", q->front->data);
    return 0;
}
*/
// 1-) Array Implementation

typedef struct
{
    int cnt;
    int data[10];
    int rear, front;
} Queue;

int isFull(Queue *q)
{
    if (q->cnt == 10)
        return 1;
    else
        return 0;
}

int isEmpty(Queue *q)
{
    if (q->cnt == 0)
        return 1;
    else
        return 0;
}

void initialize(Queue *q)
{
    q->cnt = 0;
    q->front = 0;
    q->rear = -1;
}

void enqueue(Queue *q, int x)
{
    if (isFull(q))
        printf("It's full");
    else
    {
        q->rear++;
        q->cnt++;
        if (q->rear == 10)
        {
            q->rear = 0;
            q->data[q->rear] = x;
        }
        else
            q->data[q->rear] = x;
        // Circular array
    }
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty");
        return -100;
    }
    else
    {
        int x = q->data[q->front];
        q->front++;
        q->cnt--;
        if (q->front == 10)
            q->front = 0;
        return x;
    }
}
void printQueue(Queue *q)
{
    int cnt = 0, temp = q->front;
    while (cnt != q->cnt)
    {

        if (temp == 10)
        {
            temp = 0;
            printf("%d ", q->data[temp]);
            temp++;
            cnt++;
        }
        else
        {
            printf("%d ", q->data[temp]);
            temp++;
            cnt++;
        }
    }
}
int main(void)
{
    Queue *q = malloc(sizeof(Queue));
    initialize(q);
    enqueue(q, 31);
    enqueue(q, 30);
    enqueue(q, 29);
    enqueue(q, 28);
    enqueue(q, 55);
    enqueue(q, 55);
    enqueue(q, 55);
    enqueue(q, 55);
    dequeue(q);
    dequeue(q);
    enqueue(q, 55);
    enqueue(q, 55);
    enqueue(q, 55);
    enqueue(q, 55);

    printQueue(q);
}

/*

// Question
Write a func that prints all elements in a queue
which is implemented by arrays



*/