#include<bits/stdc++.h>
#include <iostream>
using namespace std;

bool DFS(vector<int> adj[],int source,bool *visited,bool *recst)
{
    visited[source]=true;
    recst[source]=true;
    for(int u:adj[source])
    {
        if(!visited[u])
        {
            if(DFS(adj,u,visited,recst))
                return true;
        }
        else if(recst[u]==true) return true;
    }
    recst[source]=false;
    return false;
}

bool isCyclicDFSsolver(vector<int> adj[],int v)
{

    bool visited[v],recst[v];
    for(int i=0;i<v;i++){ visited[i]=false;recst[i]=false;}

    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
             if (DFS(adj,i,visited,recst)) return true;
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
        adj[src].push_back(dst);// for directed graph
    }

    if(isCyclicDFSsolver(adj,v))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}


// This uses the logic of DFS ( Parent concept )
// TC: O(E+v)