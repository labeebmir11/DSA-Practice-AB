//Coding a Binary Search Tree, if the code isnt working try running in gdb onine
# include <stdio.h>
# include <stdlib.h>

struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}*root = NULL;
void Insert(int key)
{
    struct Node *t  = root; //for traversal
    struct Node *q = NULL; //tailing pointer for t
    struct Node *newnode; //creating a new node

    if(root == NULL)
    {   
        root = (struct Node *)malloc(sizeof(struct Node));
        root->data = key;
        root->lchild = root->rchild = NULL;
        t = root;
    }
    else{
        while(t!=NULL)
        {
            q = t;
            if(t->data == key)
                return;
            else if(t->data < key)
                t = t->rchild;
            else
                t = t->lchild;        
        }
        //till the loop is completed t becomes NULL
        newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = key;
        if(newnode->data < q->data)q->lchild= newnode;
        else
            q->rchild = newnode;
    }
}

struct Node* RecInsert(struct Node *p, int key)
{   
    struct Node *newnode;
    if(p == NULL)
    {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = key;
        newnode->lchild = newnode->rchild = NULL;
        return newnode;
    }
    else if(p->data < key)
        p->rchild = RecInsert(p->rchild,key);
    else
        p->lchild = RecInsert(p->lchild, key); 
        
    return p;    //important
}

void Inorder(struct Node *p)    //left, node, child
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d\t", p->data);
        Inorder(p->rchild);
    }
}

struct Node* search(struct Node *p, int key)
{
    struct Node *t = p;
    while(t!=NULL)
    {
        if(t->data > key)
            t = t->lchild;
        else if(t->data < key)
            t = t->rchild;
        else if(t->data == key)
            return t;        
    }
    return NULL;
}

struct  Node* inordersucc(struct Node *p) //pass p->right as argument
{
    struct Node *curr = p;
    while(curr && curr->lchild)
    {
        curr = curr->lchild; //because inorder successor is the leftmost child of the right subtree
    }
    return curr;
}

struct Node* inorderpre(struct Node *p) //pass p->left as argument 
{
    struct Node*curr = p;
    while(curr && curr->rchild)
    {
        curr = curr->rchild; //inorder predecessor is the rightmost child of the left subtree
    }
    return curr;
}

struct Node* RecSearch(struct Node *p, int key)
{
    if(p == NULL)
        return NULL;
    else
    {
        if(p->data > key)
           return RecSearch(p->lchild, key);
        else if(p->data < key)
            return RecSearch(p->rchild, key);
        else
            return p;        
    }    
}
struct Node* deleteBS(struct Node *p, int key)
{
    struct Node *q = NULL;
    if(p->data < key)
        p->rchild = deleteBS(p->rchild, key);
    else if(p->data > key)
        p->lchild = deleteBS(p->lchild, key);
    else
    {
        if(p->lchild == NULL)
        {
            q = p->rchild;
            free(p);
            return q;
        }
        else if(p->rchild == NULL)
        {
            q = p->lchild;
            free(p);
            return q;
        }
        else
        {
            //we need to access the inorder predecessor or the inorder successor
            q = inordersucc(p->rchild);
            p->data = q->data;
            p->rchild = deleteBS(p->rchild, q->data);

            
        }
    }    
    return p;
}

int main()
{
    Insert(1);Insert(7);root=RecInsert(root,3);root=RecInsert(root,2);Insert(4);Insert(20);Insert(5);Insert(9);
    Inorder(root);
    struct Node *s =  RecSearch(root,7);
    if(s!=NULL)printf("\nElement %d is found\n", s->data);
    else
        printf("Not found\n");
    deleteBS(root,4);
    Inorder(root);
}