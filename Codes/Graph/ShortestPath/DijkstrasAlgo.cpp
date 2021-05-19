#include <iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

typedef  pair<int,int>ipair;

void DijkshtraPrintShortestWeight(vector<ipair> adj[],int v,int e,int s)
{
    ipair weight[v];
    int key[v];
    int parent[v];
    for(int i=0;i<v;i++)
    {
        weight[i]={INT_MAX,i};
        key[i]=INT_MAX;
        parent[i]=0;
    }
    weight[s]={0,s};
    key[s]=0;
    priority_queue<ipair,vector<ipair>, greater<ipair>>pq(weight,weight+v);
    bool goneoutside[v];
    for(int i=0;i<v;i++)
    {
        goneoutside[i]=false;
    }
    while(!pq.empty())
    {
        int w=pq.top().first;
        int u= pq.top().second;
        // cout<<"* u = "<<u<<endl;
        pq.pop();   // log(E)
        goneoutside[u]=true;
        for(auto adjofu:adj[u])
        {
            int adjunode=adjofu.first;
            int wadju = adjofu.second;
            if(goneoutside[adjunode]==false && w+wadju<key[adjunode])
            {
                key[adjunode]=w+wadju;
                pq.push({key[adjunode],adjunode});        //log V
                parent[adjunode]=u;
                // cout<<"{ "<<key[adjunode]<<" , "<<adjunode<<" } is pushed in queue"<<endl;
            }
        }
        // cout<<"The keys are : "<<endl;
        // for(int L:key ) cout<<L<<" ";
        // cout<<endl;
        // cout<<"The goneoutside are : "<<endl;
        // for(bool L:goneoutside ) cout<<L<<" ";
        // cout<<endl;
        // cout<<"The parents are : "<<endl;
        // for(int L:parent ) cout<<L<<" ";
        // cout<<endl;
    }
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
        adj[dst].push_back({src,w});
    }
    int source=0;
    cout<<endl;
    cout<<endl;
    // for(auto u:adj)
    // {
    //     for(auto aa:u)
    //     {
    //         cout<<aa.first<<" "<<aa.second<<endl;
    //     }
    //     cout<<endl;
    // }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    DijkshtraPrintShortestWeight(adj,v,e,source);
    return 0;
}



// TC: O((E+v)(Log v)) = O(Elogv) approx

// Sample Input and output

// 8 11
// 0 1 5
// 0 7 1
// 7 1 1
// 1 6 8
// 0 2 2
// 2 4 1
// 2 3 3
// 3 4 1
// 3 6 1
// 6 5 2
// 3 5 5




// The keys are :
// 0 2 2 4 3 7 5 1
// The path from 0 to 0 is :0
// The path from 1 to 0 is :1 - 7 - 0
// The path from 2 to 0 is :2 - 0
// The path from 3 to 0 is :3 - 4 - 2 - 0
// The path from 4 to 0 is :4 - 2 - 0
// The path from 5 to 0 is :5 - 6 - 3 - 4 - 2 - 0
// The path from 6 to 0 is :6 - 3 - 4 - 2 - 0
// The path from 7 to 0 is :7 - 0