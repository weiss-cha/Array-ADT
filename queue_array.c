#include <stdio.h>
#include <stdbool.h>
#define SIZE 5

void queue_init();
bool empty();
void enqueue(int);
void dequeue();
int front();
int rear();
bool is_full();

int i;
int j;
int f = -1, r = -1;
int queue[SIZE];

int main(void)
{
    while (1)
    {
        printf("Enter the value:");
        scanf("%d", &i);

        if(i > 0)
        {
            enqueue(i);
        }

        else if(i < 0)
        {
            if(empty())
            {
                printf("\"Error - Queue is empty\"\n");
            }

            else
            {
                printf("Front: %d\n", front());
                printf("Rear: %d\n", rear());
            }
        }

        else
        {
            if(empty())
            {
                printf("\"Error - Queue is empty\"\n");
            }

            else
            {
                dequeue();
            }
        }
    }

    return 0;
}

void queue_init()
{
    r = f = -1;
}

bool empty()
{
    return r == -1;
}

void enqueue(int val)
{
    if(empty())
    {
        r = f = 0;
    }

    else
    {
        j = r;
        r = r + 1;

        if(r == SIZE)
        {
            r = 0;
        }

        if(is_full())
        {
            printf("\"Error - Queue is full\"\n");
            r = j;
            return;
        }
    }

    queue[r] = val;
}

void dequeue()
{
    if(r == f)
    {
        r = f = -1;
    }

    else
    {
        f = f + 1;

        if(f == SIZE)   
        {
            f = 0;
        }
    }
}

int front()
{
    return queue[f];
}

int rear()
{
    return queue[r];
}

bool is_full()
{
    return f == r;
}
