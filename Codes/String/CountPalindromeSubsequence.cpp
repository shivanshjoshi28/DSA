// https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1
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
int calculate(string s,int i,int j)
{
    if(i>j) return 0;
    if(i==j) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j]) return dp[i][j]=1+calculate(s,i+1,j)+calculate(s,i,j-1);
    else
        return dp[i][j]=calculate(s,i+1,j)+calculate(s,i,j-1)-calculate(s,i+1,j-1);

}
int main()
{
    string s="abb";
    memset(dp,-1,sizeof(dp));
    cout<<calculate(s,0,s.length()-1);
    return 0;
}

// Dp is used in this