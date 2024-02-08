// Stack using Linked list in C++
# include <iostream>

using namespace std;
class Node
{
 public:   
    int data;
    Node*next;
};


class Stack
{
private:
    Node *top; 
public:
    Stack();
    ~Stack();

    void push(int x);
    int pop();
    int peek(int index);
    void Display();



};
Stack::Stack()
{
    top = nullptr;
}
Stack:: ~Stack()
{
    Node *p = top;
    while(top)
    {
        top = top->next;
        delete p;
        p = top;
    }
}
void Stack:: push(int x)
{
    Node *newnode = new Node;
    if(newnode == NULL)
        cout<<"Stack Overflow"<<endl;
    else
    {
        newnode->data = x;
        newnode->next = top;
        top = newnode;
    }    

}

int Stack::pop()
{
    Node* p;
    int x = -1;
    if (top == nullptr){
        cout << "Stack Underflow!, no element available" << endl;
    } else {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}
void Stack::Display()
{
    Node*p = top;
    if(top == nullptr)
        cout<<"Stack is empty"<<endl;
    else
    {
        while(p!=nullptr)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
    cout<<endl;
    }    
}
int Stack:: peek(int index)
{   
    Node*p = top;
    if(top == nullptr){
        cout<<"Stack is empty"<<endl;
        return -1;}
    for(int i = 1; p!=nullptr && i < index; i++ )
    {
     p = p->next;
    }  
    if (p!=nullptr)
    {
        return p->data;
    } 
    return -1;
}

int main()
{
    int A[] = {1,3,5,7,9};
    Stack s;

    //Populate stack
    //for(int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
       // s.push(1);

    // Display stack
    s.Display();  

    // peek
    cout<<"Stack peek at 3rd: "<<s.peek(3)<<endl;

    //pop
    cout<<"Popping the top element deletes: "<<s.pop();

    //Display after popping
    s.Display();  
}
