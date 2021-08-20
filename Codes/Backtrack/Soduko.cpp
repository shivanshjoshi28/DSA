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
#define n 9
bool isSafe(int num,int i,int j,int grid[n][n])
{
    for(int x=0;x<n;x++)
    {
        if(grid[i][x]==num || grid[x][j]==num) return false;
    }
    int sq=sqrt(n);
    int extendup=i-(i%sq);
    int extendleft=j-(j%sq);
    for(int x=0;x<sq;x++)
    {
        for(int y=0;y<sq;y++)
        {
            if(grid[x+extendup][y+extendleft]==num) return false;
        }
    }
    return true;
}
bool SolveSudoku(int grid[n][n])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(grid[i][j]==0) goto outside;
        }
    }
    outside:if(i==n && j==n) return true;
    for(int num=1;num<=n;num++)
    {
        // cout<<num<<endl;
        if(isSafe(num,i,j,grid))
        {
            grid[i][j]=num;
            if(SolveSudoku(grid)) return true;
            grid[i][j]=0;
        }
    }
    return false;
}


int main()
{
    boost;
    int grid[n][n]={ 
         {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {7, 4, 5, 2, 0, 6, 3, 0, 0} };
    if(SolveSudoku(grid))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }

    }
    else
    {
        cout<<"Solution not possible"<<endl;
    }
    return 0;
}