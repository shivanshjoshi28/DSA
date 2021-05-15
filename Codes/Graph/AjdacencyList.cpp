#include<bits/stdc++.h>
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int main()
{
    int v,e;
    cout<<"Enter the no. of vertices and edges in the graph : ";
    cin>>v>>e;
    vector<pair<int,int>> adj[v];
    
    unordered_map<char,int>m;
    char arr[v];
    int index=0;
    cout<<"Enter the edges and their weight : \n";
    for(int i=0;i<e;i++)
    {
        char fst,scd;
        cin>>fst>>scd;
        int w;
        cin>>w;
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
        adj[src].push_back({dst,w});
        adj[dst].push_back({src,w});  // for undirected graph 
    }
    for(int i=0;i<v;i++)
    {
        vector<pair<int,int>> v= adj[i];
        for(int j=0;j<v.size();j++)
        {
            // if(v[j].first>=i)
                cout<<arr[i]<<" - "<<arr[v[j].first]<<" = "<<v[j].second<<endl;
        }
    }
    return 0;
}





// O( v ) aux space for map and O(v) aux space for array . 
