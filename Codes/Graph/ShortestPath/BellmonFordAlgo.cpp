// it work for negative weight ( mainly for directed graph );
// #include<bits/stdc++.h>
#include<vector>
#include <iostream>
#include<climits>
using namespace std;
typedef  pair<int,int>ipair;

void BellmanFordAlgo(vector<ipair>adj[],int v,int e,int s)
{
    int key[v],parent[v];
    for(int i=0;i<v;i++)
    {
        key[i]=INT_MAX;
        parent[i]=0;
    }
    key[s]=0;
    for(int count =0;count<v-1;count++)
    {
        // for all the edges do the below .
        for(int i=0;i<v;i++)
        {
            // src=i; 
            for(auto ipairu:adj[i])
            {
                int dst= ipairu.first;
                int w= ipairu.second;
                if(key[dst]>key[i]+w)
                {
                    key[dst]=key[i]+w;
                    parent[dst]=i;
                }

            }
        }
            cout<<endl;
    cout<<"The keys are : "<<endl;
    for(int L:key ) cout<<L<<" ";
        cout<<endl;
    }
    // checking for the negative cycle in the graph
    for(int i=0;i<v;i++)
        {
            // src=i; 
            for(auto ipairu:adj[i])
            {
                int dst= ipairu.first;
                int w= ipairu.second;
                if(key[dst]>key[i]+w)
                {
                    cout<<" Negative cycle is present in the graph !!!!!"<<endl;
                    return;
                }
            }
        }
    cout<<endl;
    cout<<"The keys are : "<<endl;
    for(int L:key ) cout<<L<<" ";
        cout<<endl;
    for(int i=0;i<v;i++)
    {
        cout<<"The path from "<<i<<" to 0 is :";
        for(int j=i;j!=0;j=parent[j])
        {
            cout<<j<<" - ";
        }
        cout<<0<<endl;
    }
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<ipair> adj[v];
    for(int i=0;i<e;i++)
    {
        int src,dst,w;
        cin>>src>>dst>>w;
        adj[src].push_back({dst,w});
        // adj[dst].push_back({src,w});
    }
    int s=0;
    BellmanFordAlgo(adj,v,e,s);
    return 0;
}



// TC: O(e*|v-1|) = O(e*v)


// Input 1:
// 4 5
// 0 1 1
// 0 2 4
// 1 2 -3
// 2 3 3
// 1 3 2

// Output :
// The keys are :
// 0 1 -2 1

// The keys are :
// 0 1 -2 1

// The keys are :
// 0 1 -2 1

// The keys are :
// 0 1 -2 1
// The path from 0 to 0 is :0
// The path from 1 to 0 is :1 - 0
// The path from 2 to 0 is :2 - 1 - 0
// The path from 3 to 0 is :3 - 2 - 1 - 0



// But if I take it a undirected graph it, will give the output that there is a negative cycle .