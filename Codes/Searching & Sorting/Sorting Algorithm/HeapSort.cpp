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

void Heapify(vector<int> &arr, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int large = i;
    if (left < n && arr[left] > arr[large])
    {
        large = left;
    }
    if (right < n && arr[right] > arr[large])
    {
        large = right;
    }
    if (large != i)
    {
        swap(arr[i], arr[large]);
        Heapify(arr, n, large);
    }
}

void BuildHeap(vector<int> &arr, int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        Heapify(arr, n, i);
    }
}
void HeapSort(vector<int> &arr, int n)
{
    BuildHeap(arr, n); // O(n)

    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}
int main()
{
    boost;
    int arr[5] = {3, 2, 342, 1, 3};
    vector<int> a(arr, arr + 5);
    int n = 5;
    HeapSort(a, n);
    for (int aa : a)
        cout << aa << " ";
    return 0;
}

//O(nlog n)-