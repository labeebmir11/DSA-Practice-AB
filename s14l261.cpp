//Program to implement circular CirQueue using array
# include <stdio.h>
# include <stdlib.h>

struct CirQueue
{
    int size;
    int front;
    int rear;
    int *A;
};
void create(struct CirQueue *q)
{
    printf("Enter size of CirQueue\n");
    scanf("%d",&q->size);
    q->front = q->rear = 0;
    q->A = (int*)malloc(sizeof(int)*q->size);

}
void enqueue(struct CirQueue *q, int x)
{
    if((q->rear+1)%q->size == q->front)  //if array is full
        printf("CirQueue is full, can't add element\n");
    else
    {
        q->rear = (q->rear+1)%q->size ;//elements are added from the rear just like people in a CirQueue and deleted from the front
        q->A[q->rear] = x;
    }    
}
int dequeue(struct CirQueue *q)   //elements are always deleted from the front of the CirQueue
{   
    int x = -1;
    if(q->front == q->rear)
        printf("CirQueue is empty, nothing to delete\n");
    else
    {
        q->front = (q->front + 1)%q->size;
        x = q->A[q->front];
    } 
    return x;   
}

void Display(struct CirQueue q)
{   
    if(q.front == q.rear) 
        printf("CirQueue is empty\n");
    else
    {
        int i = q.front + 1;
        do
        {
           printf("%d\t",q.A[i]);
           i = (i+1)%q.size;
        } while (i!=(q.rear+1)%q.size);
        
    }
        printf("\n");
}
int isEmpty(struct CirQueue q)
{
    if(q.front == q.rear)
        return 1; //is empty
    else
        return 0; //not empty    
}
int isFull(struct CirQueue q)
{
    if((q.rear+1)%q.size == q.front)
        return 1; //is full
    else
        return 0;    
}
int main()
{
    struct CirQueue q;
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