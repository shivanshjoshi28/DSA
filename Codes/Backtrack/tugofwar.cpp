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

void Recur(int arr[],int n,int start,int count,int &ans,vector< bool >curr,vector< bool >&subset,int sum,int total_sum)
{
    // cout<<"count = "<<count<<endl;
    if(count==n/2)
    {
        if(abs(total_sum/2-sum)<ans)
        {
            // cout<<"sum = "<<sum<<endl;
            ans=abs(total_sum/2-sum);
            // cout<<"ans = "<<ans<<endl;
            rep(i,n)
            {
                subset[i]=curr[i];
            }
        }
        return;
    }

    else if(start==n) return;
    for(int i=start;i<=(n-((n/2)-count));i++)
    {
        // cout<<"start = "<<start<<" i= "<<i<<endl;
        if(count<n/2)
        {
            // cout<<"Yes at start = "<<start<<endl;
            curr[i]=true;
            sum+=arr[i];
            count++;
            Recur(arr,n,i+1,count,ans,curr,subset,sum,total_sum);
            count--;
            curr[i]=false;
            sum-=arr[i];
        }
    }
}

void tugOfWar(int arr[],int n)
{
    vector<bool>subset(n,false);
    vector<bool>curr(n,false);
    int ans=INT_MAX;
    int total_sum=0;
    rep(i,n)
    {
        total_sum+=arr[i];
    }
    // cout<<"total sum"<<total_sum<<endl;
    Recur(arr,n,0,0,ans,curr,subset,0,total_sum);
    for(auto it:subset) cout<<it<<endl;
}

int main()
{
    boost;
    int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    // int arr[]={1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    tugOfWar(arr, n);
    return 0;
}