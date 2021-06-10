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

int CutTree(int arr[], int n, int m)
{
    sort(arr, arr + n);
    int low = arr[0];
    int high = arr[n - 1];
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int left = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mid)
                left += (arr[i] - mid);
        }
        if (left >= m)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}

int main()
{
    boost;
    int arr[5] = {4, 42, 40, 26, 46};
    int n = 5;
    int m = 20;
    cout << CutTree(arr, n, m);
    return 0;
}