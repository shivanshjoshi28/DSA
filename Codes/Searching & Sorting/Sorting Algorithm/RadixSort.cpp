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

void CountSort(int arr[], int exp, int n)
{
    int count[10] = {0};
    rep(i, n)
    {
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    rep(i, n) arr[i] = output[i];
}
void RadixSort(int arr[], int n)
{
    int mx = arr[0];
    rep(i, n) mx = max(mx, arr[i]);
    for (int exp = 1; mx / exp > 0; exp *= 10)
    {
        CountSort(arr, exp, n);
    }
}
int main()
{
    boost;
    int arr[5] = {123, 234, 2, 35, 2342};
    int n = 5;
    RadixSort(arr, n);
    for (auto i : arr)
        cout << i << " ";
    return 0;
}

// TC- theta(d*(n+b))
// where d= no. of digits in maximum no.
// n= no of element in array
// b= base like here it is 10 - decimal number
