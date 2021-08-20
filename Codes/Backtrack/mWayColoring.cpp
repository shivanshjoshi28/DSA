#include<bits/stdc++.h>
#include <iostream>
using namespace std;

#include<vector>
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back
#define MP make_pair
#define endl "\n"
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
const int inf =(int) 1e18;
const int ninf = (int)-1e17;
#define rep(a, b) for (int a = 0; a < b; a++)
#define per(a, b) for (int a = b - 1; a >= 0; a--)
#define FOR(it, start, end) for (auto it = start; it != end; it++)
#define V 4
bool isSafe(int ind,int color[],bool graph[V][V],int choise)
{
    for(int i=0;i<V;i++)
    {
        if(graph[ind][i] && color[i]==choise) 
        return false;
    }
    return true;
}
bool ColorPossible(bool graph[V][V],int m,int ind,int color[])
{
    if(ind==V)
    return true;
    for(int i=1;i<=m;i++)
    {
        if(isSafe(ind,color,graph,i))
        {
            color[ind]=i;
            if(ColorPossible(graph,m,ind+1,color)) return true;
            color[ind]=0;
        }
    }
    return false;
}
void graphColoring(bool graph[V][V],int m)
{
    int color[V]={0};
    if(ColorPossible(graph,m,0,color))
    {
        for(int i=0;i<V;i++) cout<<color[i]<<endl;
    }
    else
    {
        cout<<"Not possible"<<endl;
    }

}
int main()
{
    boost;
    bool graph[V][V] = { { 0, 1, 1, 1 },
                         { 1, 0, 1, 0 },
                         { 1, 1, 0, 1 },
                         { 1, 0, 1, 0 }, };
                          
    // Number of colors
    int m = 3;
    graphColoring(graph, m);
    return 0;
}



// below is the good implementation in O(V+E) using simple bfs .
