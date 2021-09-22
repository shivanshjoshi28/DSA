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

long long int count(long long int n)
{
    // table[i] will store count
    // of solutions for value i.
    long long int table[n + 1], i;
 
    // Initialize all table
    // values as 0
    for(long long int j = 0; j < n + 1; j++)
            table[j] = 0;
 
    // Base case (If given value is 0)
    table[0] = 1;
 
    // One by one consider given 3 moves
    // and update the table[] values after
    // the index greater than or equal to
    // the value of the picked move
    for (i = 1; i <= n; i++)
    table[i] += table[i - 1];

    for(int i=0;i<=n;i++)
    {
        cout<<table[i]<<" ";
    }
    cout<<endl;
     
    for (i = 2; i <= n; i++)
    table[i] += table[i - 2];
         for(int i=0;i<=n;i++)
    {
        cout<<table[i]<<" ";
    }
    cout<<endl;
    // for (i = 10; i <= n; i++)
    // table[i] += table[i - 10];
    //  for(int i=0;i<=n;i++)
    // {
    //     cout<<table[i]<<" ";
    // }
    // cout<<endl;
    return table[n];
}

int main()
{
    // boost;
    cout<<count(3);
    return 0;
}