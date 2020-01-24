#include<stdio.h>
#include<stdlib.h>
#define SIZE 40
struct queue
{
    int front,rear;
    int items[SIZE];
};
struct queue* create_queue()
{
    struct queue* q=malloc(sizeof(struct queue));
    q->front=-1;
    q->rear=-1;
    return q;
}
int isempty(struct queue *q)
{
    if(q->rear==-1)
        return 1;
    return 0;
}
void push(struct queue *q, int data)
{
    if(q->front==-1)
        q->front=0;
    q->rear++;
    q->items[q->rear]=data;
}
int pop(struct queue *q)
{
    int item;
    if(isempty(q))
        return -1;
    else
    {
        item=q->items[q->front];
        q->front++;
        if(q->front>q->rear)
            q->front=q->rear=-1;
        return item;
    }
}

typedef struct Node
{
    struct Node* next;
    int data;
}node;

struct Graph
{
    int V;
    node** adjlist;
    int* visited;
};
node* create_node(int data)
{
    node* new_node=malloc(sizeof(node));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}
struct Graph* create_graph(int V)
{
    struct Graph* graph=malloc(sizeof(struct Graph));
    graph->V=V;
    graph->adjlist=malloc(V*sizeof(node));
    graph->visited=malloc(V*sizeof(int));
    for(int i=0;i<V;i++)
    {
        graph->visited[i]=0;
        graph->adjlist[i]=NULL;
    }
        
    return graph;
}
void add_edges(struct Graph* graph,int src,int dest)
{
    node* new_node=create_node(dest);
    new_node->next=graph->adjlist[src];
    graph->adjlist[src]=new_node;
    
    //Unidirectional Connection
    // new_node=create_node(src);
    // new_node->next=graph->adjlist[dest];
    // graph->adjlist[dest]=new_node;
    
}
void print_graph(struct Graph* graph)
{
    for(int i=0;i<graph->V;i++)
    {
        printf("\n Adjacency list of vertex %d\n head ", i+1); 
        node* pCrawl = graph->adjlist[i]; 
        
        while (pCrawl) 
        { 
            printf("-> %d", pCrawl->data+1); 
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 

    }
}
int bfs(struct Graph* graph, int vertex)
{
    struct queue* q=create_queue();
    graph->visited[vertex]=1;
    int count=1;
    push(q,vertex);
    while(!isempty(q))
    {
        int current_vertex=pop(q);
        node* temp=graph->adjlist[current_vertex];
        while(temp)
        {
            int adjvertex=temp->data;
            if(graph->visited[adjvertex]==0)
            {
                count++;
                graph->visited[adjvertex]=1;
                push(q,adjvertex);
            }
            temp=temp->next;
        }
    }
    return count;
}
void clear_visited(struct Graph* graph)
{
    for(int i=0;i<graph->V;i++)
    {
        graph->visited[i]=0;
    }
}
int main()
{
    int V,edges;
    scanf("%d %d",&V,&edges);
    struct Graph* graph=create_graph(V);
    int d1,d2;
    for(int i=0;i<edges;i++)
    {
        scanf("%d %d",&d1,&d2);
        add_edges(graph,d1-1,d2-1);
    }
    printf("F\n");
    print_graph(graph);
    int count=0;
    for(int i=0;i<V;i++)
    {
        if(graph->visited[i]==0)
        {
            count+=bfs(graph,i);
        }
        if(count==V)
        {
            
        }
        // count=bfs(graph,i);
        // clear_visited(graph);
        // if(count==V)
        // {
        //     printf("%d",i+1);
        //     break;
        // }
    }
    if(count==-1)
        printf("BAD LUCK");
    
}