#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void TopologicalSort(vector<int>adj[],int indegree[],int v,char arr[])
{
    queue<int>q;
    for(int i=0;i<v;i++) // TC(O(v))
    {
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty())    //TC(O(e+v))
    {
        int u=q.front();
        q.pop();
        cout<<arr[u]<<" ";
        for(int v:adj[u])
        {
            indegree[v]--;
            if(indegree[v]==0)
            {
                q.push(v);
            }
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
    cout<<"Enter the edges : \n";
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
    }
    int indegree[v];
    for(int i=0;i<v;i++) indegree[i]=0;
    for(auto a:adj)
    {
        for(int u:a)
        {
            indegree[u]++;
        }
    }
    cout<<"The topological Sort is : ";
    TopologicalSort(adj,indegree,v,arr);
    return 0;
}

// TC: O(E+V)