// ip - arr[]={1,1,0,0,0,1}
// if we flip all the 0 to 1 whole array will become 1's ,here as 0's group are lesss as compared to 1's so ,we flip it

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
    int arr[6] = {1, 1, 0, 0, 0, 1};
    int n = 6;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            if (arr[i] != arr[0])
            {
                cout << "From " << i;
            }
            else
                cout << " to " << i - 1 << endl;
        }
    }

    if (arr[n - 1] != arr[0])
        cout << " to " << n - 1 << endl;

    return 0;
}

// see the copy for the reference ,we will flip only the 2nd group