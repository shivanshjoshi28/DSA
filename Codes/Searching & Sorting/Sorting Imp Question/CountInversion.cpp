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

int CountAndMerge(int arr[], int l, int m, int h)
{
    int n1 = m - l + 1;
    int n2 = h - m;
    int left[n1], right[n2];
    int res = 0;
    rep(i, n1)
    {
        left[i] = arr[i + l];
    }
    rep(j, n2)
    {
        right[j] = arr[j + m + 1];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            res += (n1 - i);
            arr[k++] = right[j++];
        }
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
    return res;
}
int CountInversion(int arr[], int l, int h)
{
    int res = 0;
    if (l < h)
    {
        int mid = (l + h) / 2;
        res += CountInversion(arr, l, mid);
        res += CountInversion(arr, mid + 1, h);
        res += CountAndMerge(arr, l, mid, h);
    }
    return res;
}

int main()
{
    boost;
    int arr[5] = {2, 4, 1, 3, 5};
    int n = 5;
    cout << CountInversion(arr, 0, n - 1);

    return 0;
}

// count the total no. of inversion in the array
// inversion means  a pair ( arr[i],arr[j]) such that i<j and arr[i]>arr[j]

//O(nlog n) - efficient sol