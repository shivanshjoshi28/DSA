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

int maxSumrecur(int arr[],int n)    // o(2^n)    
{
    if(n==1) return arr[0];
    if(n==2) return max(arr[0],arr[1]);
    return max(maxSumrecur(arr,n-1),arr[n-1]+maxSumrecur(arr,n-2));
}

int tabulationmaxSum(int arr[],int n)    //O(n) TC and O(n) SC
{
    int dp[n+1];
    dp[1]=arr[0];
    dp[2]=max(arr[0],arr[1]);
    for(int i=3;i<=n;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+arr[i-1]);
    }
    return dp[n];
}

int efficientMaxSum(int arr[],int n)        //O(n)  TC  and  O(1)  SC
{
    int prev_prev=arr[0];
    int prev=max(arr[0],arr[1]);
    int res;
    for(int i=2;i<n;i++)
    {
        res=max(prev,prev_prev+arr[i]);
        prev_prev=prev;
        prev=res;
    }
    return res;
}
int main()
{
    boost;
    int arr[4]={10,5,15,20};
    int n=4;
    cout<<maxSumrecur(arr,n);
    cout<<endl;
    cout<<tabulationmaxSum(arr,n);
    cout<<endl;
    cout<<efficientMaxSum(arr,n);
    return 0;
}