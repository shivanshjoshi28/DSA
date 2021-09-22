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


int recur(int arr[],int prod,int n)
{
    if(n==0 || prod==0) return 0;
    int res= recur(arr,prod,n-1);
    if(arr[n-1]<=prod)
        res+=(1+recur(arr,prod/arr[n-1],n-1));
    return res;
}



int main()
{
    // boost;
    int arr[5]={2,3,4,6,12};
    int prod=12;
    int n=5;
    cout<<recur(arr,prod,n);
    return 0;
}