// #include<bits/stdc++.h>
#include<vector>
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
