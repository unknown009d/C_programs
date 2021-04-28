int q[5];
int front = -1, rear = -1;

void enqueue(int v)
{
    if (rear == 4)
    {
        printf("\nQueue is Full.");
    }
    else
    {
        if (front == -1)
        {
            front++;
        }
        rear++;
        q[rear] = v;
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("\nQueue is Empty.");
    }
    else
    {
        printf("\nDeleted Value : %d ", q[front]);
        front++;
        if (front == rear + 1)
        {
            front = -1;
            rear = -1;
        }
    }
}

void display()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
    }
    else
    {
        int x;
        printf("\nQueue Elements : \n");
        for (x = front; x < rear; x++)
        {
            printf("%d ", q[x]);
        }
    }
}
