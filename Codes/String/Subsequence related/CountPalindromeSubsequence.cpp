// https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1
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

int dp[1001][1001];
int calculate(string s, int i, int j)
{
    if (i > j)
        return 0;
    if (i == j)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == s[j])
        return dp[i][j] = 1 + calculate(s, i + 1, j) + calculate(s, i, j - 1);
    else
        return dp[i][j] = calculate(s, i + 1, j) + calculate(s, i, j - 1) - calculate(s, i + 1, j - 1);
}

// it is just to find the maximum length palindromic subsequence
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
                    dp[i][j] = 2;
                else
                    dp[i][j] = 1;
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
                if (s[j] == s[i + j])
                {
                    dp[j][i + j] = 2 + dp[j + 1][i + j - 1];
                }
                else
                    dp[j][i + j] = max(dp[j][i + j - 1], dp[j + 1][i + j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
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
    // if(start==0) cout<<"TO make full string as Palindrome "<<s.length()-(end-start+1)<<" character needs to be added"<<endl;
    // else{
    //     cout<<"To make full string as Palindrome "<<s.length()-1<<" character needs to be added"<<endl;
    //     }
    // PrintString(s,start,end);
}
int main()
{
    string s = "abcbdaab";
    memset(dp, -1, sizeof(dp));
    cout << calculate(s, 0, s.length() - 1);
    cout << endl;
    dplongestPalind(s);
    return 0;
}

// Dp is used in this