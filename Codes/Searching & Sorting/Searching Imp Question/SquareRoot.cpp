// find square root of a no. , if it is perfect square, else print the floor value accordingly

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

// naive solution is O(squareRootOfNumber) , as we will iterate from 1 to infinite and then break when it sq of that no. become greater

int main()
{
    int n = 15;
    int low = 1, high = n, ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int sq = mid * mid;
        if (sq == n)
        {
            ans = mid;
            break;
        }
        else if (sq > n)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }
    cout << ans;
    return 0;
}