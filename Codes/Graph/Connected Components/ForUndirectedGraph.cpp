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

void ConnectedComponentsDFS(vector<int> adj[],int v,char arr[])
{

    bool visited[v];
    for(int i=0;i<v;i++) visited[i]=false;

    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            DFS(adj,i,v,visited,arr);
            cout<<endl;
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
    cout<<"Enter the edges: \n";
    for(int i=0;i<e;i++)
    {
        int src,dst;
        cin>>src>>dst;

        adj[src].push_back(dst);
    }

    ConnectedComponentsDFS(adj,v,arr);
    return 0;
}



// TC: O(E+V)



/// connected components in undirected graph would be be the dfs from Splitted part of the graph
// Means nodes that are not connected to the other part of the graph , as undirected graph is birected so we can go from every and each node.
