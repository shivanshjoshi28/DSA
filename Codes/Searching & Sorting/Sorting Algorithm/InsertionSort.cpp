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

void run()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int main()
{
    int arr[5] = {3, 2, 342, 1, 3};
    int n = 5;
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int end = i - 1;
        while (end >= 0 && arr[end] > curr)
        {
            arr[end + 1] = arr[end];
            end--;
        }
        arr[end + 1] = curr;
    }
    for (int I : arr)
        cout << I << " ";
    return 0;
}

//O(n^2)