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



int recur(int coins[],int val,int n)
{
    if(val==0) return 0;
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(coins[i]<=val)
        {
            int res=recur(coins,val-coins[i],n);
            if(res!=INT_MAX)
                ans=min(ans,res+1);
        }
    }
    return ans;
}

int solvedp(int coins[],int val,int n)
{
    int dp[val+1];
    dp[0]=0;
    for(int i=1;i<=val;i++) dp[i]=INT_MAX;
    for(int i=1;i<=val;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(coins[j]<=i)
            {
                int res=dp[i-coins[j]];
                if(res!=INT_MAX)
                    dp[i]=min(dp[i],res+1);
            }
        }
    }
    return dp[val];
}
int main()
{
    boost;
    int coins[3]={3,4,1};
    int n=3;
    int val=5;
    cout<<recur(coins,val,n);
    cout<<endl;
    cout<<solvedp(coins,val,n);
    return 0;
}