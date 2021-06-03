// the arrival and departure time is given , we need to keep the track of time , at which the maximum guest was there in wedding at same time
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

int MaxGuest1(int arr[], int dep[], int n)
{

    // bruteforce solution - O(n^2)
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = 1;
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[j] >= arr[i] && arr[j] <= dep[i]) || (arr[i] >= arr[j] && arr[i] <= dep[j]))
                curr++;
        }
        res = max(res, curr);
    }
    return res;
}
// int MaxGuest2(int arr[], int dep[], int n)
// {

// O(N log n ) solution Merge Interval solution  as we have to merge first then after O(n) for below
//     int track = 0;
//     int curr = 1;
//     int res = 0;
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] >= arr[track] && arr[i] <= dep[track])
//         {
//             curr++;
//             res = max(curr, res);
//             arr[track] = min(arr[track], arr[i]);
//             dep[track] = max(dep[track], dep[i]);
//         }
//         else
//         {
//             curr = 1;
//             track++;
//             arr[track] = arr[i];
//             dep[track] = dep[i];
//         }
//     }
//     return res;
// }
int MaxGuest3(int arr[], int dep[], int n)
{
    sort(arr, arr + n); // o(nlog n )
    sort(dep, dep + n); // O(nlogn )
    // as both are sorted array , we need to merge them
    int i = 0, j = 0;
    int curr = 0;
    int res = 0;
    while (i < n && j < n) // O(n)      as only i will complete first , as person arrive first then depart , for last person also
    {
        if (arr[i] <= dep[j])
        {
            curr++;
            i++;
        }
        else
        {
            curr--;
            j++;
        }
        res = max(res, curr);
    }
    return res;
}

int main()
{
    boost;
    int dep[4] = {530, 830, 820, 840};
    int arr[4] = {500, 600, 700, 800};
    int n = 4;
    cout << MaxGuest1(arr, dep, n);
    // cout << MaxGuest2(arr, dep, n);     // for this array should be sorted accrd to arr or dep in ascending or descending order respectively
    cout << MaxGuest3(arr, dep, n);
    return 0;
}
