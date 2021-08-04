// https://www.geeksforgeeks.org/buy-maximum-stocks-stocks-can-bought-th-day/

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
    int n;
    cin >> n;
    vector<int> prices;
    rep(i, n)
    {
        int temp;
        cin >> temp;
        prices.push_back(temp);
    }
    int k;
    cin >> k;
    vector<pair<int, int>> arr;
    rep(i, n)
    {
        arr.push_back({prices[i], i + 1});
    }
    sort(arr.begin(), arr.end());
    int rem = k;
    int count = 0;
    rep(i, n)
    {
        int p = min(arr[i].second, rem / arr[i].first);
        count += p;
        rem -= (p * arr[i].first);
    }
    cout << count;
    return 0;
}