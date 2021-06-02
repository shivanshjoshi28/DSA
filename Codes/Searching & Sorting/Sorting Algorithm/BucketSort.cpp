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

void BucketSort(int arr[], int n, int k)
{
    int mx = arr[0];
    rep(i, n) mx = max(mx, arr[i]);
    mx++;                       // we need to just learn this
    vector<int> BucketArray[k]; // k bucket
    rep(i, n)
    {
        int pos = (k * arr[i]) / mx;
        BucketArray[pos].push_back(arr[i]);
    }
    rep(i, k)
    {
        sort(BucketArray[i].begin(), BucketArray[i].end());
    }
    int index = 0;
    for (auto eachBckt : BucketArray)
    {
        for (auto it : eachBckt)
        {
            arr[index++] = it;
        }
    }
}

int main()
{
    boost;
    int arr[7] = {20, 80, 10, 85, 75, 99, 18};
    int n = 7;
    int k = 5;   // total no. bucket to form
    int low = 0; // these are all the assumption in this example
    BucketSort(arr, n, k);
    for (auto A : arr)
        cout << A << " ";
    return 0;
}

// O(n)         , assuming k is nearly equal to n, k~n  and data is uniformally distributed
