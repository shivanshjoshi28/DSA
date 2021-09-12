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
    if(m==0 || n==0) return 0;

    int res;
    if(s1[m-1]==s2[n-1])
        res=1+recur(s1,s2,m-1,n-1);
    else
        res=max(recur(s1,s2,m-1,n),recur(s1,s2,m,n-1));
    return res;
}


int MemoizationDP(vector<vector<int>>&dp,string s1,string s2,int m,int n)
{
    // cout<<m<<" "<<n<<endl;
    if(dp[m][n]==-1)
    {
        int res;
        if(m==0 || n==0) res=0;
        else if(s1[m-1]==s2[n-1])
            res=1+MemoizationDP(dp,s1,s2,m-1,n-1);
        else
            res=max(MemoizationDP(dp,s1,s2,m,n-1),MemoizationDP(dp,s1,s2,m-1,n));

        dp[m][n]=res;
    }
    return dp[m][n];
}
void print(stack<char>&st,vector<vector<int>>dp,string s1,string s2,int m,int n)
{
    int i=m;
    int j=n;
    while (i>0 or j>0)
    {
        // cout<<i<<" "<<j<<endl;
        if(s1[i-1]==s2[j-1] and dp[i-1][j-1]+1==dp[i][j])
        {
            // cout<<s1[i-1]<<" ";
            st.push(s1[i-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i][j-1]>dp[i-1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
}

int TabulationDP(string s1,string s2,int m,int n)
{
    vector<vector<int>>table(m+1,vector<int>(n+1,-1));
    for(int i=0;i<=m;i++) table[i][0]=0;
    for(int j=0;j<=n;j++) table [0][j]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                table[i][j]=table[i-1][j-1]+1;
            }
            else
            {
                table[i][j]=max(table[i-1][j],table[i][j-1]);
            }
        }
    }
    cout<<endl;

    for(auto it :table)
    {
        for(auto i: it) cout<<i<<" ";
        cout<<endl;
    }
    cout<<endl;
    stack<char>st;
    print(st,table,s1,s2,m,n);
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    cout<<endl;

    return table[m][n];
}

int DP2dArrayOptimizedSolution(string s1, string s2)
{
    int x = s1.length(), y = s2.length();
    int DpArray[2][y + 1];
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            if (i == 0 or j == 0)
                DpArray[i % 2][j] = 0;

            else if (s1[i - 1] == s2[j - 1])
            {
                DpArray[i % 2][j] = 1 + DpArray[(i + 1) % 2][j - 1];
            }
            else
            {
                DpArray[i % 2][j] = max(DpArray[i % 2][j - 1], DpArray[(i + 1) % 2][j]);
            }
        }
    }
    return DpArray[x % 2][y];
}


int main()
{
    // boost;
    string s1="ABCDAEFGH";
    string s2="ABAACA";
    int m=s1.length();
    int n=s2.length();
    // cout<<recur(s1,s2,m,n);
    // cout<<endl;

    // vector<vector<int>>dp1(m+1,vector<int>(n+1,-1));
    // cout<<MemoizationDP(dp1,s1,s2,m,n);
    // cout<<endl;
    cout<<TabulationDP2(s1,s2,m,n);
    
    return 0;
}