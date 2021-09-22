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

int recur(int n,int coins[],int sum)
{
    if(sum==0 ) return 1;
    if(n==0) return 0;
    int res=recur(n-1,coins,sum);
    if(coins[n-1]<=sum)
        res+=recur(n,coins,sum-coins[n-1]);
    return res;
}

int Memo(vector<vector<int>>&dp,int n,int coins[],int sum)
{
    if(dp[sum][n]==-1)
    {
        int res;
        if(sum==0 ) res=1;
        else if(n==0) res=0;
        else
        {
            res=Memo(dp,n-1,coins,sum);
            if(coins[n-1]<=sum)
                res+=recur(n,coins,sum-coins[n-1]);
        }
        dp[sum][n]=res;
    }
    return dp[sum][n];
}
int SolveDP(int n,int coins[],int sum)
{
    vector<vector<int>>dp(sum+1,(vector<int>(n+1,-1)));
    for(int i=0;i<=n;i++)  dp[0][i]=1;
    for(int j=1;j<=sum;j++) dp[j][0]=0;
    for(int i=1;i<=sum;i++)   // here i is the sum and j is the n 
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=dp[i][j-1];
            if(coins[j-1]<=i)
                dp[i][j]+=(dp[i-coins[j-1]][j]);
        }
    }
    return dp[sum][n];
}

int SolveDP2(int n,int coins[],int sum)
{
    vector<vector<int>>dp(n+1,(vector<int>(sum+1,-1)));
    for(int i=1;i<=sum;i++)  dp[0][i]=0;
    for(int j=0;j<=n;j++) dp[j][0]=1;

    for(int j=1;j<=sum;j++)     // j is sum in top
    {
        for(int i=1;i<=n;i++)   // i is n in left 
        {
            dp[i][j]=dp[i-1][j];
            if(coins[i-1]<=j)
                dp[i][j]+=dp[i][j-coins[i-1]];
        }
    }
    return dp[n][sum];
}

int count( int S[], int m, int n )		
{		
// table[i] will be storing the number of solutions for		
// value i. We need n+1 rows as the table is constructed		
// in bottom up manner using the base case (n = 0)		
int table[n+1];		
// Initialize all table values as 0		
memset(table, 0, sizeof(table));		
// Base case (If given value is 0)		
table[0] = 1;		
// Pick all coins one by one and update the table[] values		
// after the index greater than or equal to the value of the		
// picked coin		
// cout<<m<<endl;
for(int i=0; i<m; i++)	
{
    for(int j=S[i]; j<=n; j++)
    {	
        // table[j]=0;
        // cout<<i<<" "<<j<<endl;
        table[j] += table[j-S[i]];
    }	
    cout<<"i= "<<i<<endl;
    for(int k=0;k<=n;k++) cout<<table[k]<<" ";
    cout<<endl;
}

    return table[n];		
}		


int main()
{
    // boost;
    int coins[2]={1,2};
    int n=2;
    int sum=3;
    cout<<recur(n,coins,sum);
    cout<<endl;
    // vector<vector<int>>dp(sum+1,vector<int>(n+1,-1));
    // cout<<Memo(dp,n,coins,sum);
    // cout<<endl;
    // cout<<SolveDP(n,coins,sum);
    // cout<<endl;
    // cout<<SolveDP2(n,coins,sum);
    cout<<count(coins,n,sum);
    
    return 0;
}