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

struct JobStatus
{
    int start;
    int end;
    int profit;
    // JobStatus(int s,int e,int p)
    // {
    //     start=s;
    //     end=e;
    //     profit=p;
    // }
};
bool comp(JobStatus j1, JobStatus j2)
{
    return j1.end < j2.end;
}
int main()
{
    boost;
    JobStatus arr[6] = {{1, 3, 5}, {2, 5, 6}, {4, 6, 5}, {6, 7, 4}, {5, 8, 11}, {7, 9, 2}};
    sort(arr, arr + 6, comp); // sort according to end time
    int n = 6;
    int dp[6] = {0};
    dp[0] = arr[0].profit;
    int ans = dp[0];
    for (int i = 1; i < n; i++)
    {
        int inc = arr[i].profit;
        int last = -1;
        int low = 0;
        int high = i - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid].end <= arr[i].start)
            {
                last = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        if (last != -1)
            inc += dp[last];
        int exc = dp[i - 1];
        dp[i] = max(exc, inc);
    }
    rep(i, n) cout << dp[i] << " ";
    cout << endl;
    cout << dp[n - 1];
    return 0;
}

// TC: O(n log n )