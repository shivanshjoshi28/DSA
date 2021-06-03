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

int lomutopartition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;
    for (int j = l; j < h; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}

// int Hoarse(int arr[], int l, int h)
// {
//     int pivot = arr[l];
//     int i = l - 1, j = h + 1;
//     while (true)
//     {
//         do
//         {
//             i++;
//         } while (arr[i] < pivot);

//         do
//         {
//             j--;
//         } while (arr[j] > pivot);
//         if (i >= j)
//             return j;
//         swap(arr[i], arr[j]);
//     }
// }
int KthSmallElement(int arr[], int n, int k)
{
    int l = 0, h = n - 1;
    while (l < h)
    {
        int p = lomutopartition(arr, l, h);
        if (p == k - 1)
            return arr[p];
        else if (p > k - 1)
            h = p - 1;
        else
            l = p + 1;
    }
    return -1;
}

int main()
{
    boost;
    int arr[6] = {7, 10, 4, 3, 20, 15};
    int n = 6;
    int k = 3;
    cout << KthSmallElement(arr, n, k);

    return 0;
}

// int this hoare's partition cannot be applied as in that the array order is not confirmed
