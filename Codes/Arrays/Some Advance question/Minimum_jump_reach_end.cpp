#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void run()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int minreach(int arr[], int n) // Solution 1: O(n)      most efficient
{
    if (n == 0)
        return -1;
    if (n == 1)
        return 0;
    if (arr[0] == 0)
        return -1;
    int maxReachable = arr[0];
    int jumps = 1;
    int steps = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
            return jumps;
        maxReachable = max(maxReachable, i + arr[i]);
        steps--;

        if (steps == 0)
        {
            jumps++;
            if (i >= maxReachable)
                return -1;
            steps = maxReachable - i;
        }
    }
}

int usingDP(int arr[], int n) // Solution 2 : Using Dynammic programming O(n^2)
{
    if (n == 0)
        return -1;
    if (n == 1)
        return 0;

    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = INT_MAX;
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] != INT_MAX && arr[j] + j >= i)
            {
                if (dp[j] + 1 < dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    if (dp[n - 1] != INT_MAX)
        return dp[n - 1];
    else
        return -1;
}
int main()
{
    int arr[12] = {1, 3, 0, 8, 1, 1, 1, 0, 1, 0, 0, 1};
    cout << minreach(arr, 12) << endl;
    cout << usingDP(arr, 12) << endl;
    return 0;
}
