// This program contains all the functions related to a single, linear linked list
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

struct Node
{
    int data;
    struct Node *next;
}*first = NULL,*second=NULL,*third = NULL;

struct Node* Search(struct Node *p, int key)
{
    while(p!= NULL)
    {
        if(key == p->data)
            return p;
        p = p->next;
    }
    return NULL;

}

void InsertinSort(struct Node*p,int x )
{
    struct Node*newnode,*temp = first,*q = NULL;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    if(first == NULL || x < first->data)
    {
        newnode->data = x;
        newnode->next = first;
        first = newnode;
    }
    else
    {
        while(temp && temp->data < x)
        {   
            q = temp;
            temp = temp->next;
        }
        newnode->data = x;
        newnode->next = q->next;
        q->next = newnode;

    }
}


void create(int A[], int n)
{
    struct Node *temp,*newnode;
    
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    temp = first;
    for(int i = 1; i < n; i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = A[i];
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
    }
}


void create2(int A[], int n)
{
    struct Node *temp,*newnode;
    
    second = (struct Node*)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    temp = second;
    for(int i = 1; i < n; i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = A[i];
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
    }
}

void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
}

void RDisplay(struct Node *p)
{
    if(p!=NULL) //note that if has been used instead of while
    {
        printf("%d\t", p->data);
        RDisplay(p->next);
    }
}

int count(struct Node *p)
{
    int count = 0;
    while(p!=NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
int Rcount(struct Node *p)
{
    if(p == NULL)
        return 0;
    else
    return Rcount(p->next)+1;    
}

int Sum(struct Node *p)
{
    int sum = 0;
    while(p!=NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}
int Rsum(struct Node *p)
{
    if(p == NULL)
        return 0;
    else
        return p->data + Rsum(p->next);    
}

int max(struct Node *p)
{
    int m = INT_MIN;
    while(p!=NULL)
    {
        if(p->data > m)
        {
            m = p->data;
        }
        p = p->next;
    }
    return m;
}

int Rmax(struct Node *p)
{
    //base case
    if(p == NULL)
        return INT_MIN;
    
    int maxofRest = Rmax(p->next);
    return(p->data > maxofRest)?p ->data:maxofRest;        
}

int min(struct Node *p)
{
    int m = INT_MAX; //take int max for minimum because all other elements will be lesser than it. if we take min, it will always be lower than any other element
    while(p != NULL)
    {
        if(p->data < m)
            m = p->data;

        p = p->next;    
    }
    return m;
}
int Rmin(struct Node *p)
{
    if(p == 0)
        return INT_MAX;
    int minofRest = Rmin(p->next);
    return (p->data < minofRest)?  p->data : minofRest;    
}

struct Node* Search(struct Node *p, int key)
{
    while(p!= NULL)
    {
        if(key == p->data)
            return p;
        p = p->next;
    }
    return NULL;

}

struct Node* RecSearch(struct Node *p, int key)
{
    if(p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    return RecSearch (p->next, key);        
}

struct Node* tth_Search(struct Node *p, int key) // Transport to head
{
    struct Node *q = NULL;
    while(p!=NULL)
    {
        if(key == p->data)
        {   
            if(q!=NULL){
            q->next = p->next;
            p->next = first;
            first = p;}

            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

void Insert(struct Node *p, int pos, int x)
{
    struct Node*temp,*newnode;
    if(pos < 0 || pos> count(p))
        return;
     newnode = (struct Node*)malloc(sizeof(struct Node));
     newnode->data = x;
    if(pos == 0)   //inserting new node before  the first node
    {
        temp = first;
        newnode->next = first;
        first = newnode;
    }
    else if(pos > 0)  //inserting at any place after the first node
    {
        int i;
        temp = first;
        for(i = 1; i < pos && temp; i++)  //move the traversing pointer temp to the node after which the new node is to be inserted
            temp = temp->next;
        if(temp)
        {
            newnode->next = temp->next;
            temp->next = newnode;
        }    
    }
}

void InsertLast(struct Node *p, int x)
{
    struct Node*temp,*newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    temp = first;
    if(first == NULL)
    {   
        newnode->data = x; 
        newnode->next = NULL; 
        first = temp = newnode;
    }
    else
    {
        while(temp->next !=NULL)
    {
        temp = temp->next;
    }
        newnode->data = x;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
    }
}

void InsertinSort(struct Node*p,int x )
{
    struct Node*newnode,*temp = first,*q = NULL;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    if(first == NULL || x < first->data)
    {
        newnode->data = x;
        newnode->next = first;
        first = newnode;
    }
    else
    {
        while(temp && temp->data < x)
        {   
            q = temp;
            temp = temp->next;
        }
        newnode->data = x;
        newnode->next = q->next;
        q->next = newnode;

    }
}

int Delete(struct Node*p, int pos)
{   
    int x,i;
    struct Node*t = first, *q = NULL;
    if(pos < 1 || pos > count(p))
        return -1;     //invalid input
    if(pos == 1)
    {
        first = first->next;
        x = t->data;
        free(t);
    }   
    else
    {
        for(i = 1; i < pos && t!=NULL; i++)
        {
            q = t;
            t = t->next;
        }
        if(t)
        {
        q->next = t->next;
        x = t->data;
        free(t);
        }
    } 
    return x;
}

int CheckSorted(struct Node *p)  //self!
{
    struct Node*q=first,*temp = first->next;
    while(temp!=NULL)
    {
        if (q->data > temp->data)
            return -1; //not sorted
        else if(q->data < temp->data)
        {
            q = temp;
            temp = temp->next;
        }    
            
    }
    return 1; //array is sorted
}

int isSorted(struct Node*p)
{
    int x = INT_MIN;
    while(p!=NULL)
    {
        if(p->data < x)  //element of the linkedlist is smaller than the least integer
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

void RemoveDuplicate(struct Node*p) //removing duplicates from a sorted linked list      self!
{   
    
    struct Node*q=first,*temp = first->next;
    while(temp!=NULL)
    {
        if(q->data == temp->data)
        {
            q->next = temp->next;
            free(temp);
            temp = q->next;
        }
        else
        {
        q = temp;
        temp = temp->next;
        }
    }
    
}

void Reverse(struct Node *p)
{
    struct Node*prevnode = NULL, *currentnode = first, *nextnode = first;
    while(currentnode!=NULL)
    {
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    first = prevnode;

}
void SlidingReverse(struct Node*p) // p is not the first node, it doesnt make any change in first, it just points to the same location as first does
{
    struct Node*r,*q;
    r = q = NULL;
    p = first;
    while(p!=NULL)
    {
       r = q;
       q = p;
       p = p->next;
       q->next = r;
    }
    first = q;
}

void ReversebyArray(struct Node*p)
{   
    int i = 0;
    struct Node*q = first;  //for traversing the array
    int *A;
    A = (int*)malloc(sizeof(int) * count(p));
    while(q!=NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    //get q back to first and i to the last element of the array
    q = first; i--;
    while(q!=NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void RecursiveReverse(struct Node*q, struct Node*p)
{
    // q is the trailing pointer following p
    if(p!=NULL)
    {
        RecursiveReverse(p, p->next); //q becomes equal to p and p moves to next
        p->next = q;// this will happen at the time of returning from the recursive call
    }
    else  //if p =0
        first = q;
}

void Concatenate(struct Node*p, struct Node*q)
{
    while(p->next !=NULL)
    {
        p = p->next;
    }
    p->next = q;
    q  = NULL;
}

void MergeSorted(struct Node*p, struct Node*q)
{
    struct Node*last;
    if(first->data < second->data)
    {
        third = last = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        third,last = second;
        second = second->next;
        last->next = second;
    }

    while(first!=NULL && second!=NULL)
    {
        if(first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
        //for the remaining nodes:
        if(first!=NULL)last->next = first;
        else last->next = second;
    }
}

int isLoop(struct Node *p) // fnction to check if a linked list is a loop
//take two pointers and make one traverse the list faster than the other. if the list is a loop, the two pointers will become equal at some point just like a faster car meeting a slower one on a circular track. 
{
    struct Node*t= first ,*s= first;
    do
    {
       t = t->next;
       s = s->next;
       // s = (s!=NULL)?s->next : NULL;
       if(s!=NULL)
        s = s->next;
       else
        return 0; // no loop detected as one of the pointers has become zero 
        
    } while (t && s && t!=s); //while both loops are not NULL and if both are not equal. 
    if(t == s)
        return 1; //is a loop
    else
        return 0;
}
