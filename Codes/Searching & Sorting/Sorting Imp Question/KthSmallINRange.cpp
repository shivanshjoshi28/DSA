// https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/kth-smallest-number-again-2/
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<pair<int, int>> vp;
        rep(i, n)
        {
            int t, f;
            cin >> t >> f;
            vp.push_back(MP(t, f));
        }
        sort(vp.begin(), vp.end());

        int overlap = 0;
        for (int i = 1; i < n; i++)
        {
            if (vp[overlap].second >= vp[i].first)
            {
                vp[overlap].second = max(vp[overlap].second, vp[i].second);
            }
            else
            {
                overlap++;
                vp[overlap] = vp[i];
            }
        }
        // we have got the block till overlap

        while (q--)
        {
            int k;
            cin >> k;
            int ans = -1;
            for (int i = 0; i <= overlap; i++)
            {
                if ()
            }
        }
    }
    return 0;
}