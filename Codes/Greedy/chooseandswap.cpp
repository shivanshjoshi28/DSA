// https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1
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
    string str;
    cin >> str;
    set<char> s;
    for (auto ch : str)
        s.insert(ch);
    for (auto ch : str)
    {
        s.erase(ch);
        if (s.empty())
        {
            break;
        }
        if (*s.begin() < ch)
        {
            char ch1 = *s.begin();
            for (int i = 0; i < str.size(); i++)
            {
                if (str[i] == ch1)
                {
                    str[i] = ch;
                }
                else if (str[i] == ch)
                {
                    str[i] = ch1;
                }
            }
            break;
        }
    }
    cout << str << endl;
    return 0;
}