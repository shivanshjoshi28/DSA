// https://www.geeksforgeeks.org/find-the-k-th-permutation-sequence-of-first-n-natural-numbers/
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

int findNum(int& k,int n)
{
    if(n==1) return 0;   // only one element left in set , that wiill be final one
    int factorialn_1;
    n--;
    factorialn_1=n;  // n-1
    while(k>=factorialn_1 and n>1)
    {
        factorialn_1=factorialn_1*(n-1);   // (n-1)*(n-2)  first time
        n--;
    }
    int ret= k/factorialn_1;
    k=k%factorialn_1;
    return ret;
}
string solve(int n,int k)
{
    string ans;
    k--;
    set<int>arr;
    rep(i,n)
    {
        arr.insert(i+1);
    }
    auto itr=arr.begin();
    for(int i=0;i<n;i++)
    {
        int idx= findNum(k,n-i);
        advance(itr,idx);
        ans+=to_string(*itr);
        arr.erase(itr);
        itr=arr.begin();
    }
    return ans;
}

int main()
{
    boost;
    int n,k;
    cin>>n>>k;
    cout<<solve(n,k);
    return 0;
}