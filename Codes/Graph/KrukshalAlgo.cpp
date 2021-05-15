// #include<bits/stdc++.h>
#include <iostream>
#include "DisjointSet.h"
#include<algorithm>
using namespace std;

class Edge
{
public:
    int weight;
    int src;
    int dst;

    Edge(int w,int s,int d);
};

Edge::Edge(int w,int s,int d)
{
    weight=w;
    src=s;
    dst=d;
}
bool comparefx(Edge e1,Edge e2)
{
    return e1.weight<e2.weight;
}
void printEdge(vector<Edge>mst)
{
    for(auto i:mst)
    {
        cout<<i.src<<" - "<<i.dst<<" = "<<i.weight<<endl;
    }
}
int Krukshal(vector<Edge> & Edgelist,int v)
{
    int i=0,j=0;
    sort(Edgelist.begin(),Edgelist.end(),comparefx);
    int e=Edgelist.size();
    vector<Edge> mst;
    int res=0;
    while(i<e && j<v-1)
    {
        int src= Edgelist[i].src;
        int dst= Edgelist[i].dst;

        int srcroot= find(src);
        int dstroot= find(dst);

        if(srcroot==dstroot)
        {
            i++;
            continue;
        }
        mst.push_back(Edgelist[i]);
        res+=Edgelist[i].weight;
        Union(srcroot,dstroot);
        i++;
        j++;
    }
    printEdge(mst);
    return res;
}
int main()
{
    // here we have to maintain two thing parent and rank
    cout<<"Enter the no. of vertex and edges in the graph : ";
    int v,e;
    cin>>v>>e;
    dsuf.resize(v);   // array of parent and rank mixture;

    for(int i=0;i<v;i++)
    {
        dsuf[i].parent=-1;
        dsuf[i].rank=0;
    }

    vector<Edge> Edgelist;
    cout<<"Enter the edges starting point and end point followed by the weight: \n";
    for(int i=0;i<e;i++)
    {
        int start,end,weight;
        cin>>start>>end>>weight;
        Edge e(weight,start,end);
        Edgelist.push_back(e);
    }
    cout<<"Min cost of Spanning tree is "<<Krukshal(Edgelist,v);
    return 0;
}
// TC: Sorting  - ElogE
// +
// TC: O(E * logV) for disjoint set DS as we through every edge and find and union operation if of order o(logv) .     
  



  /*                O(ElogE + E logv)    = O(ElogE) */