
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
#define MAX 100
int graph[MAX][MAX] = {0};
bool is_clique(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (graph[arr[i]][arr[j]] == 0)
                return false;
        }
    }
    return true;
}
void solve(int v, int k, int start, vector<int> arr, int &ans)
{
    for (int i = start; i < v; i++)
    {
        arr.push_back(i);
        if (is_clique(arr))
        {
            // ans = max(ans, arr.size());
            if (arr.size() > ans)
                ans = arr.size();
            // cout << ans << endl;
            for (auto it : arr)
                cout << it << " ";
            cout << endl;
            solve(v, k, i + 1, arr, ans);
        }
        arr.pop_back();
    }
}
int main()
{
    // boost;
    int v, e;
    cin >> v >> e;
    vector<int> arr;
    rep(i, e)
    {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    int k = 3;
    int ans = 0;
    solve(v, k, 0, arr, ans);
    cout << ans;
    return 0;
}