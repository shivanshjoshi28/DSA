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

int lomuto(vector<int> &arr, int l, int h)
{
    int pivot = arr[h]; // last element
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
int Hoarse(vector<int> &arr, int l, int h)
{
    int pivot = arr[l];
    int i = l - 1, j = h + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}
void QuickSortLomuto(vector<int> &arr, int l, int h)
{
    if (l < h)
    {
        int partition = lomuto(arr, l, h);
        QuickSortLomuto(arr, l, partition - 1);
        QuickSortLomuto(arr, partition + 1, h);
    }
}

void QuickSortHoare(vector<int> &arr, int l, int h)
{
    if (l < h)
    {
        int partition = Hoarse(arr, l, h);
        QuickSortHoare(arr, l, partition);
        QuickSortHoare(arr, partition + 1, h);
    }
}
int main()
{
    int arr[5] = {3, 2, 342, 1, 3};
    vector<int> a(arr, arr + 5);
    int n = 5;
    // QuickSortLomuto(a, 0, n - 1);
    // for (int I : a)
    //     cout << I << " ";
    QuickSortHoare(a, 0, n - 1);
    for (int I : a)
        cout << I << " ";
    return 0;
}
