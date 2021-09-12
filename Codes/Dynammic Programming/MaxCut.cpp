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


// recursion implementation done in recursion folder folder or must be in copy
int maxcut(int sum,int a,int b,int c)
{
    vector<int>dp(sum+1,-1);
    dp[0]=0;
    for(int i=1;i<=sum;i++)
    {
        if(i-a>=0) dp[i]=max(dp[i],dp[i-a]);
        if(i-b>=0) dp[i]=max(dp[i],dp[i-b]);
        if(i-c>=0) dp[i]=max(dp[i],dp[i-c]);
        if(dp[i]!=-1) dp[i]++;
    }
    return dp[sum];
}
int main()
{
    boost;
    int sum=5;
    int a=1,b=2,c=3;
    cout<<maxcut(sum,a,b,c);
    return 0;
}