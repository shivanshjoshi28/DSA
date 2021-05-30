// using modified kadane' algo for this
// previously we were finding the max subarray sum in the one go,
// this time we simply modify this problem as finding the minimum subarray using kadane's an finally substracting that from the total array elements sum

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

int KadaneMaxSubarray(int arr[], int n)
{
    int res = arr[0];
    int maxtillnow = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxtillnow = max(maxtillnow + arr[i], arr[i]);
        res = max(res, maxtillnow);
    }
    return res;
}
int MaximumCircularSubarray(int arr[], int n)
{
    int maxoverall = KadaneMaxSubarray(arr, n);
    if (maxoverall < 0)
        return maxoverall; // it means that there is no +ve element in the array initially so ans is max using kadane's

    // inverse the sign of every element in the array
    int sum = 0;
    rep(i, n)
    {
        sum += arr[i];
        arr[i] = -arr[i];
    }
    int max_circular = sum + KadaneMaxSubarray(arr, n);
    return max(max_circular, maxoverall);
}

int main()
{
    boost;
    int arr[5] = {-8, 4, -3, 5, -4};
    cout << MaximumCircularSubarray(arr, 5);
    return 0;
}