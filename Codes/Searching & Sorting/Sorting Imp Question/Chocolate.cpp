// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void run()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

int main()
{
    run();
    int n,m;
    cin>>n;
    cin>>m;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    if(m>n)
    {
        cout<<-1;
        return 0;
    }
    sort(v.begin(),v.end());
    int minfirstwindow= v[m-1]-v[0];
    int res= minfirstwindow;
    for(int i=1;i+m-1<n;i++)
    {
        // cout<<"At i= "<<i<<"res = "<<res<<endl;
        res=min(res,(v[i+m-1]-v[i]));
    }
    cout<<res;
    return 0;
}


// Input:
// 9
// 5
// 3 4 1 9 5 6 7 9 12

// OUtput : 4