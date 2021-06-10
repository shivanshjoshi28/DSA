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
    int sum = 0;
    int student = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            return false;
        if (sum + arr[i] > mid)
        {
            student++;
            sum = arr[i];
            if (student > m)
                return false;
        }
        else
            sum += arr[i];
    }
    return true;
}
int main()
{
    boost;
    int arr[4] = {12, 34, 67, 90};
    int n = 4;
    int m = 2;
    int sum = 0;
    int low = 0;
    rep(i, n)
    {
        sum += arr[i];
    }
    int ans = 0;
    int high = sum;
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