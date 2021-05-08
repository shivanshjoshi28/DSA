// https://practice.geeksforgeeks.org/problems/minimize-the-heights-i/1/
#include<vector>
#include <iostream>
#include<climits>
#include <algorithm>
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
    // int arr[4]={1,5,8,10};
    // int n=4,k=2;
    // run();
    int n,k;
    cin>>k>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        if((arr[i]-k)>0)
        {
            v.push_back({arr[i]-k,i});
        }
        v.push_back({arr[i]+k,i});
    }
    vector<int>freq(n,0);
    sort(v.begin(),v.end());
    // for(auto ar:v) cout<<"("<<ar.first<<","<<ar.second<<")"<<endl;
    int low=0,high=1,elem=0;

    // while(elem<n && high<v.size())
    // {
    //     if(freq[v[high].second]==0)
    //     {
    //         elem++;
    //     }
    //     freq[v[high].second]++;
    //     high++;
    // }
    // int ans= v[high-1].first-v[low].first;
    freq[v[0].second]++;
    elem++;
    int ans=INT_MAX;

    while(low<high && high<v.size())
    {
        if(elem<n)
        {
            if(freq[v[high].second]==0)
            {
                elem++;
            }
            freq[v[high].second]++;
            high++;
        }
        if(elem==n)
        {
            ans= min(ans,v[high-1].first-v[low].first);
            if(freq[v[low].second]==1)
                elem--;
            freq[v[low].second]--;
            low++;
        }
    }
    while(elem==n)
    {
            ans= min(ans,v[high-1].first-v[low].first);
            if(freq[v[low].second]==1)
                elem--;
            freq[v[low].second]--;
            low++;
    }



    // while(high<v.size())
    // {
    //     // for(int l:freq) cout<<l<<" ";
    //     // cout<<endl;
    //     if(freq[v[low].second]==1)
    //         elem--;
    //     freq[v[low].second]--;
    //     low++;



    // while(elem<n && high<v.size())
    // {
    //     if(freq[v[high].second]==0)
    //     {
    //         elem++;
    //     }
    //     freq[v[high].second]++;
    //     high++;
    // }
    // if(elem==n){
    //     // cout<<"ans= "<<ans<<" new diff = "<<v[high-1].first-v[low].first<<endl;
    //     // cout<<"v[high-1].first = "<<v[high-1].first<<"v[low].first = "<<v[low].first<<endl;
    //     ans= min(ans,v[high-1].first-v[low].first);}
    // else break;
    // }



    cout<<ans;

    return 0;
}


// 5
// 10
// 7 9 7 7 5 10 2 6 5 6




// 8