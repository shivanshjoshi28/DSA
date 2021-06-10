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
    // 3 5 7 9 20 25 30 40 55 56 57 60 62   - arr1
    // 1 4 7 11 14 25 44 47 55 57 100          -arr2
    // now use the same as in merging the two sorted array , keep the track of sum till we got the same element s1 & s2 for two array element sum
    return 0;
}
// https://www.spoj.com/problems/ANARC05B/