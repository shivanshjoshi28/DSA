#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void DFS(vector<int> adj[],int source, int v,bool *visited,char arr[])
{
    visited[source]=true;
    cout<<arr[source]<<endl;

    for(int u:adj[source])
    {
        if(!visited[u])
        {
            DFS(adj,u,v,visited,arr);
        }
    }
}

void DFSsolver(vector<int> adj[],int v,char arr[])
{

    bool visited[v];
    for(int i=0;i<v;i++) visited[i]=false;

    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            DFS(adj,i,v,visited,arr);
        }
    }

}

int main()
{
    int v,e;
    cout<<"Enter the no. of vertices and edges in the graph : ";
    cin>>v>>e;
    vector<int> adj[v];
    
    unordered_map<char,int>m;
    char arr[v];
    int index=0;
    cout<<"Enter the edges and their weight : \n";
    for(int i=0;i<e;i++)
    {
        char fst,scd;
        cin>>fst>>scd;
        fflush(stdin);

        int src,dst;
        if(m.find(fst)==m.end())
        {
            m[fst]=index;
            src=index;
            arr[index]=fst;
            index++;
        }
        else
        {
            src=m[fst];
        }

        if(m.find(scd)==m.end())
        {
            m[scd]=index;
            dst=index;
            arr[index]=scd;
            index++;
        }
        else 
        {
            dst=m[scd];
        }
        adj[src].push_back(dst);
        adj[dst].push_back(src);  // for undirected graph 
    }

    DFSsolver(adj,v,arr);
    return 0;
}



// TC: O(E+V)