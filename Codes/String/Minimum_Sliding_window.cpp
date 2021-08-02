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

string minWindow(string s, string t)
{
    //we need a hash table for this
    vector<int> hash(256, 0);

    for (char c : t)
        hash[c]++;

    //2 pointers
    int start = 0, end = 0;

    /*
            head stores the start of the index where min win substr starts
            length is the length of the min win substr
        */
    int length = INT_MAX, head = 0;

    //count of the letters from string t that have already been encountered
    int count = 0;

    while (end < s.size())
    {
        cout << start << " " << end << endl;
        for (auto it : hash)
            cout << it << " ";
        cout << endl;
        if (hash[s[end]] > 0)
            count++;
        hash[s[end]]--;
        end++;

        //when the count reaches the required length
        while (count == t.size())
        {
            if (end - start < length)
            {
                length = end - start;
                head = start;
            }

            if (hash[s[start]] == 0)
                count--;

            hash[s[start]]++;
            start++;
        }
    }

    if (length == INT_MAX)
        return "";
    else
        return s.substr(head, length);
}
int main()
{
    boost;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t);
    return 0;
}