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

int LongestConsecutiveSequence1(int arr[], int n)
{
    sort(arr, arr + n);
    int count = 1;
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[i - 1] == 1)
        {
            count++;
            res = max(res, count);
        }
        else
        {
            count = 1;
        }
    }
    return res;
}
int LongestConsecutiveSequence2(int arr[], int n)
{
    unordered_set<int> s;
    rep(i, n) s.insert(arr[i]);
    int res = 0;

    rep(i, n)
    {
        if (s.find(arr[i] - 1) == s.end()) // it means arr[i]-1 is not present  so its the starting
        {
            int count = 1;
            int k = arr[i] + 1;
            while (s.find(k) != s.end()) // jb tk aage milta rhe
            {
                k++;
                count++;
            }
            res = max(res, count);
        }
    }
    return res;
}
int main()
{
    boost;
    int arr[6] = {5, 1, 7, 3, 2, 8};
    int n = 6;
    cout << LongestConsecutiveSequence1(arr, n) << endl; // TC: O(nlog n )    SC: O(1);
    cout << LongestConsecutiveSequence2(arr, n);         // TC: O( n )    SC: O(n)  - for unordered set;
    return 0;
}