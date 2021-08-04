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
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    rep(i, n)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    vector<int> copy1 = arr;
    vector<int> copy2 = arr;
    int ans = 0;
    while (copy1.size() > 0)
    {
        ans += copy1[0];
        copy1.erase(copy1.begin());
        if (copy1.size() >= k)
            copy1.erase(copy1.end() - k, copy1.end());
        else
            copy1.clear();
    }
    int newans = 0;
    while (copy2.size() > 0)
    {
        newans += copy2.back();
        copy2.erase(copy2.end() - 1);
        if (copy2.size() >= k)
            copy2.erase(copy2.begin(), copy2.begin() + k);
        else
            copy2.clear();
    }
    cout << ans << " " << newans;

    return 0;
}
