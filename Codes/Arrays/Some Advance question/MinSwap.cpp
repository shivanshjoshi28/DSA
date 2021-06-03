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

int MinSwap(int arr[], int n, int k)
{
    int good = 0, bad = 0;
    rep(i, n) if (arr[i] <= k) good++;
    rep(i, good) if (arr[i] > k) bad++;
    int res = bad;

    for (int i = good; i < n; i++)
    {
        if (arr[i] > k)
            bad++;
        if (arr[i - good] > k)
            bad--;
        res = min(res, bad);
    }
    return res;
}
int main()
{
    boost;
    int arr[6] = {2, 1, 5, 4, 0, 3};
    int n = 6;
    int k = 3;
    cout << MinSwap(arr, n, k);
    return 0;
}

// Minimum swaps required bring elements less equal K together
// TC:o(n)     sliding window technique