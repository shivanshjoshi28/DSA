#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#include <vector>
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back
#define MP make_pair
#define endl "\n"
#define boost                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define F first
#define S second
const int inf = (int)1e18;
const int ninf = (int)-1e17;
#define rep(a, b) for (int a = 0; a < b; a++)
#define per(a, b) for (int a = b - 1; a >= 0; a--)
#define FOR(it, start, end) for (auto it = start; it != end; it++)

int main()
{
    boost;
    int arr[6] = {1, 4, 4, 1, 0, 1};
    int n = 6;
    int k = 5; // range is 0-4
    int count[k] = {0};
    rep(i, n)
    {
        count[arr[i]]++;
    }
    for (int i = 1; i < k; i++)
    {
        count[i] += count[i - 1]; // prefix sum array
    }
    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    rep(i, n)
    {
        arr[i] = output[i];
    }

    return 0;
}

// O(n+k)