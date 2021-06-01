// Catching the thief problem gfg

/*
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
void DFSUtil(vector<int> &Pi, vector<int> &Ti, int k, int n, int ans, int val, int i, int j)
{
    if (i == Pi.size() || j == Ti.size()) // base case
    {
        ans = max(ans, val);
        // cout << " ans = " << ans << endl;
        return;
    }

    // for (int ki = j; ki < Ti.size(); ki++)
    // {
    //     if (abs(Ti[ki] - Pi[i]) <= k)
    //     {
    //         // cout << "Ti[" << ki << "]" << Ti[ki] << " is grouped with "
    //         //      << " - Pi[" << i << "]=" << Pi[i] << endl;
    //         i++;
    //         j = ki + 1;
    //         DFSUtil(Pi, Ti, k, n, ans, val + 1, i, j);
    //         i--;
    //         j = ki;
    //     }
    //     // cout << " Call for Police = " << Pi[i] << endl;
    // }
    for (int ki = 0; ki < Ti.size(); ki++)
    {
        if (ki != j - 1 && abs(Ti[ki] - Pi[i]) <= k)
        {
            // cout << "Ti[" << ki << "]" << Ti[ki] << " is grouped with "
            //      << " - Pi[" << i << "]=" << Pi[i] << endl;
            i++;
            j = ki + 1;
            DFSUtil(Pi, Ti, k, n, ans, val + 1, i, j);
            i--;
            j = ki;
        }
        // cout << " Call for Police = " << Pi[i] << "With ki = "<<ki<<endl;
    }
}

void MaxThiefCount(char arr[], int n)
{
    int k = 2;
    vector<int> Pi, Ti;
    rep(i, n)
    {
        if (arr[i] == 'P')
            Pi.push_back(i);
    }
    rep(i, n)
    {
        if (arr[i] == 'T')
            Ti.push_back(i);
    }
    int ans = 0;
    DFSUtil(Pi, Ti, k, n, ans, 0, 0, 0);
}

int main()
{
    boost;
    char arr[6] = {'T', 'T', 'P', 'P', 'T', 'P'};
    int n = 6;
    MaxThiefCount(arr, n);
    return 0;
}

*/

// Above solution of exponential Time Complexity

// Now lets write the code whose TC is O(n)

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int EfficientMaxThiefCount(char arr[], int n)
{
    int k = 2;
    vector<int> Pi, Ti;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 'P')
            Pi.push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 'T')
            Ti.push_back(i);
    }
    int p = 0, t = 0;
    int ans = 0;

    while (p < Pi.size() && t < Ti.size())
    {
        if (abs(Pi[p] - Ti[t]) <= k)
        {
            ans++;
            p++;
            t++;
        }
        else
        {
            if (Pi[p] < Ti[t])
                p++; // as Pi contains the sorted index data and Ti also contains the sorted one . So as Pi[p]<Ti[t] ,
                     // it means every Ti element from t to end will be not satisfying the condition to catch the thief;
            else
                t++;
        }
    }
    return ans;
}

int main()
{
    char arr[6] = {'T', 'T', 'P', 'P', 'T', 'P'};
    int n = 6;
    cout << EfficientMaxThiefCount(arr, n);
    return 0;
}