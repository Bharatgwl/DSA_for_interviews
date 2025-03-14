#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct
{
    int arr[MAX];
    int top;

} stack;
void push(stack *s1, int data)
{
    if (s1->top == MAX - 1)
    {
        printf("satck overflow");
        return;
    }
    else
    {
        s1->top++;
        s1->arr[s1->top] = data;
    }
}
int top(stack *s1)
{
    if (s1->top == -1)
    {
        printf("stack is empty\n");
        return -1;
    }
    return s1->arr[s1->top];
}
int pop(stack *s1)
{
    if (s1->top == -1)
    {
        printf("stack underflow");
        return -1;
    }
    else
    {
        s1->top--;
        return s1->arr[s1->top + 1];
    }
}
int main()
{
    stack *s1;

    s1 = (stack *)malloc(sizeof(stack));
    s1->top = -1;
    push(s1, 1);
    push(s1, 2);
    push(s1, 3);
    push(s1, 4);
    push(s1, 5);
    push(s1, 6);
    push(s1, 7);
    push(s1, 8);
    push(s1, 9);
    push(s1, 10);
    pop(s1);
    pop(s1);
    pop(s1);
    pop(s1);
    pop(s1);
    pop(s1);
    pop(s1);
    pop(s1);
    pop(s1);
   
    printf("%d", top(s1));
}