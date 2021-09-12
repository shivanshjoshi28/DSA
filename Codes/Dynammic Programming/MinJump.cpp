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

int minjump(int arr[],int n)
{
    if(n==1) return 0;

    int res=INT_MAX;
    for(int i=0;i<=n-2;i++)
    {
        if(arr[i]+i>=n-1)
        {
            int sub_rec=minjump(arr,i+1);
            if(sub_rec!=INT_MAX)
                res=min(res,sub_rec+1);
        }
    }
    return res;
}

int dpsolve(int arr[],int n)
{
    int dp[n];
    dp[0]=0;
    for(int i=1;i<n;i++) dp[i]=INT_MAX;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]+j>=i)
            {
                if(dp[j]!=INT_MAX)
                    dp[i]=min(dp[i],dp[j]+1);
            }
        }
    }
    return dp[n-1];
}
int main()
{
    // boost;
    int arr[6]={3,4,2,1,2,1};
    int n=6;
    cout<<minjump(arr,n);
    cout<<endl;
    cout<<dpsolve(arr,n);
    
    return 0;
}