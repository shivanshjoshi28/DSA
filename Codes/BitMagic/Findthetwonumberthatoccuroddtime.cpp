// There is an array given , in which there are two number that comes odd times in that array. You need to print those two number
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
    int arr[10] = {3, 3, 3, 5, 2, 2, 5, 5, 1, 1};
    int XOR = 0;
    rep(i, 10)
    {
        XOR ^= arr[i];
    }
    //  101 xor 011 -> 110
    // now find the last set bit of the answer (5 xor 3)

    int grp = (XOR & (~(XOR - 1)));
    int first = 0, second = 0;
    rep(i, 10)
    {
        if ((grp & arr[i]) != 0)
        {
            first ^= arr[i];
        }
        else
            second ^= arr[i];
    }
    cout << first << " " << second;

    return 0;
}
