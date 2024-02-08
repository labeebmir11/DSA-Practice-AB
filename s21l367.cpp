# include <stdio.h>
# include <stdlib.h>

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

void InsertinSort(struct Node*p, int x )
{
    struct Node* newnode, *temp = p, *q = NULL;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->next = NULL;
    if (p == NULL || x < p->data)
    {
        newnode->next = p;
        p = newnode;
    }
    else
    {
        while (temp && temp->data < x)
        {
            q = temp;
            temp = temp->next;
        }
        newnode->next = q->next;
        q->next = newnode;
    }
}

int hash(int key)
{
    return key % 10;    //key % size
}

void InsertinHT(struct Node *H[], int key)
{
    int index = hash(key);
    
    // If the slot is empty, create a new node
    if (H[index] == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = key;
        newNode->next = NULL;
        H[index] = newNode;
    } else {
        // If the slot is not empty, insert the new node using InsertinSort()
        InsertinSort(H[index], key);
    }
}

void DeleteFromHT(struct Node *H[], int key) {
    int index = hash(key);
    struct Node *p = H[index];
    struct Node *q = NULL;
    
    // If the list is empty
    if (p == NULL) {
        printf("Key not found\n");
        return;
    }
    
    // If the first node is the one to delete
    if (p->data == key) {
        H[index] = p->next;
        free(p);
        return;
    }
    
    // Traverse the list to find the node to delete
    while (p != NULL && p->data != key) {
        q = p;
        p = p->next;
    }
    
    // If the node is not found
    if (p == NULL) {
        printf("Key not found\n");
        return;
    }
    
    // Delete the node
    q->next = p->next;
    free(p);
}


int main()
{   
    struct Node *m;
    struct Node *HT[10];  //array of pointers to struct Node
    int i;

    for(i = 0; i < 10; i++)
        HT[i] = NULL;
    
    InsertinHT(HT,12);
    InsertinHT(HT,22);  
    InsertinHT(HT,42);
   
    m = Search(HT[hash(22)], 22);

    if (m != NULL) {
        printf("%d\t", m->data);
    } else {
        printf("Key not found\n");
    }
    
    // Testing delete function
    printf("Deleting 22\n");
    DeleteFromHT(HT, 22);

    // Searching for the deleted key
    m = Search(HT[hash(22)], 22);
    if (m != NULL) {
        printf("%d\t", m->data);
    } else {
        printf("Key not found\n");
    }

    return 0;
}