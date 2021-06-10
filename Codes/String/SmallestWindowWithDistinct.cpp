// https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

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
    string s = "aabbccdd"; // in this case it will give wrong as this progm assume that there must be atleast one substring with all distinct value( including all element in that)
    set<char> st;
    for (char c : s)
        st.insert(c);
    int n = st.size();
    int start = 0;
    int end = 1;
    unordered_map<char, int> m;
    m[s[start]]++;
    int result = INT_MAX;
    int count = 1;
    while (end < s.length() && start < end)
    {
        if (count < n)
        {
            if (m[s[end]] == 0)
                count++;
            m[s[end]]++;
            end++;
        }
        if (count == n)
        {
            result = min(result, end - start);
            if (m[s[start]] == 1)
                count--;
            m[s[start]]--;
            start++;
        }
    }
    while (count == n)
    {
        result = min(result, end - start);
        if (m[s[start]] == 1)
            count--;
        m[s[start]]--;
        start++;
    }
    cout << result << endl;
    return 0;
}