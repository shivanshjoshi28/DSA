// find the length of minimum substring whose sum is greater than the given number
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

int MinimumSub(int arr[], int x, int n)
{
    int i = 0, j = 0;
    int curr = 0;
    int res = INT_MAX;
    while (i <= j && j < n)
    {
        while (curr <= x && j < n)
        {
            curr += arr[j++];
        }
        while (curr > x && i < j)
        {
            res = min(res, j - i);
            curr -= arr[i];
            i++;
        }
    }

    // do like this or you may prefer above method also
    // int i = 0, j = 1;
    // int curr = arr[0];
    // int res = INT_MAX;
    // while (i < j && j < n)
    // {
    //     if (curr <= x && j < n)
    //     {
    //         curr += arr[j++];
    //     }
    //     if (curr > x && i < j)
    //     {
    //         res = min(res, j - i);
    //         curr -= arr[i];
    //         i++;
    //     }
    // }
    // while (curr > x && i < j)
    // {
    //     res = min(res, j - i);
    //     curr -= arr[i];
    //     i++;
    // }
    return res;
}
int main()
{
    boost;
    int arr[5] = {10, 1, 5, 7, 7};
    int x = 9;
    cout << MinimumSub(arr, x, 5);
    return 0;
}

// TC- O(n)   two pointer approach