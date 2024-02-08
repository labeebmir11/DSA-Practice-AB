//Program to implement queue using array
# include <stdio.h>
# include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *A;
};
void create(struct Queue *q)
{
    printf("Enter size of Queue\n");
    scanf("%d",&q->size);
    q->front = q->rear = -1;
    q->A = (int*)malloc(sizeof(int)*q->size);

}
void enqueue(struct Queue *q, int x)
{
    if(q->rear == q->size - 1)  //if array is full
        printf("Queue is full, can't add element\n");
    else
    {
        q->rear++; //elements are added from the rear just like people in a queue and deleted from the front
        q->A[q->rear] = x;
    }    
}
int dequeue(struct Queue *q)   //elements are always deleted from the front of the queue
{   
    int x = -1;
    if(q->front == q->rear)
        printf("Queue is empty, nothing to delete\n");
    else
    {
        q->front++;
        x = q->A[q->front];
    } 
    return x;   
}

void Display(struct Queue q)
{   
    if(q.front == q.rear) 
        printf("Queue is empty\n");
    else
    //elements in an array are present from the q->front+1 to q->rear
        for(int i = q.front + 1; i <= q.rear; i++)
        {
            printf("%d\t", q.A[i]);
        }   
        printf("\n");
}
int isEmpty(struct Queue q)
{
    if(q.front == q.rear)
        return 1; //is empty
    else
        return 0; //not empty    
}
int isFull(struct Queue q)
{
    if(q.rear == q.size - 1)
        return 1; //is full
    else
        return 0;    
}
int main()
{
    /*struct Queue q;
    create(&q);
    enqueue(&q,1);enqueue(&q,3);enqueue(&q,5);enqueue(&q,7);
    Display(q);
    dequeue(&q);
    Display(q);*/
     struct Queue q;
    create(&q);
    enqueue(&q,1);enqueue(&q,3);enqueue(&q,5);enqueue(&q,7);
    Display(q);
    dequeue(&q);
    dequeue(&q);
    Display(q);
    enqueue(&q,1);enqueue(&q,3);
    Display(q);
    dequeue(&q);dequeue(&q);dequeue(&q);dequeue(&q);
    Display(q);
    enqueue(&q,1);
    Display(q);
}