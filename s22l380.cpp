//Program to implement bfs and dfs traversal of graph usinglinked list
# include <stdio.h>
# include <stdlib.h>

struct Node
{
 int data;
 struct Node *next;

}*front=NULL,*rear=NULL;

void enqueue(int x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("Queue is FUll\n");
    else
    {
        t->data=x;
        t->next=NULL;
        if(front==NULL)
            front=rear=t;
        else
        {
            rear->next=t;
            rear=t;
        }
    }

}

int dequeue()
{
    int x=-1;
    struct Node* t;

    if(front==NULL)
        printf("Queue is Empty\n");
    else
    {
        x=front->data;
        t=front;
        front=front->next;
        free(t);
    }
    return x;
}

int isEmpty()
{
    return front==NULL;
}

void BFS(int G[][7], int start, int n)
{   
    int visited[7] = {0};
    int u,v;
    int i = start;
    printf("%d\t", i);
    visited[i] = 1;
    enqueue(i);

    while(!isEmpty())
    {
        u = dequeue();
        for(v = 1; v < n; v++)
        {   
            if(G[u][v] == 1 && visited[v] == 0)
            {
                printf("%d\t", v);
                visited[v] = 1;
                enqueue(v);
            }
           
        }
    }

    
}

void DFS(int G[][7], int start, int n)
{
    int u = start;
    static int visited[7] = {0}; //static because it needs to stay constant across recursive calls

    if(visited[u] == 0)
    {
        printf("%d\t", u);
        visited[u] = 1;
    }
    for(int v = 1 ; v < n ; v++)
    {
        if(G[u][v] == 1 && visited[v] == 0)
            DFS(G, v, n);
    }
}

int main()
{
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

    BFS(G, 3, 7); 
    printf("\n");  
    DFS(G, 3, 7);            
}