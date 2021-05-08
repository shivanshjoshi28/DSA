#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void run()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}
int dp[1001][1001];
int solve(string p,string s,int i,int j)
{
    // cout<<i<<" "<<j<<endl;
    if(i==-1 && j==-1) return 1;
    if(j==-1)
    {
        for(int k=0;k<i;k++)
        {
            if(p[k]!='*') return 0;
        }
        return 1;
    }
    if(i==-1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(p[i]==s[j] || p[i]=='?') return dp[i][j]=solve(p,s,i-1,j-1);
    if(p[i]=='*')
    {
        int a= solve(p,s,i-1,j);
        int b=solve(p,s,i,j-1);
        return dp[i][j]=a or b;
    }
    return dp[i][j]=0;
}
int main()
{
    string p="g*ks?*";
    string s="gkscddsf";
    memset(dp,-1,sizeof(dp));
    if(solve(p,s,p.length()-1,s.length()-1)) cout<<"Yes";
    else cout<<"No";
    return 0;
}