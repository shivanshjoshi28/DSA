// to show brian Karnighan algorithm

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

int count(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main()
{
    boost;
    int n = -1; // here -1 = 111.....32 times  as 2^32-1 .ie. in base 10 . when changed to decimal it give 32 times 1
    cout << count(n);
    return 0;
}

// wap to count the total no. of set bits present in the given number;

// TC= O(k), where k is the number of set bit present in the number