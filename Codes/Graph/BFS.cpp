#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void BFS(vector<int> adj[],int source, int v,bool *visited,char arr[])
{
    queue<int>q;
    q.push(source);
    visited[source]=true;
    while (!q.empty())
    {
        int u= q.front();
        q.pop();
        cout<<arr[u]<<endl;
        for(int v:adj[u])
        {
            // cout<<u<<" v= "<<v<<endl;
            if(!visited[v])
            {
                visited[v]=true;
                q.push(v);
            }
        }
    }
    

}

void BFSsolver(vector<int> adj[],int v,char arr[])
{

    bool visited[v];
    for(int i=0;i<v;i++) visited[i]=false;

    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            BFS(adj,i,v,visited,arr);
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

    BFSsolver(adj,v,arr);
    return 0;
}

// TC: O(E+V)