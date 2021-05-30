// maximum value of arr[j]=arr[i], such that j>i , in array arr:
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
    int arr[7] = {2, 3, 10, 6, 4, 8, 1};
    int res = INT_MIN;
    int minelem = arr[0];

    for (int i = 1; i < 7; i++)
    {
        res = max(res, arr[i] - minelem);
        minelem = min(minelem, arr[i]);
    }
    cout << res;
    return 0;
}