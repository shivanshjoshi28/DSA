#include<bits/stdc++.h>
#include<vector>
#include <iostream>
using namespace std;

struct ParentRankMix
{
    int parent;
    int rank;
};
vector<ParentRankMix>dsuf;

int find(int i)
{
    if(dsuf[i].parent==-1)
        return i;
    return dsuf[i].parent = find(dsuf[i].parent);
}

void Union(int first,int second)
{
    if(dsuf[first].rank>dsuf[second].rank)
    {
        dsuf[second].parent=first;
    }

    else if(dsuf[first].rank<dsuf[second].rank)
    {
        dsuf[first].parent=second;
    }
    else
    {
        dsuf[first].parent=second;
        dsuf[second].rank+=1;
    }
}

bool iscyclic(vector<pair<int,int>> & Edgelist)
{
    for(int i=0;i<Edgelist.size();i++)
    {
        int src= Edgelist[i].first;
        int dst= Edgelist[i].second;

        int srcroot= find(src);
        int dstroot= find(dst);
        cout<<"at src = "<<src<<" and dst = "<<dst<<endl;
        cout<<srcroot<<" "<<dstroot<<endl;
        if(srcroot==dstroot)
            return true;
        Union(srcroot,dstroot);
        for(auto vv:dsuf) cout<<vv.parent<<" ";
        cout<<endl;
        for(auto vv:dsuf) cout<<vv.rank<<" ";
        cout<<endl;
    }
    return false;

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

    vector<pair<int,int>> Edgelist;

    cout<<"Enter the edges starting point and end point : \n";
    for(int i=0;i<e;i++)
    {
        int start,end;
        cin>>start>>end;
        Edgelist.push_back({start,end});
    }

    if(iscyclic(Edgelist))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}

// TC: O(E * logV) as we through every edge and find and union operation if of order o(logv) .
