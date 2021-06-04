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

int StockPriceK1(int arr[], int n, int k) // TC: O(n*k)   , n= size of stock array
{
    vector<vector<int>> dp(k + 1, vector<int>(n, 0));
    int ans = 0;

    for (int i = 1; i < k + 1; i++) // i is for row
    {
        int maxdiff = dp[i - 1][0] - arr[0];
        for (int j = 1; j < n; j++) // j for column
        {
            dp[i][j] = max(dp[i][j - 1], (arr[j] + maxdiff));
            maxdiff = max(maxdiff, (dp[i - 1][j] - arr[j]));
            ans = max(ans, dp[i][j]);
        }
    }
    for (auto it : dp)
    {
        for (auto I : it)
            cout << I << " ";
        cout << endl;
    }
    return ans;
}

int StockPriceK2(int arr[], int n, int k) // TC: O(k * n^2)
{
    int ans = 0;
    vector<vector<int>> dp(k + 1, vector<int>(n, 0));
    for (int i = 1; i < k + 1; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int maxans = INT_MIN;
            for (int k = 0; k < j; k++) // we reduce this loop in above solution , above one is much better . But we must know the logic
            {
                maxans = max(maxans, arr[j] - arr[k] + dp[i - 1][k]);
            }
            dp[i][j] = max(dp[i][j - 1], maxans);
            ans = max(ans, dp[i][j]);
        }
    }
    for (auto it : dp)
    {
        for (auto I : it)
            cout << I << " ";
        cout << endl;
    }
    return ans;
}
int main()
{
    boost;
    int arr[12] = {2, 4, 1, 3, 0, 8, 6, 7, 0, 10, 3, 5};
    int k = 3;
    int n = 12;
    cout << StockPriceK1(arr, n, k) << endl;
    cout << StockPriceK2(arr, n, k) << endl;
    return 0;
}

// we are given an array of stock you are required to find the maximum profit when we may buy and sell at max k times