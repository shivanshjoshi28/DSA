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

int recur(int value[],int weight[],int W,int n)
{
    if(W==0 || n==0) return 0;
    if(weight[n-1]>W)
        return recur(value,weight,W,n-1);
    else
    {
        return max(value[n-1]+recur(value,weight,W-weight[n-1],n-1),recur(value,weight,W,n-1));
    }
}

int SolveDp(int value[],int weight[],int W,int n)
{
    vector<vector<int>>dp(W+1,vector<int>(n+1,-1));

    for(int i=0;i<=n;i++) dp[0][i]=0;
    for(int i=0;i<=W;i++) dp[i][0]=0;
    for(int i=1;i<=W;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(weight[j-1]>i)
                dp[i][j]=dp[i][j-1];
            else
            {
                dp[i][j]=max(value[j-1]+dp[i-weight[j-1]][j-1],dp[i][j-1]);
            }
        }
    }
    return dp[W][n];
}
int main()
{
    boost;
    int value[3]={10,15,40};
    int weight[3]={1,2,3};
    int W=6;
    int n=3;
    cout<<recur(value,weight,W,n);
    cout<<endl;
    cout<<recur(value,weight,W,n);
    
    return 0;
}