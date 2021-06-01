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
    boost;
    int arr[5] = {2, 5, 8, 12, 30};
    int s = 0, e = 4;
    int x = 17;
    while (s < e)
    {
        if (arr[s] + arr[e] == x)
        {
            cout << "exist";
            return 0;
        }
        else if (arr[s] + arr[e] > x)
            e--;
        else
            s++;
    }
    return 0;
}

// O(n) solution better than the naive solution ie of O(n^2).

// Same question can come for triplet   -- FOr sorted array
// O(n^2)

rep(i, n)
{
    target = x - arr[i];
    // now go and search the pair using the above approach in O(n)
}

// When it comes of unsorted array to form triplet
// Then don't use hashing,use this method only , as we can first sort the array in O(nlog n )
// SO finallly the complexity can be O(nlog n)+O(n^2)=> O(n^2)
