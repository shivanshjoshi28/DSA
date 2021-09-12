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

int recur(int e,int f)
{
    // cout<<e<<" "<<f<<endl;
    if(f==1 || f==0) return f;
    if(e==1) return f;
    int res=INT_MAX;
    for(int x=1;x<=f;x++)
    {
        res=min(res,1+max(recur(e-1,x-1),recur(e,f-x)));
    }
    return res;
}

int SolveDp(int e,int f)
{
    vector<vector<int>>dp(f+1,vector<int>(e+1,INT_MAX));
    for(int j=1;j<=e;j++)
    {
        dp[0][j]=0;
        dp[1][j]=1;
    }
    for(int i=2;i<=f;i++)
    {
        dp[i][1]=i;
    }
    for(int i=2;i<=f;i++)
    {
        for(int j=2;j<=e;j++)
        {
            for(int x=1;x<=i;x++)
            {
                int a= 1+max(dp[x-1][j-1],dp[i-x][j]);
                dp[i][j]=min(dp[i][j],a);
            }
        }
    }
    for(auto it:dp)
    {
        for(auto i:it) cout<<i<<" ";
        cout<<endl;
    }
    return dp[f][e];
}
int main()
{
    // boost;
    int e=2,f=10;
    cout<<recur(e,f);
    cout<<endl;
    cout<<SolveDp(e,f);
    return 0;
}