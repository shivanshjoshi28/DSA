// https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1
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

bool solve(int mid, int n)
{
    int x = mid;
    int f = 5;
    int count = 0;
    while (f <= x)
    {
        count += (x / f);
        f *= 5;
    }
    return count >= n;
}
int main()
{
    boost;
    int n = 32;
    int low = 1;
    int high = 1e8;
    int ans;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (solve(mid, n))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << ans;
    return 0;
}