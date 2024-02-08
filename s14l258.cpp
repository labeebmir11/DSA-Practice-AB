// Program to implement queue using array in C++
# include <iostream>

using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *A;
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void Display();        
};
Queue::Queue(int size)
{
    this->size = size;
    front = rear = -1;
    A = new int[size];
}
Queue::~Queue()
{
    delete []A;
}
bool Queue::isEmpty()
{
    if(front == rear)
        return true;
    return false;    
}
bool Queue::isFull() {
    if (rear == size-1){
        return true;
    }
    return false;
}
void Queue:: enqueue(int x)
{
    if(isFull())
        cout<<"Queue is full"<<endl;
    else
    {
        rear++;
        A[rear] = x;
    }    

}
int Queue::dequeue() {
    int x = -1;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        front++;
        x = A[front];
    }
    return x;
}
void Queue::Display()
{
    for(int i = front+1;i <=rear;i++)
    {
        cout<<A[i]<<" "<<flush; //flush prevents any delay in displaying the output
    }
    cout<<endl;
}
int main()
{
    int A[] = {1,3,5,7,9};
    int s = sizeof(A)/ sizeof(A[0]);   //for total number of elements in the array
    Queue q(s);
    for(int i = 0; i < s; i++ )
        q.enqueue(A[i]);
     q.dequeue();   
    q.Display(); 
}