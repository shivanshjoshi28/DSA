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
#define n 4
int Path[n][n]={0};
bool isSafe(int i,int j,int mat[n][n])
{
    if(i<n and j<n and mat[i][j]==1) return true;
    return false;
}
bool RatMaze(int i,int j,int mat[n][n])
{
    if(i==n-1 and j==n-1)
    {
        Path[i][j]=1;
         return true;
    }
    if(isSafe(i,j,mat))
    {
        Path[i][j]=1;
        if(RatMaze(i+1,j,mat)) return true;
        if(RatMaze(i,j+1,mat)) return true;
        Path[i][j]=0;
    }
    return false;
}
void solve(int mat[n][n])
{
    if(!RatMaze(0,0,mat))
    cout<<"Solution not possible"<<endl;
    else
    {
       cout<<"Path is"<<endl;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++) cout<<Path[i][j]<<" ";
           cout<<endl;
       }
    }
}
int main()
{
    boost;
    int mat[n][n]={ { 1, 1, 1, 0 },
                    { 1, 1, 0, 1 },
                    { 0, 1, 0, 0 },
                    { 1, 1, 1, 1 } };
    solve(mat);
    return 0;
}