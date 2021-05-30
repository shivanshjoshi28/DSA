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
    int arr[5] = {3, 0, 1, 2, 5};
    int lh[5], rh[5];
    lh[0] = arr[0];
    int maxleft = arr[0];
    for (int i = 1; i < 5; i++)
    {
        maxleft = max(maxleft, arr[i]);
        lh[i] = maxleft;
    }

    rh[4] = arr[4];
    int maxright = arr[4];
    for (int i = 4; i >= 0; i--)
    {
        maxright = max(maxright, arr[i]);
        rh[i] = maxright;
    }
    int water = 0;
    for (int i = 0; i < 5; i++)
    {
        water += (min(lh[i], rh[i]) - arr[i]);
    }
    cout << water;
    // O(n) with space =O(n)

    return 0;
}

// we have to find the total water trapped inside