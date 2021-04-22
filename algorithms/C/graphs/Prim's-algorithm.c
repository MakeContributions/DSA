/*                                                               Prim's Algorithm                                               
             This is Prim's algorithm to find the lowest cost to traverse it all vertex of a graph or MST(Minimal Spanning Tree)                                              */
#include<stdio.h>
#include<stdlib.h>
// node type structure
struct node
{
    int no;
    int PI;
    int Key;
    struct node *next;
};
// graph type structure
struct Graph
{
    int V;
    int E;
};
// this function initialize value in Graph structure members
struct Graph* create_graph(int V,int E)
{
    // Graph structure pointer to store value
 struct Graph *G;
 G=(struct Graph*)malloc(sizeof(struct Graph));
 G->E=E;
 G->V=V;
 return(G);
}
// function to check the least priority Key or distance node no. and return it
int less_priority(struct node *Start)
{
    int less=0,no=0;
    less=Start->Key;
    no=Start->no;
    Start=Start->next;
    // until start is not equal to 0 the loop will run
    while(Start!=NULL)
    {
        if(Start->Key<less)
        {
            less=Start->Key;
            no=Start->no;
        }
        Start=Start->next;
    }
    return(no);
}
// this function insert the a node
void insertion(struct node **Start,int no)
{
    struct node *temp,*t;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->no=no;
    temp->PI=0;
    temp->Key=1000;
    temp->next=NULL;
    if(*Start==NULL)
    { temp->Key=0;
        *Start=temp;
       }
    else
    {
        t=*Start;
        while(t->next!=NULL)
            t=t->next;
        t->next=temp;
    }
}
// remove node from the queue
struct node* deletion(struct node **Start)
{ int check=0;
struct node *temp,*t,*pre;
    temp=(struct node*)malloc(sizeof(struct node));
    // finding the less priority node no.
    check=less_priority(*Start);
    // is start no. member is equal to check variable
    if((*Start)->no==check)
    {
        temp->no=(*Start)->no;
        temp->Key=(*Start)->Key;
        temp->PI=(*Start)->PI;
        temp->next=NULL;
        t=*Start;
        *Start=(*Start)->next;
        free(t);
    }
    else
    { t=*Start;
        while(t->next!=NULL)
        {
            pre=t;
            t=t->next;
            if(check==t->no)
                break;
            }
            temp->no=t->no;
            temp->PI=t->PI;
            temp->Key=t->Key;
            temp->next=NULL;
            pre->next=t->next;
            free(t);
    }
    return(temp);
}
// this function check whether the particular node is in the queue or not
int check_in_q(int n,struct node *Start)
{
   while(Start!=NULL)
   {
       if(Start->no==n)
        return(1);
       Start=Start->next;
   }
   return(0);
}
int get_n(int n,struct node *Start)
{ int Key;
// finding the distance of the node no. match with the n(node number) and returning the distance
    while(Start!=NULL)
    {
        if(n==Start->no)
        {
            Key=Start->Key;
            break;
        }
        Start=Start->next;
    }
    return(Key);
}
//this function change the Key(distance) and PI(Parent node) value with the given arguments
void change(int n,struct node **Start,int Key,int PI)
{
    struct node *temp;
    if((*Start)->no==n)
    {
        (*Start)->Key=Key;
        (*Start)->PI=PI;
    }
    else
    {
      temp=*Start;
      while(temp!=NULL)
      {
          if(temp->no==n)
          {
              temp->Key=Key;
              temp->PI=PI;
              break;
          }
          temp=temp->next;
      }
    }
}
//the main logic to find lowest cost traverse
void Prims(struct node **Start,struct Graph *G)
{ int e1,i,n,w;
    struct node *temp;
    int t,cost=0;
    // run until start is not equal to 0
    while(*Start!=NULL)
    {
        //take the less priority node
    temp=deletion(Start);
    // increase cost
    cost+=temp->Key;
    printf("Enter the no. of nodes connected to V%d",temp->no);
    scanf("%d",&e1);
    for(i=0;i<e1;i++)
    {
        printf("enter the node no of v%d and weight",temp->no);
        scanf("%d%d",&n,&w);
        if(1==check_in_q(n,*Start))
        {
            t=get_n(n,*Start);
            if(w<t)
                change(n,Start,w,e1);
        }
    }
    }
    printf("\n Cost=%d",cost);
}
// driver code
int main()
{
    struct node *Start=NULL;
    struct Graph *G;
    int i,v,e;
    printf("enter vertex and edges");
    scanf("%d %d",&v,&e);
    G=create_graph(v,e);
    for(i=0;i<G->V;i++)
        insertion(&Start,i+1);
    Prims(&Start,G);
    return 0;
}
/*
Input:
enter vertex and edges 3
6
Enter the no. of nodes connected to V1 2
enter the node no of v1 and weight2
5
enter the node no of v1 and weight 3
2
Enter the no. of nodes connected to V3 2
enter the node no of v3 and weight1
2
enter the node no of v3 and weight 2
2
Enter the no. of nodes connected to V2 2
enter the node no of v2 and weight 1
5
enter the node no of v2 and weight 3
2
Output: Cost: 4

Time Complexity:O(V^2)

*/
