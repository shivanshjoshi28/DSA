// https://www.geeksforgeeks.org/weighted-job-scheduling/
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

typedef struct Job
{
    int start;
    int end;
    int profit;
    // Job(int s,int e,int p)
    // {
    //     start=s;
    //     end=e;
    //     profit=p;
    // }
}Job;
void run()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}
bool comp(Job a,Job b)
{
    return a.end<b.end;
}

int calculate(Job jobsarr[],int n)
{
    sort(jobsarr,jobsarr+n,comp);
    int dp[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=jobsarr[i].profit;
    }



    for(int i=1;i<n;i++)             //n^2 TC.
    {
        dp[i]=max(dp[i-1],jobsarr[i].profit);
        for(int j=i-1;j>=0;j--)
        {
            if(jobsarr[j].end<=jobsarr[i].start)
            {
                dp[i]=max(dp[i],dp[j]+jobsarr[i].profit);
                cout<<"i= "<<i<<" j= "<<j<<endl;
                cout<<"Here breaked"<<endl;
                break;
            }
        }
    }
    int ans=INT_MIN;
    for(auto i:dp)
    {
        ans=max(ans,i);
        cout<<i<<" ";
    }
    cout<<endl;
    return ans;

}
int main()
{
    int n;
    cin>>n;
    struct Job jobsarr[n];
    for(int i=0;i<n;i++)
    {
        int s,e,p;
        cin>>s>>e>>p;
        // Job temp=new Job(s,e,p);
        jobsarr[i].profit=p;
        jobsarr[i].start=s;
        jobsarr[i].end=e;
    }
    cout<<calculate(jobsarr,n);
    return 0;
}



