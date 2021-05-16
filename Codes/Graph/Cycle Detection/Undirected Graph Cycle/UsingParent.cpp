#include<bits/stdc++.h>
#include <iostream>
using namespace std;

bool DFS(vector<int> adj[],int source,bool *visited,int parent)
{
    visited[source]=true;
    for(int u:adj[source])
    {
        if(!visited[u])
        {
            if(DFS(adj,u,visited,source))
                return true;
        }
        else if(u!=parent) return true;
    }
    return false;
}

bool isCyclicDFSsolver(vector<int> adj[],int v)
{

    bool visited[v];
    for(int i=0;i<v;i++) visited[i]=false;

    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            int parent = -1;
             if (DFS(adj,i,visited,parent)) return true;
        }
    }
    return false;

}
int main()
{
    int v,e;
    cout<<"Enter the no. of vertices and edges in the graph : ";
    cin>>v>>e;
    vector<int> adj[v];
    
    unordered_map<char,int>m;
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
            index++;
        }
        else 
        {
            dst=m[scd];
        }
        adj[src].push_back(dst);
        adj[dst].push_back(src);  // for undirected graph 
    }

    if(isCyclicDFSsolver(adj,v))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}


// This uses the logic of DFS ( Parent concept )
// TC: O(E+v)