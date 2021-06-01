// given an unsorted array and a number x , we need to find, if there is pair in the array with sum equal to x

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
    int arr[7] = {3, 5, 9, 2, 8, 10, 11};
    int x = 17;
    unordered_set<int> s;
    rep(i, 7)
    {
        if (s.find(x - arr[i]) != s.end())
        {
            cout << "Yes pair exist";
            return 0;
        }
        s.insert(arr[i]);
    }
    return 0;
}