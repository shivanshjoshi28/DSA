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

bool check(string s1, string s2)
{
    int n = s1.length();
    int ma = s2.length();
    if (n != ma)
        return false;
    int m1[256] = {0};
    int m2[256] = {0};
    for (int i = 0; i < n; i++)
    {
        if (!m1[s1[i]] and !m2[s2[i]])
        {
            m1[s1[i]] = s2[i];
            m2[s2[i]] = s1[i];
        }
        else if (m1[s1[i]] != s2[i])
            return false;
    }
    return true;
}

int main()
{
    boost;
    string s1 = "abca";
    string s2 = "xyyx";
    if (check(s1, s2))
        cout << "yes";
    else
        cout << "no";
    return 0;
}