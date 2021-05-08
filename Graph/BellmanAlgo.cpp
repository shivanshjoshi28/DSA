
// this algorithm also work if the edges are negative , btw it doesn't work in case of cycle
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int *finaldist;
int *path;

class Edge
{
    public:
        int u,v,w;
};
class Graph
{
    public:
        int vertices;
        int e;
        Edge * edges;
    
};
Graph * createGraph(int v,int e)
{
    Graph * g = new Graph;

    g->e=e;
    g->vertices=v;
    g->edges= new Edge[e];
    finaldist= new int[v];
    path= new int[v];
    return g;
}
void Bellman( Graph * graph, int start)
{

    for(int i=0;i<graph->vertices;i++)
    {
        finaldist[i]=INT_MAX;
        path[i]=-1;
    }
    finaldist[start]=0;

    for(int i=0;i<graph->vertices-1;i++)
    {
        // cout<<"This is i= "<<i<<endl;
        for(int i=0;i<graph->e;i++)
        {
            int u=graph->edges[i].u;
            int v=graph->edges[i].v;
            int w=graph->edges[i].w;
            if(finaldist[u]!=INT_MAX and finaldist[u]+w < finaldist[v])
            {
                finaldist[v]=finaldist[u]+w;
                path[v]=u;
            }
        }

    }
    for(int i=0;i<graph->e;i++)
    {
        int u=graph->edges[i].u;
        int v=graph->edges[i].v;
        int w=graph->edges[i].w;
        if(finaldist[u]!=INT_MAX and finaldist[u]+w < finaldist[v])
        {
            cout<<"Negative cycle exist .. cannot apply Bellman's Algorithm in this question !! ";
            exit(0);
        }
    }
}
int main()
{
    int v,e;
    cout<<"Enter the total no.of vertices and edges in the graph : ";
    cin>>v>>e;
    Graph * graph= createGraph(v,e);
    // cout<<"hello";
    for(int i=0;i<e;i++)
    {
        cout<<"Enter the u , v, and finally btw those edges : ";
        int u,v,w;
        cin>>u>>v>>w;
        graph->edges[i].u=u;
        graph->edges[i].v=v;
        graph->edges[i].w=w;
    }
    Bellman(graph,0);
    int n;
    cout<<"Enter the vertex for which you want to find the min distance from 0 :";
    cin>>n;
    cout<<"The distance of "<<n <<" from vertex 0 is : "<<finaldist[n]<<endl;
    cout<<"all are :" ;
    for(int i=0;i<v;i++)  // this is the distance of all from the 0 // pls read it carefully as i have made it for alphabet with some restrictions . 
    {
        cout<<finaldist[i]<<" ";
    }
    cout<<endl;
    cout<<"The path is : ";
    int y=n;
    while(y!=-1)
    {
        cout<<y<<" ";
        y=path[y];
    }
    
    return 0;
}