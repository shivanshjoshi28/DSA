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
void PrintString(string s, int low, int high)
{
    for (int i = low; i <= high; i++)
        cout << s[i];
}
void longestPalin(string str)
{
    int start = 0, maxlengthsubstring = 1;
    for (int i = 1; i < str.length(); i++)
    {

        // even substring check
        int low = i - 1;
        int high = i;
        while (low >= 0 && high < str.length() && str[low] == str[high])
        {
            if (high - low + 1 > maxlengthsubstring)
            {
                maxlengthsubstring = high - low + 1;
                start = low;
            }
            low--;
            high++;
        }

        //odd substring check
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < str.length() && str[low] == str[high])
        {
            if (high - low + 1 > maxlengthsubstring)
            {
                maxlengthsubstring = high - low + 1;
                start = low;
            }
            low--;
            high++;
        }
    }
    PrintString(str, start, start + maxlengthsubstring - 1);
}

void dplongestPalind(string s)
{
    int n = s.length();
    int dp[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                dp[i][j] = 1;
            if (i < j && j - i == 1)
            {
                if (s[i] == s[j])
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
        }
    }

    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // j is the row and  i+j is the column  as we have to go daigonally
            if (i + j < n)
            {
                if (s[j] == s[i + j] && dp[j + 1][i + j - 1] == 1)
                {
                    dp[j][i + j] = 1;
                }
                else
                    dp[j][i + j] = 0;
            }
        }
    }

    int start = 0, end = 0, maxlength = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == 1 && j - i + 1 > maxlength)
            {
                maxlength = j - i + 1;
                start = i;
                end = j;
            }
        }
    }
    if (start == 0)
        cout << "TO make full string as Palindrome " << s.length() - (end - start + 1) << " character needs to be added" << endl;
    else
    {
        cout << "To make full string as Palindrome " << s.length() - 1 << " character needs to be added" << endl;
    }
    PrintString(s, start, end);
}

int main()
{
    string s = "AACECAAAA";
    longestPalin(s); // odd even substring method O(n^2) TC with O(1) SC
    cout << endl;
    dplongestPalind(s); // dp method O(n^2) TC with O(n^2) SC

    return 0;
}
