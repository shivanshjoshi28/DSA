// https://www.geeksforgeeks.org/longest-possible-route-in-a-matrix-with-hurdles/
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
#define R 3
#define C 10
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
bool isSafe(int x,int y)
{
    if(x>=0 and x<R and y>=0 and y<C) return true;
    return false;
}
void recurPath(int mat[R][C],int i,int j,int x,int y,int &ans,int dist,bool visited[R][C])
{
    if(i==x and j==y)
    {
        ans=max(ans,dist);
        return;
    }
    visited[i][j]=true;
    for(int ind=0;ind<4;ind++)
    {
        int newi=i+dx[ind];
        int newj=j+dy[ind];
        if(isSafe(newi,newj) and !visited[newi][newj] and mat[newi][newj]==1)
        {
        recurPath(mat,newi,newj,x,y,ans,dist+1,visited);
        }
    }
    visited[i][j]=false;
}

void findLongestPath(int mat[R][C],int i,int j,int x,int y)
{
    int ans=INT_MIN;
    bool visited[R][C];
    rep(q,R)
    {
        rep(w,C)
        {
            visited[q][w]=false;
        }
    }
    recurPath(mat,i,j,x,y,ans,0,visited);
    if(ans==INT_MIN) cout<<"NOT POSSIBLE "<<endl;
    else cout<<ans<<endl;
}


int main()
{
    boost;
    // input matrix with hurdles shown with number 0
    int mat[R][C] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                      { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
                      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
 
    // find longest path with source (0, 0) and
    // destination (1, 7)
    findLongestPath(mat, 0, 0, 1, 7);
    
    return 0;
}