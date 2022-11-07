// STACK:
// A stack is a container of objects that are inserted and removed according to the last-in-first out principle
// think about push & pop in flutter

#define STACKSIZE 10
// Implementation of Stacks
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char data;
    struct node *next;
} Node;

typedef struct
{
    int cnt;
    Node *top;

} Stack;

void initialize(Stack *stk)
{
    stk->cnt = 0;
    stk->top = NULL;
}

void push(Stack *stk, char c)
{
    if (stk->cnt == STACKSIZE)
        printf("\nStack is full");
    else
    {
        Node *temp = malloc(sizeof(Node));
        temp->data = c;
        temp->next = stk->top;
        stk->top = temp;
        stk->cnt++;
    }
}

int pop(Stack *stk)
{
    if (stk->cnt == STACKSIZE)
        printf("\nStack is full");
    else
    {
        int x = stk->top->data;
        Node *temp = stk->top;
        stk->top = stk->top->next;
        free(temp);
        return x;
    }
    return 0;
}

/*
void main(){
    Stack *stk = malloc(sizeof(Stack));
    initialize(stk);
    push(stk, 31);
    push(stk, 32);
    push(stk, 44);
    push(stk, 55);
    push(stk, 99);
    pop(stk);
    printf("%d", stk->top->data);
}
*/

/*
void main(){
    Stack n;
    initialize(&n);
    push(&n, 4);
    push(&n, 14);
    push(&n, 41);
    push(&n, 6);
    printf("\n%d", pop(&n));
    printf("\n%d", pop(&n));
    printf("\n%d", pop(&n));
    printf("\n%d", pop(&n));
}
*/

// Array Implementations
/*
typedef struct
{
    int top;
    int data[STACKSIZE]
} Stack;

void reset(Stack *stk)
{
    stk->top = -1;
}

void push(Stack *stk, int c)
{
    if (stk->top = STACKSIZE - 1)
        printf("\nStack is full");
    else
    {
        stk->top++;
        stk->data[stk->top] = c;
    }
    stk->data[++(stk->top)]; // ERROR
}

void pop(Stack *stk)
{
    if (stk->top == -1)
    {
        printf("\nStack is empty");
        return -100;
    }
    else
    {
        int x = stk->data[stk->top];
        stk->top--;
        return x;
    }
    return stk->data[stk->top--];
}
*/

// Applications of Stacks in Computers

// Recursive functions...
// Infix, Prefix, Postfix
// Operators: +,-,/,*,^
// Operands: A,B,C,etc

// Infix            Prefix          Postfix
// A+B-C            -+ABC           AB+C-
// A-B/(C*D^E)      -A/B*C^DE       ABCDE^*/-

// Evaluate the following postfix expressions using stack

// HOEWORK: 32 * 56* + (implement it in a stack)

// Compilers Check Programs for Syntax Errors
// but only using paranthesis :))

// Homework

void main()
{
    Stack *stk = malloc(sizeof(Stack));
    initialize(stk);

    push(stk, 3);
    push(stk, 2);
    push(stk, "*");
    push(stk, 5);
    push(stk, 6);
    push(stk, "*");
    // push(stk, "+");
    while (stk->cnt != 0)
    {
        char temp = stk->top->data;

        // switch ()
        // {
        // case /* constant-expression */:
        //     /* code */
        //     break;
        
        // default:
        //     break;
        // }
    }
}