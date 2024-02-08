//Program to implement double ended Queue using Array
# include <iostream>

using namespace std;

class DEQueue
{
private:
    int size;
    int front;
    int rear;
    int *Q;   
public:    
    DEQueue(int size);
    ~DEQueue();
    void display();
    void enqueuefront(int x);
    void enqueuerear(int x);
    int dequeueFront();
    int dequeueRear();
    bool isEmpty();
    bool isFull();

};
DEQueue:: DEQueue(int size)
{
    this->size = size;
    front = rear = -1;
    Q = new int[size];
}
DEQueue:: ~DEQueue()
{
    delete []Q;
}
bool DEQueue:: isEmpty()
{
    if(front == rear)
        return true;
    return false;    
}
bool DEQueue:: isFull()
{
    if(rear == size - 1)
        return true;
    else
        return false;    
}
void DEQueue:: enqueuefront(int x)
{
    if(front == -1)
        cout<<"Queue is full, element can't be added"<<endl;
    else
    {
        Q[front] = x;
        front--;
    }    
}
void DEQueue:: enqueuerear(int x)
{
    if(isFull())
        cout<<"Queue overflow"<<endl;
    else
    {
        rear++;
        Q[rear] = x;
    }    
    
}
int DEQueue:: dequeueFront()
{
    int x = -1;
    if(isEmpty())
        cout<<"Stack underflow, nothing to delete"<<endl;
    else
    {
        x = Q[front];
        front++;
    } 
    return x;   
}
int DEQueue::dequeueRear() {
    int x = -1;
    if (rear == -1){
        cout << "DEQueue Underflow" << endl;
    } else {
        x = Q[rear];
        rear--;
    }
    return x;
}


void DEQueue:: display()
{
    for(int i = front + 1 ; i <= rear; i++)
        cout<<Q[i]<<" ";
    cout<<endl;    
}

int main()
{
     int A[] = {1, 3, 5, 7, 9};
     int B[] = {2, 4, 6, 8};

     DEQueue deq(sizeof(A)/sizeof(A[0]));
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.enqueuerear(A[i]);
    }
    deq.display();
    deq.enqueuerear(11);
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.dequeueFront();
    }
    deq.dequeueFront();
 
    cout << endl;
 
    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.enqueuefront(B[i]);
    }
    deq.enqueuefront(10);
    deq.display();
    deq.enqueuefront(12);
    
    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.dequeueRear();
    }
    deq.display();
    deq.dequeueRear();
    deq.dequeueRear();
}
