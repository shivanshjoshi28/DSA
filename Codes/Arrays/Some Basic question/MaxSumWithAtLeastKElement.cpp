// Kadane's+ sliding window concept
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

void fillMaxtillnowArray(int arr[], int n, int MaxSubarrayTillNow[])
{
    int res = arr[0];
    int maxtillnow = arr[0];
    MaxSubarrayTillNow[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxtillnow = max(maxtillnow + arr[i], arr[i]);
        MaxSubarrayTillNow[i] = maxtillnow;
        res = max(res, maxtillnow);
    }
}

void MaxSumWithAtleastKelement(int arr[], int n, int k)
{
    int MaxSubarrayTillNow[n];
    fillMaxtillnowArray(arr, n, MaxSubarrayTillNow);
    int sumkelement = 0;
    for (int i = 0; i < k; i++)
    {
        sumkelement += arr[i];
    }
    int res = sumkelement;
    for (int i = k; i < n; i++)
    {
        sumkelement += (arr[i] - arr[i - k]);
        res = max(res, max(sumkelement, sumkelement + MaxSubarrayTillNow[i - k]));
    }
    cout << res << endl;
}
int main()
{
    boost;
    int arr[5] = {1, 2, 3, -10, -3};
    int k = 4;
    MaxSumWithAtleastKelement(arr, 5, k);

    return 0;
}