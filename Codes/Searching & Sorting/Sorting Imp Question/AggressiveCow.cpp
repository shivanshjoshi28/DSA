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
int Aggressive(int arr[], int n, int c)
{
    sort(arr, arr + n);
    int low = arr[0];
    int high = arr[n - 1];
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int prev = arr[0];
        int cow = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] - prev >= mid)
            {
                cow++;
                prev = arr[i];
            }
            if (c == cow)
                break;
        }
        if (c == cow)
        {
            low = mid + 1;
            ans = mid;
        }
        else
            high = mid - 1;
    }
    return ans;
}

int main()
{
    boost;
    int arr[6] = {1, 5, 8, 11, 13, 16};
    int c = 4;
    int n = 6;
    cout << Aggressive(arr, n, c);
    return 0;
}