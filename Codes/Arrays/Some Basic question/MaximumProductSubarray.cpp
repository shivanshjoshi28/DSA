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

int maxProd(int arr[], int n)
{
    int res = arr[0];
    int maxending_tillNow = arr[0];
    int minending_tillNow = arr[0];
    for (int i = 1; i < n; i++)
    {
        int temp = maxending_tillNow;
        maxending_tillNow = max(maxending_tillNow * arr[i], minending_tillNow * arr[i], arr[i]);
        minending_tillNow = min(temp * arr[i], minending_tillNow * arr[i], arr[i]);
        res = max(res, maxending_tillNow);
    }
    return res;
}

int main()
{
    boost;
    int arr[7] = {-3, 2, -4, 6, 0, -8, 5};
    cout << maxProd(arr, 7);

    return 0;
}