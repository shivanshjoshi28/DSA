// https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1
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

void solve(int sum,vector<int>arr,int start,vector<int>curr,set<vector<int>>&ans,int n)
{
    if(sum==0)
    {
        // if(ans.size()!=0 && ans.back()!=curr)
        // {
        //     ans.push_back(curr);
        // }
        // else if(ans.size()==0) 
        ans.insert(curr);
        return;
    }
    else if(sum<0)
    {
        return;
    }
    else if(start==n) return;
    for(int i=start;i<n;i++)
    {
        if(arr[i]<=sum)
        {
            sum-=arr[i];
            curr.push_back(arr[i]);
            solve(sum,arr,i,curr,ans,n);
            curr.pop_back();
            sum+=arr[i];
        }
        else
        {
            return;
        }
    }
}




int main()
{
    boost;
    int n;
    cin>>n;
    vector<int>arr;
    rep(i,n)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int sum;
    cin>>sum;
    set<vector<int>>ans;
    vector<int>v;
    sort(arr.begin(),arr.end());
    solve(sum,arr,0,v,ans,arr.size());
    int count=0;
    for(auto it:ans)
    {
        for(auto itt:it) cout<<itt<<" ";
        // count++;
        // if(count==10) break;
        cout<<endl;
    }
    return 0;
}