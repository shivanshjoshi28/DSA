// it can be solved using any partition technique
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

void sort(vector<int>&arr)
{
    int n= arr.size();
    int i=-1,j=n;
    while(i<=j)
    {
        do
        {
            i++;
        }while(arr[i]<0);
        do
        {
            j--;
        }while(arr[j]>0);
        if(i>=j) return ;
        swap(arr[i],arr[j]);
    }
}
int main()
{
    // run();
    vector<int> arr{2,-2,0,1,0,23,-5};
    sort(arr);
    for(int i:arr)cout<<i<<" ";
    return 0;
}


// Output : -5 -2 0 1 0 23 2


// You may also write a same logic for segregation of even odd and sorting of binary array   O(n)