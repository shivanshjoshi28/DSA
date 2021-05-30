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

int main()
{
    boost;
    int arr[6] = {3, 4, 8, -9, 20, 6};
    int rightside_sum = 0;
    int n = 6;
    rep(i, n)
    {
        rightside_sum += arr[i];
    }
    int leftside_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (leftside_sum == rightside_sum - arr[i])
        {
            cout << "Got answer at i= " << i << " Sum = " << leftside_sum << " on both the side " << endl;
            break;
        }
        leftside_sum += arr[i];
        rightside_sum -= arr[i];
    }
    cout << "Equilibrium not present" << endl;

    return 0;
}