// https://practice.geeksforgeeks.org/problems/edit-distance3702/1
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
int check(string s1,string s2,int m,int n)
{
    if(m==-1) return n+1;
    if(n==-1) return m+1;

    if(dp[m][n]!=-1) return dp[m][n];
    if(s1[m]==s2[n]) return dp[m][n]=check(s1,s2,m-1,n-1);

    int a= check(s1,s2,m-1,n-1);   //replacing 
    int b= check(s1,s2,m-1,n);     // deleting
    int c= check(s1,s2,m,n-1);      // inserting
    return dp[m][n]=1+min(a,min(b,c));
}

int main()
{
    string s1="geeky";
    string s2="gesek";
    int m=s1.length()-1;
    int n=s2.length()-1;
    memset(dp,-1,sizeof(dp));
    cout<<check(s1,s2,m,n);
    return 0;
}

// this problem is solved using dp.