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


int count(string str)
{
    int n=str.length();
    int dp[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            dp[i][j]=0;
    }
    
    for(int gap=0;gap<n;gap++)
    {
        for(int j=0;j<n;j++)
        {
            if((j+gap)<n)
            {
                if(j==(j+gap)) 
                    dp[j][j+gap]=1;
                else
                {
                    if(str[j]==str[j+gap])
                        dp[j][j+gap]=1+dp[j+1][j+gap]+dp[j][j+gap-1];
                    else
                        dp[j][j+gap]=dp[j+1][j+gap]+dp[j][j+gap-1]-dp[j+1][j+gap-1];
                }
            }
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    return dp[0][n-1];
}

int main()
{
    boost;
    string str="abccbc";
    cout<<count(str);
    
    return 0;
}