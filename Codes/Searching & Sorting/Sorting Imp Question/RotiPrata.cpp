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

bool solve(int arr[], int n, int mid, int m)
{
    int time = 0;
    int paratha = 0;
    rep(i, n)
    {
        int rank = arr[i];
        time = rank;
        int j = 2;
        while (time <= mid)
        {
            paratha++;
            time = time + (j * rank);
            j++;
        }
        if (paratha >= m)
            return true;
    }
    return false;
}

int main()
{
    boost;
    int arr[4] = {1, 2, 3, 4};
    int n = 4;
    int m = 10;
    int low = 0;
    int ans;
    int high = 1e8;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (solve(arr, n, mid, m))
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