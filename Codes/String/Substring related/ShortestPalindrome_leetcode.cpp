
// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// #include <vector>
// typedef pair<int, int> pii;
// typedef vector<int> vi;
// #define pb push_back
// #define MP make_pair
// #define endl "\n"
// #define boost                         \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL)
// #define F first
// #define S second
// const int inf = (int)1e18;
// const int ninf = (int)-1e17;
// #define rep(a, b) for (int a = 0; a < b; a++)
// #define per(a, b) for (int a = b - 1; a >= 0; a--)
// #define FOR(it, start, end) for (auto it = start; it != end; it++)

// void run()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("inp.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif
// }

// string shortestPalindrome(string s)
// {

//     int n = s.length();
//     cout << n << endl;
//     if (n == 0)
//         return s;
//     else if (n == 1)
//         return s;
//     int found = 0;
//     for (auto it : s)
//         if (it != s[0])
//         {
//             found = 1;
//             break;
//         }
//     if (found == 0)
//         return s;
//     else
//     {
//         int dp[n][n];
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 dp[i][j] = 0;
//             }
//         }

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (i == j)
//                     dp[i][j] = 1;
//                 if (i < j && j - i == 1)
//                 {
//                     if (s[i] == s[j])
//                         dp[i][j] = 1;
//                     else
//                         dp[i][j] = 0;
//                 }
//             }
//         }

//         for (int i = 2; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 // j is the row and  i+j is the column  as we have to go daigonally
//                 if (i + j < n)
//                 {
//                     if (s[j] == s[i + j] && dp[j + 1][i + j - 1] == 1)
//                     {
//                         dp[j][i + j] = 1;
//                     }
//                     else
//                         dp[j][i + j] = 0;
//                 }
//             }
//         }

//         int start = 0, end = 0, maxlength = INT_MIN;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (dp[i][j] == 1 && j - i + 1 > maxlength)
//                 {
//                     maxlength = j - i + 1;
//                     start = i;
//                     end = j;
//                 }
//             }
//         }
//         if (start == 0)
//         {
//             int add = s.length() - (end - start + 1);
//             string str = s.substr(s.length() - add, add);
//             reverse(str.begin(), str.end());
//             s = str + s;
//             // cout << "TO make * full string as Palindrome " << s.length() - (end - start + 1) << " character needs to be added" << endl;
//         }
//         else
//         {
//             int breakpoint = 0;
//             int i = n - 1;
//             for (i = n - 1; i >= 1; i--)
//             {
//                 if (dp[0][i] == 1)
//                 {
//                     breakpoint = i;
//                     break;
//                 }
//             }
//             if (breakpoint == 0)
//             {
//                 string str = s.substr(1, s.length() - 1);
//                 reverse(str.begin(), str.end());
//                 s = str + s;
//             }
//             else
//             {
//                 string str = s.substr(i + 1, s.length() - (i + 1));
//                 reverse(str.begin(), str.end());
//                 s = str + s;
//             }

//             // cout << "To make full string as Palindrome " << s.length() - 1 << " character needs to be added" << endl;
//         }
//     }
//     return s;
// }

// int main()
// {
//     // boost;
//     run();
//     string s;
//     cin >> s;
//     cout << shortestPalindrome(s);

//     return 0;
// }

// TLE

// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// #include <vector>
// typedef pair<int, int> pii;
// typedef vector<int> vi;
// #define pb push_back
// #define MP make_pair
// #define endl "\n"
// #define boost                         \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL)
// #define F first
// #define S second
// const int inf = (int)1e18;
// const int ninf = (int)-1e17;
// #define rep(a, b) for (int a = 0; a < b; a++)
// #define per(a, b) for (int a = b - 1; a >= 0; a--)
// #define FOR(it, start, end) for (auto it = start; it != end; it++)
// bool check(string s)
// {
//     string temp = s;
//     reverse(temp.begin(), temp.end());
//     return temp == s;
// }
// string shortest(string s)
// {
//     if (s.length() == 0 or s.length() == 1)
//         return s;

//     string palin = s;
//     int maxlen = INT_MIN;
//     string temp = "";

//     for (int i = s.length() - 1; i >= 0; i--)
//     {
//         if (!check(palin))
//         {
//             temp += palin[palin.length() - 1];
//             palin.pop_back();
//         }

//         else if (palin.length() > maxlen)
//         {
//             maxlen = palin.length();
//             break;
//         }
//     }
//     return temp + s;
// }

// int main()
// {
//     boost;
//     // string s = "abcd";
//     string s;
//     cin>>s;
//     cout<<shortest(s);
//     return 0;
// }

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

class Solution
{
public:
    vector<int> fillLP(string cp)
    {
        int n = cp.length();
        vector<int> lp(n, 0);
        int len = 0;
        int i = 1;

        while (i < n)
        {
            if (cp[len] == cp[i])
                lp[i++] = ++len;
            else
            {
                if (len == 0)
                    lp[i++] = 0;
                else
                    len = lp[len - 1];
            }
        }
        return lp;
    }

    string shortestPalindrome(string s)
    {
        string cp = s;
        reverse(cp.begin(), cp.end());

        string temp = s + '$' + cp;
        vector<int> lp = fillLP(temp);
        return cp.substr(0, s.length() - lp.back()) + s;
    }
};
int main()
{
    boost;
    Solution obj;
    string s;
    cin >> s;
    cout << obj.shortestPalindrome(s);

    return 0;
}