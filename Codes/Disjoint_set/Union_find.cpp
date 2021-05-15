//program to check if there is a cycle in the graph (Undirected graph)
#include<bits/stdc++.h>
#include<vector>
#include <iostream>
using namespace std;
vector<int> dsuf;

int find(int i)
{
    if(dsuf[i]==-1)
        return i;
    return find(dsuf[i]);
}

void Union(int first,int second)
{
    dsuf[first]=second;
}

bool iscyclic(vector<pair<int,int>> & Edgelist)
{
    for(int i=0;i<Edgelist.size();i++)
    {
        int src= Edgelist[i].first;
        int dst= Edgelist[i].second;

        int srcroot= find(src);
        int dstroot= find(dst);
        // cout<<"at src = "<<src<<" and dst = "<<dst<<endl;
        // cout<<srcroot<<" "<<dstroot<<endl;
        if(srcroot==dstroot)
            return true;
        Union(srcroot,dstroot);
        // for(int vv:dsuf) cout<<vv<<" ";
        // cout<<endl;
    }
    return false;

}


int main()
{
    cout<<"Enter the no. of vertex and edges in the graph : ";
    int v,e;
    cin>>v>>e;

    dsuf.resize(v,-1);   // it store the parent array full to -1

    // for(int i=0;i<v;i++)
    // {
    //     dsuf[i]=-1;
    // }

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


// TC: O(E * V) as we through every edge and find and union operation if of order o(v) as there may be a skewed tree formed.