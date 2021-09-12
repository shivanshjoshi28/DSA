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

int recur(string s1,string s2,int m,int n)
{
    if(m==0) return n;
    if(n==0) return m;

    if(s1[m-1]==s2[n-1])
        return recur(s1,s2,m-1,n-1);
    return 1+min(recur(s1,s2,m-1,n),min(recur(s1,s2,m-1,n-1),recur(s1,s2,m,n-1)));
}

int DP(string s1,string s2,int m,int n)
{
    vector<vector<int>>table(m+1,vector<int>(n+1,-1));
    for(int i=0;i<=m;i++)
    table[i][0]=i;
    for(int j=0;j<=n;j++)
    table[0][j]=j;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
                table[i][j]=table[i-1][j-1];
            else
            {
                table[i][j]=1+min(table[i-1][j],min(table[i-1][j-1],table[i][j-1]));
            }
        }
    }
    return table[m][n];
}

int main()
{
    boost;
    string s1="SATURDAY",s2="SUNDAY";
    int m=s1.length(),n=s2.length();
    cout<<recur(s1,s2,m,n);
    cout<<endl;
    cout<<DP(s1,s2,m,n);
    return 0;
}