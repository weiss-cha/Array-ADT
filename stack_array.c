#include <stdio.h>
#include <stdbool.h>
#define SIZE 5

void stack_init();
bool empty();
void push(int);
void pop();
int top();
bool is_full();

int i;
int t = -1;
int stack[SIZE];

int main(void)
{
    while (1)
    {
        printf("Enter the value:");
        scanf("%d", &i);

        if(i > 0)
        {
            push(i);
        }

        else if(i < 0)
        {
            if(empty())
            {
                printf("\"Error - Stack is empty\"\n");
            }

            else
            {
                printf("%d\n", top());
            }
        }

        else
        {
            if(empty())
            {
                printf("\"Error - Stack is empty\"\n");
            }

            else
            {
                pop();
            }
        }
    }

    return 0;
}

void stack_init()
{
    t = -1;
}

bool empty()
{
    return t == -1;
}

void push(int val)
{
    if(is_full())
    {
        printf("\"Error - Stack is full\"\n");
    }

    else
    {
        t = t + 1;
        stack[t] = val;
    }
}

void pop()
{
    t = t - 1;
}

int top()
{
    return stack[t];
}

bool is_full()
{
    return t == SIZE - 1;
}