//find the duplicate in the array 
// https://leetcode.com/problems/find-the-duplicate-number/
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
    int arr[7]={1,5,3,4,0,3,6};
    int n=7;
    for(int i=0;i<n;i++)
    {
        arr[arr[i]%n]=arr[arr[i]%n]+n;
    }
    for(int i=0;i<7;i++)
    {
        if(arr[i]/n>1) cout<<i<<" ";
    }
    return 0;
}



// second method is to use hash map and increment the frequency