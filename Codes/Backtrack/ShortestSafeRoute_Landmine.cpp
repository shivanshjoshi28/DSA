/*#include<bits/stdc++.h>
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
#define R 12
#define C 10
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
bool isSafe(int x,int y)
{
    if(x>=0 and x<R and y>=0 and y<C) return true;
    return false;
}
void transformmat(int mat[R][C])
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(mat[i][j]==0)
            {
                rep(k,4)
                {
                    int newi = i+dx[k];
                    int newj = j+dy[k];
                    if(isSafe(newi,newj))
                    {
                        mat[newi][newj]=-1;
                    }
                }
            }
        }
    }

    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(mat[i][j]==-1)
            {
                mat[i][j]=0;
            }
        }
    }
}
int findShortestPath(int mat[R][C])
{
    transformmat(mat);
    int dis[R][C];
    rep(i,R)
    {
        rep(j,C)
        {
            dis[i][j]=-1;
        }
    }

    queue<pair<int,int>>q;
    rep(i,R)
    {
        if(mat[i][0]==1)
        {
            dis[i][0]=0;
            q.push({i,0});
        }
    }
    while(!q.empty())
    {
        auto top=q.front();
        q.pop();
        int x=top.first;
        int y=top.second;
        int ordist= dis[x][y];
        for(int i=0;i<4;i++)
        {
            int newx= x+dx[i];
            int newy=y+dy[i];
            if(isSafe(newx,newy) and dis[newx][newy]==-1 and mat[newx][newy]==1)
            {
                dis[newx][newy]=ordist+1;
                q.push({newx,newy});
            }
        }
    }
    int ans=INT_MAX;
    rep(i,R)
    {
        if(mat[i][C-1]==1 and dis[i][C-1]!=-1 and dis[i][C-1]<ans)
        {
            ans=dis[i][C-1];
        }
    }
    return ans;
}
int main()
{
    boost;
        int mat[R][C] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };
 
    // find shortest path
    cout<<findShortestPath(mat);
    return 0;
}
*/

// Above is the solution with a time complexity of o(R*C) as its normal BFS



// Below is the solution of Backtracking 


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
#define R 12
#define C 10
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
bool isSafe(int x,int y)
{
    if(x>=0 and x<R and y>=0 and y<C) return true;
    return false;
}
void transformmat(int mat[R][C])
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(mat[i][j]==0)
            {
                rep(k,4)
                {
                    int newi = i+dx[k];
                    int newj = j+dy[k];
                    if(isSafe(newi,newj))
                    {
                        mat[newi][newj]=-1;
                    }
                }
            }
        }
    }

    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(mat[i][j]==-1)
            {
                mat[i][j]=0;
            }
        }
    }
}
void DfsUtil(int &ans,int x,int y,int dist,int visited[R][C],int mat[R][C])
{
    if(y==C-1)
    {
        ans=min(ans,dist);
        return;
    }
    visited[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(isSafe(newx,newy) and !visited[newx][newy] and mat[newx][newy]==1)
        {
            DfsUtil(ans,newx,newy,dist+1,visited,mat);
        }
    }
    visited[x][y]=0;
}
int findShortestPath(int mat[R][C])
{
    transformmat(mat);
    int ans=INT_MAX;
    int visited[R][C];
    for(int i=0;i<R;i++)
    {
        if(mat[i][0]==1)
        {
            memset(visited,0,sizeof(visited));
            DfsUtil(ans,i,0,0,visited,mat);
        }
    }
    return ans;
}
int main()
{
    boost;
        int mat[R][C] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };
 
    // find shortest path
    cout<<findShortestPath(mat);
    return 0;
}
