#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool check(unordered_map<char, int> um, unordered_map<char, int> newum)
{
    if (um.size() != um.size())
        return false;
    for (auto it : newum)
    {
        if (um[it.first] != it.second)
            return false;
    }
    return true;
}
int CountSubstring(string str, string search, unordered_map<char, int> &newum)
{
    int k = search.size();
    unordered_map<char, int> um;
    for (int i = 0; i < k; i++)
    {
        um[str[i]]++;
    }
    int ans = 0;
    if (check(um, newum))
        ans++;
    for (int j = k; j < str.size(); j++)
    {
        um[str[j]]++;
        char del = str[j - k];
        um[str[j - k]]--;
        if (um[del] == 0)
        {
            um.erase(del);
        }
        if (check(um, newum))
            ans++;
    }
    return ans;
}

int main()
{
    string str = "aabaabaa";
    string search = "aaba";
    unordered_map<char, int> newum;
    for (int i = 0; i < search.length(); i++)
    {
        newum[str[i]]++;
    }
    cout << CountSubstring(str, search, newum);
    return 0;
}