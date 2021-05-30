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
    int arr[7] = {2, 3, -8, 7, -1, 2, 3};
    // using kadane' algo
    int n = 7;
    int res = arr[0];
    int maxtillnow = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxtillnow = max(maxtillnow + arr[i], arr[i]);
        res = max(res, maxtillnow);
    }
    cout << res << endl;

    return 0;
}