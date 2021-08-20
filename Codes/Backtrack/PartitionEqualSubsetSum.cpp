// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
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

bool backtrack(int t_sum,int curr_sum,int arr[],int start,int n)
{
    if(t_sum<curr_sum) return false;
    else if(t_sum==curr_sum) return true;
    for(int i=start;i<n;i++)
    {
        int elem=arr[i];
        curr_sum+=arr[i];
        t_sum-=arr[i];
        if(backtrack(t_sum,curr_sum,arr,i+1,n)) return true;
        curr_sum-=arr[i];
        t_sum+=arr[i];
    }
    return false;
}

int solve(int n,int arr[])
{
    int total_sum=0;
    rep(i,n) total_sum+=arr[i];
    if(backtrack(total_sum,0,arr,0,n)) return 1;
    return 0;
}

int main()
{
    boost;
    int n;
    cin>>n;
    int arr[n];
    rep(i,n)
    {
        cin>>arr[i];
    }
    cout<<solve(n,arr);
    
    return 0;
}