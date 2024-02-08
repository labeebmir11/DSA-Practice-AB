//Program to implement binary tree using C++
# include <iostream>

using namespace std;

class Node{
public:
    Node *lchild;
    int data;
    Node *rchild;    
};
class Queue
{
private:
    int size;
    int front;
    int rear;
    Node **Q; //pointer to pointer to node
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(Node *x); //inserting adress of node in the queue
    Node* dequeue(); // returning address of node deeted    

};
Queue::Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node*[size];
}
Queue::~Queue() {
    delete [] Q;
}
 
bool Queue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}
 
bool Queue::isFull() {
    if (rear == size-1){
        return true;
    }
    return false;
}
 
void Queue::enqueue(Node* x) {
    if (isFull()){
        cout << "Queue Overflow" << endl;
    } else {
        rear++;
        Q[rear] = x;
    }
}
Node* Queue:: dequeue() 
{
    Node *x = nullptr;
    if(isEmpty())
        cout<<"Queue underflow, nothing to delete"<<endl;
    else
    {
        front++;
        x  = Q[front];
    }    
    return x;
}  
 class Tree
 {
  public:
    Node *root; //Pointer to a node
    void CreateTree();
    void PreOrder(Node *p);
    void InOrder(Node *p);
    void PostOrder(Node *p);
    void LevelOrder(Node *p);
    int Height(Node *p);
 };
 void Tree:: CreateTree()
 {
    Node *newnode, *p;
    Queue q(100);
    int x;
    root = new Node;
    cout<<"Enter data for root node(-1 for no node)"<<endl;
    cin>>x;
    if(x != -1)
    {
        root->data = x;
        root->lchild = nullptr;
        root->rchild = nullptr;
    }
     q.enqueue(root);
    while(!q.isEmpty())
    {   
        p =  q.dequeue();
        cout<<"Enter left child of "<<p->data<<" "<<endl;
        cin>>x;
        if(x!= -1)
        {
            newnode = new Node;
            newnode->data = x;
            newnode->lchild = nullptr;
            newnode->rchild = nullptr;
            p->lchild = newnode;
            q.enqueue(newnode);
        }
    
        cout<<"Enter right child of "<<p->data<<" "<<endl;
        cin>>x;
        if(x!= -1)
        {
            newnode = new Node;
            newnode->data = x;
            newnode->lchild= nullptr;
            newnode->rchild = nullptr;
            p->rchild = newnode;
            q.enqueue(newnode);
        }
    }
 }

 void Tree:: PreOrder(Node *p) //node, left,right
 {
    if(p)
    {
        cout<<p->data<<", "<<flush;
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
 }

 void Tree:: InOrder(Node *p) //left, node, right
 {
    if(p)
    {
        InOrder(p->lchild);
        cout<<p->data<<", "<<flush;
        InOrder(p->rchild);
    }
 }

 void Tree:: PostOrder(Node *p) //left,right,node
 {
    if(p)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        cout<<p->data<<", "<<flush;
    }
 }

 void Tree:: LevelOrder(Node *p)
 {
    Queue q(100);
    cout<<root->data<<", "<<flush;
    q.enqueue(root);

    while(! q.isEmpty())
    {
        p = q.dequeue();
        if(p->lchild)
        {
            cout<<p->lchild->data <<", "<<flush;
            q.enqueue(p->lchild);
        }
        if(p->rchild)
        {
            cout<<p->rchild->data<<", "<<flush;
            q.enqueue(p->rchild);
        }
    }

 }

 int Tree:: Height(Node *p)
 {
    int l = 0, r = 0;
    if(p == nullptr)
        return -1;
    l = Height(p->lchild);
    r = Height(p->rchild);
    if(l > r)
        return l+1;
    else
        return r+1;     
 }

 int main()
 {
    Tree t;
    t.CreateTree();
    //t.PreOrder(t.root);
    //t.InOrder(t.root);
    //t.LevelOrder(t.root);
    cout<<"Height of the tree is: "<<t.Height(t.root)<<endl;
 }

 
