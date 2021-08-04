
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
void solve(vector<int> adj[], int v, int e, int k, int start, vector<int> arr, int d[])
{
    if (arr.size() == k)
    {
        // main processing
        if (is_clique(arr))
        {
            for (auto it : arr)
                cout << it << " ";
            cout << endl;
        }
        return;
    }
    for (int i = start; i <= v - (k - arr.size()); i++)
    {
        if (d[i] >= k - 1)
        {
            arr.push_back(i);
            solve(adj, v, e, k, i + 1, arr, d);
            arr.pop_back();
        }
    }
}
int main()
{
    // boost;
    int v = 6;
    int e = 9;
    int d[v] = {0};
    vector<int> arr;
    vector<int> adj[v];
    rep(i, e)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        graph[a][b] = 1;
        graph[b][a] = 1;
        d[a] = d[a] + 1;
        d[b] = d[b] + 1;
    }
    int k = 3;
    solve(adj, v, e, k, 0, arr, d);

    return 0;
}