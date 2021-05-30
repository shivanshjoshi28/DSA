// left rotate the array by d unit
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

void rev(int arr[], int s, int e)
{
    while (s < e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}
void rotatebyd(int arr[], int d, int n)
{
    rev(arr, 0, d - 1); // O(d)
    rev(arr, d, n - 1); // O(n-d)
    rev(arr, 0, n - 1); // O(n)

    // print the arrray
    rep(i, n) cout << arr[i] << " ";
}
int main()
{
    boost;
    int arr[5] = {1, 2, 3, 4, 5};
    int d = 3;
    rotatebyd(arr, d, 5); // O(n)
    return 0;
}

// Reversal Algorithm in array