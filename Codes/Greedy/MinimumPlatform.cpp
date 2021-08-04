// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
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
    vector<int> arr;
    vector<int> dep;
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        arr.push_back(a);
        dep.push_back(b);
    }
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    // eg. arr --->    900, 940, 950,1100,1500,1800
    //     dep --->    910, 1120,1130,1200,1900,2000
    int i = 0, j = 0;
    int count = 0;
    int ans = 0;
    while (i < n and j < n)
    {
        if (arr[i] <= dep[j])
        {
            count++;
            i++;
            ans = max(ans, count);
        }
        else
        {
            count--;
            j++;
        }
    }
    cout << ans << endl;

    return 0;
}