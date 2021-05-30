// easy level question
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

void leader(int arr[], int n)
{
    int max = arr[n - 1];
    cout << max << " ";
    per(i, n - 1)
    {
        if (arr[i] > max)
        {
            cout << arr[i] << " ";
            max = arr[i];
        }
    }
}
int main()
{
    boost;
    int arr[7] = {7, 10, 4, 3, 6, 5, 2};
    leader(arr, 7); // print leader in the array in O(n)
    return 0;
}