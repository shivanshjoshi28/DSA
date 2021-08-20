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
#define n 5
int mat[n][n]={0};

bool isSafe(int row,int col)
{
    for(int i=0;i<col;i++)
    {
        if(mat[row][i]==1) return false;
    }
    //upper diagonal left side
    for(int i=row,j=col;i>=0 and j>=0;i--,j--)
    {
        if(mat[i][j]==1) return false;
    }
    // lower diagonal left side
    for(int i=row,j=col;i<n and j>=0;i++,j--)
    {
        if(mat[i][j]==1) return false;
    }
    return true;
}
bool recur(int col)
{
    if(col>=n) return true;

    for(int i=0;i<n;i++)
    {
        if(isSafe(i,col))
        {
            mat[i][col]=1;
            if(recur(col+1)) return true;
            mat[i][col]=0;
        }
    }
    return false;
}
void PlaceQueen()
{
    if(!recur(0))
    {
        cout<<"Not possible to place"<<endl;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) cout<<mat[i][j]<<" ";
            cout<<endl;
        }
    }
}

int main()
{
    boost;
    PlaceQueen();
    return 0;
}