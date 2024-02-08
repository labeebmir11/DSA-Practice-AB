# include <stdio.h>
# include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root = NULL;

int NodeHeight(struct Node *p)
{
    int hl,hr;
    hl = p && p->lchild?p->lchild->height:0;
    hr = p && p->rchild?p->rchild->height:0;

    return hl>hr?hl+1:hr+1;
}

int BalanceFactor(struct Node *p)
{
    int hl,hr;
    hl = p && p->lchild?p->lchild->height:0;
    hr = p && p->rchild?p->rchild->height:0;

    return hl - hr;
}

struct Node* LLRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = p->lchild->rchild;
    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == p)
        root = pl;

    return pl;    
}

struct Node* RRRotation(struct Node *p)
{
    struct Node*pr = p->rchild;
    struct Node *prl = p->rchild->lchild;

    pr->lchild =p;
    p->rchild  = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if(root == p)
        root = pr;

    return pr;    
}

struct Node* LRRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = p->lchild->rchild;
    struct Node *plrl = p->lchild->rchild->lchild;
    struct Node *plrr = p->lchild->rchild->rchild;

    plr->rchild = pl;
    plr->rchild = p;
    p->lchild = plrr;
    pl->rchild = plrl;

    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if(root == p)
        root = plr;

    return plr;    
}

struct Node* RLRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = p->rchild->lchild;
    struct Node *prll = p->rchild->lchild->lchild;
    struct Node *prlr = p->rchild->lchild->rchild;

    prl->lchild = p;
    prl->rchild = pr;
    p->rchild = prll;
    pr->lchild = prlr;

    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    if(root == p)
        root = prl;

    return prl;    



}


struct Node* RInsert(struct Node *p, int key)
{
    struct Node *t = NULL;
    if(p == NULL)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;      //starting from 1 instead of 0, so depends on number of nodes
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = RInsert(p->rchild, key);

    p->height = NodeHeight(p); //for finding max height(from left and right subtree)

    if(BalanceFactor(p) == 2  && BalanceFactor(p->lchild)== 1) 
        return LLRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild)== -1)
        return RRRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild)== -1)
        return LRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild)== 1)
        return RLRotation(p);    
                    

    return p;    
}

struct Node* inordersucc(struct Node *p)
{
    struct Node *curr = p;
    while(curr && curr->lchild)
    {
        curr = curr->lchild;
    }
    return curr;
}

void inorder(struct Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d\t", p->data);
        inorder(p->rchild);
    }
}

struct Node* deleteAVL(struct Node *p, int key)
{
    struct Node *q = NULL;
    if(p->data < key)
        p->rchild = deleteAVL(p->rchild, key);
    else if(p->data > key)
        p->lchild = deleteAVL(p->lchild, key);
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
            q = inordersucc(p->rchild);
            p->data = q->data;
            p->rchild = deleteAVL(p->rchild, q->data);
            
            
        }
        
    }  
    return p;
    p->height = NodeHeight(p);
     if(BalanceFactor(p) == 2  && BalanceFactor(p->lchild)== 1) 
        return LLRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild)== -1)
        return RRRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild)== -1)
        return LRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild)== 1)
        return RLRotation(p);   
    else if(BalanceFactor(p)== 2 && BalanceFactor(p->lchild)== 0)
        return LLRotation(p);
    else if(BalanceFactor(p)== -2 && BalanceFactor(p->lchild)== 0)
        return RRRotation(p);       

    return p;    

}
int main()
{
    root = RInsert(root, 10);
    RInsert(root, 20);
    RInsert(root, 30);
    RInsert(root, 40);
    RInsert(root, 5);

    printf("\n");
    inorder(root);
    printf("\n");

    deleteAVL(root, 40);
    printf("\n");
    inorder(root);

    

    
}