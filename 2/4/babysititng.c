#include<stdio.h>
#include<Stdlib.h>
#define SIZE 40
struct queue{
    int items[SIZE];
    int front;
    int rear;
};
struct queue* create_queue()
{
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->front=-1;
    q->rear=-1;
    return q;
}
int isempty(struct queue* q)
{
    if(q->rear==-1)
        return 1;
    return 0;
}
void enqueue(struct queue* q,int value)
{
    if(q->front==-1)
            q->front=0;
    q->rear++;
    q->items[q->rear]=value;
}
int dequeue(struct queue* q)
{
    int item;
    if(isempty(q))
        return -1;
    else
    {
        item=q->items[q->front];
        q->front++;
        if(q->front>q->rear)
        {
            q->front=q->rear=-1;
        }
        return item;
    }
}
typedef struct Node{
    int data;
    struct Node* next;
}node;

struct Graph{
    int V;
    node** adjlist;
    int* visited;
};

struct Node* make_new_node(int dest)
{
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=dest;
    new_node->next=NULL;
    return new_node;
}

struct Graph* make_graph(int V)
{
    struct Graph* graph=malloc(sizeof(struct Graph));
    graph->V=V;
    graph->adjlist=malloc(V*sizeof(node));
    graph->visited=malloc(V*sizeof(int));

    for(int i=0;i<V;i++)
    {
        graph->adjlist[i]=NULL;
        graph->visited[i]=0;
    }
    return graph;
}

void add_edge(struct Graph* graph,int src,int dest)
{
    node* new_node=make_new_node(dest);
    new_node->next=graph->adjlist[src];
    graph->adjlist[src]=new_node;

    new_node=make_new_node(src);
    new_node->next=graph->adjlist[dest];
    graph->adjlist[dest]=new_node;
}

void print_graph(struct Graph* graph)
{
    int v; 
    for (v = 0; v <graph->V; ++v) 
    { 
        node* pCrawl = graph->adjlist[v]; 
        printf("\n Adjacency list of vertex %d\n head ", v+1); 
        while (pCrawl) 
        { 
            printf("-> %d", pCrawl->data+1); 
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 
    }
}
int bfs(struct Graph* graph, int start_vertex)
{
    struct queue* q=create_queue();
    int class=start_vertex+1;
    int count=1;
    graph->visited[start_vertex]=class;
    enqueue(q,start_vertex);
    while(!isempty(q))
    {
        int current_vertex=dequeue(q);
        node* temp=graph->adjlist[current_vertex];
        printf("Visited %d temp_data-> %d queue->", current_vertex+1,temp->data+1);
        while(temp)
        {
            int adjvertex=temp->data;
            if(graph->visited[adjvertex]==0)
            {
                count++;
                printf("%d ",adjvertex+1);
                graph->visited[adjvertex]=class;
                enqueue(q,adjvertex);
            }
            temp=temp->next;
        }
        printf("\n");
    }
    return count;
}
int main()
{
    int V,edge;
    scanf("%d %d",&V,&edge);
    struct Graph* graph=make_graph(V);

    int d1,d2;
    for(int i=0;i<edge;i++)
    {
        scanf("%d %d",&d1,&d2);
        add_edge(graph,d1-1,d2-1);
    }
    print_graph(graph); 
    for(int i=0;i<V;i++)
    {
        printf("%d ",graph->visited[i]);
    }
    printf("\n");
    int MAX=0,count,index;
    for(int i=0;i<V;i++)
    {
        if(graph->visited[i]==0 && graph->adjlist[i]!=NULL)
        {
            printf("Starting BFS on %d\n",i+1);
            count=bfs(graph,i);
            if(count>MAX)
            {
                MAX=count;
                index=i+1;
            }
        }
            
    }
    printf("%d %d\n",MAX,index);
    for(int i=0;i<V;i++)
    {
        if(graph->visited[i]!=index)
            printf("%d ",i+1);
    }
    printf("\n");
    for(int i=0;i<V;i++)
    {
        printf("%d ",graph->visited[i]);
    }
    return 0;
}