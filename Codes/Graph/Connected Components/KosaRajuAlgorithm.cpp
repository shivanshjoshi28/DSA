#include<bits/stdc++.h>
#include <iostream>
using namespace std;
// Directed graph 

void dfs(vector<int>adj[],int source,stack<int>&st,int v,bool *visited)
{
    visited[source]=true;
    // cout<<source<<endl;
    for(int u:adj[source])
    {
        if(visited[u]==false)
        {
            dfs(adj,u,st,v,visited);
        }
    }
    st.push(source);  //  keep the track of final ending vertex. 
}

void DFS(vector<int>adj[],int source,int v,bool *visited)
{
    visited[source]=true;
    cout<<source<<" ";
    for(int u:adj[source])
    {
        if(visited[u]==false)
        {
            DFS(adj,u,v,visited);
        }
    }
}

void KrukshalAlgo(vector<int>adj[],int v)
{
    bool visited[v];
    stack<int>st;
    for(int i=0;i<v;i++) visited[i]=false;
    for(int i=0;i<v;i++) // DFS ( O(E+V))
    {
        if(visited[i]==false)
        {
            dfs(adj,i,st,v,visited);
        }
    }



    
    vector<int>revadj[v];
    // Now we need to change the direction of the direction of the path in the graph of every vertex
    for(int i=0;i<v;i++)
    {
        for(int u:adj[i])
        {
            revadj[u].push_back(i);
        }
    }




// now tranverse the stack element 
    for(int i=0;i<v;i++) visited[i]=false;
    cout<<"The connected components of the graph is : \n";

    while(!st.empty())
    {
        int source=st.top();
        st.pop();
        if(visited[source]==false)
        {
            DFS(revadj,source,v,visited);
            cout<<endl;
        }
    }
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<int>adj[v];


    for(int i=0;i<e;i++)
    {
        int src,dst;
        cin>>src>>dst;
        adj[src].push_back(dst);  // directed graph
    }
    KrukshalAlgo(adj,v);
    return 0;
}

// Sample input and output
// 15 19
// 0 1
// 1 2
// 2 3
// 2 5
// 3 0
// 3 4
// 4 0
// 6 5
// 6 3
// 5 7
// 7 8
// 8 9
// 9 10
// 10 8
// 10 12
// 12 11
// 11 13
// 13 12
// 9 14
// The connected components of the graph is :
// 6
// 0 3 2 1 4
// 5
// 7
// 8 10 9
// 14
// 12 13 11


// TC ( O(E+v) + O(E) + TC(E+v))  === > 2 dfs traversal traversal 
// Tc ( O(E+V))




// 2nd input and output 
// 5 5
// 0 1
// 1 2
// 2 0
// 1 3
// 3 4
// The connected components of the graph is :
// 0 2 1
// 3
// 4