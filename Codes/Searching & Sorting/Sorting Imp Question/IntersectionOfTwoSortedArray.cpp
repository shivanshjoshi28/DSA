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

void Intersection(int a[], int b[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (i > 0 && a[i] == a[i - 1])
        {
            i++;
            continue;
        }
        else if (a[i] < b[j])
            i++;
        else if (b[j] < a[i])
            j++;
        else
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
}
int main()
{
    boost;
    int arr1[8] = {3, 5, 10, 10, 10, 15, 15, 20};
    int arr2[5] = {5, 10, 10, 15, 30};
    Intersection(arr1, arr2, 8, 5); // TC: O(m+n)

    return 0;
}