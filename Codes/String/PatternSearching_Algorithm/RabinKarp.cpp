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

int createHash(string str, int n)
{
    int PRIME = 1;
    int hash = 0;
    rep(i, n)
    {
        hash += str[i] * int(pow(float(PRIME), float(i)));
    }
    return hash;
}
int createnewhash(int oldhash, int m, int sub, int add)
{
    int PRIME = 1;
    oldhash -= sub;
    oldhash /= PRIME;
    oldhash += (add * int(pow(float(PRIME), float(m - 1))));
    return oldhash;
}
bool checkequality(int start, int end, string text, string pat, int m)
{
    int index = 0;

    for (int i = start; i <= end; i++)
    {
        if (text[i] != pat[index])
            return false;
        index++;
    }
    return true;
}
void RabinKarp(string text, string pat)
{
    int n = text.length();
    int m = pat.length();
    int texhash = createHash(text, m);
    int pathash = createHash(pat, m);

    for (int i = m; i < n; i++)
    {
        if (texhash == pathash && checkequality(i - m, i - 1, text, pat, m))
        {
            cout << i - m << " ";
        }
        texhash = createnewhash(texhash, m, text[i - m], text[i]);
    }

    // check for last one
    if (texhash == pathash && checkequality(n - m, n - 1, text, pat, m))
    {
        cout << n - m << " ";
    }
}
int main()
{
    // boost;
    string text = "abdabcbabc";
    string pat = "abc";
    RabinKarp(text, pat);
    return 0;
}