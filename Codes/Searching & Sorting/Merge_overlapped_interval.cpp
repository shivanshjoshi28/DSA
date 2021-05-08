#include<bits/stdc++.h>
#include <iostream>
using namespace std;
struct Interval
{
    int first;
    int second;
};

void run()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}
bool comp(Interval i1,Interval i2)
{
    return i1.first<i2.first;
}
int main()
{
    Interval arr[4]={{1,3},{2,4},{5,7},{6,8}};
    sort(arr,arr+4,comp);

    int res=0;
    for(int i=1;i<4;i++)
    {
        Interval curr= arr[i];
        if(curr.first<=arr[res].second)
        {
            arr[res].first=min(arr[res].first,curr.first);
            arr[res].second= max(arr[res].second,curr.second);
        }
        else
        {
            res++;
            arr[res]=curr;
        }
    }
    for(int i=0;i<=res;i++)
    {
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
    }
    return 0;
}


// This logic can be used in maximum guest question where we have to count the maximum guest in the interval of arrival and departure.