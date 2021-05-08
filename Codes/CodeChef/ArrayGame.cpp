// #include<bits/stdc++.h>
#include<unordered_map>
#include<algorithm>
#include<vector>
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
int solve(vector<int>v,int s)
{
    if(s>v.size()) return 0;
    int n=v.size();
    unordered_map<int,int>m;
    for(int i=0;i<s;i++)
    {
        m[v[i]]++;
    }
    int answer=m.size();
    for(int i=s;i<n;i++)
    {
        m[v[i]]++;

        if(m.find(v[i-s])!=m.end())
        {
            if(m[v[i-s]]>1) 
                m[v[i-s]]--;
            else
                m.erase(v[i-s]);
        }
        if(m.size()>answer) answer=m.size();
    }
    return answer;
}
int main()
{
    // int t;
    // cin>>t;
    // while(t--)
    // {
        int n,s;
        cin>>n;
        cin>>s;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        cout<<solve(v,s)<<endl;
    // }
    return 0;
}