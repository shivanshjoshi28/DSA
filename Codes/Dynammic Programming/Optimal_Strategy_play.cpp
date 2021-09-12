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

int recur(int arr[],int i,int j,int n)
{
    cout<<i<<" "<<j<<endl;

    if(i+1==j)
    return max(arr[i],arr[i+1]);

    return max(arr[i]+ min(recur(arr,i+2,j,n),recur(arr,i+1,j-1,n))
            , arr[j]+ min(recur(arr,i+1,j-1,n),recur(arr,i,j-2,n)));
}

int soveDp(int arr[],int n)   // ( O( n^2))
{
    vector<vector<int>>dp(n,vector<int>(n,-1));
    for(int i=0;i<n;i++)
    {
        dp[i][i]=arr[i];  // filling diagonal 
        if(i<n-1)
        {
            dp[i][i+1]=max(arr[i],arr[i+1]);  // fill two one 
        }  
    }

    for(int gap=3;gap<n;gap+=2)
    {
        for(int i=0;i+gap<n;i++)
        {
            int j=i+gap;
            dp[i][j]=max(arr[i]+min(dp[i+2][j],dp[i+1][j-1]), arr[j]+min(dp[i][j-2],dp[i+1][j-1]));
        }
    }
    return dp[0][n-1];
}
int main()
{
    // boost;
    int arr[4]={8,15,3,7};
    int n=4;
    cout<<recur(arr,0,n-1,n);
    cout<<endl;
    cout<<soveDp(arr,n);
    return 0;
}