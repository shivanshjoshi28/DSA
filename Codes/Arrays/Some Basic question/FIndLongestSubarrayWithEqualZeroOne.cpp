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

void LongestSubarray(int arr[], int n)
{
    rep(i, n) if (arr[i] == 0) arr[i] = -1; // replace 0 with -1
    int maxlength = 0;
    int sum = 0;
    int end_index = 0;
    unordered_map<int, int> m;

    rep(i, n)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxlength = i + 1;
            end_index = i;
        }
        if (m.find(sum) != m.end()) // sum is present ;
        {
            if (maxlength < i - m[sum])
            {
                maxlength = i - m[sum];
                end_index = i;
            }
        }
        else
            m[sum] = i;
    }
    cout << end_index - maxlength + 1 << " to " << end_index << endl;
}

int main()
{
    boost;
    int arr[14] = {0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1};
    LongestSubarray(arr, 14);
    return 0;
}