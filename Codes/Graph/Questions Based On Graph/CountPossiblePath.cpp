#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

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

int path;
vector<int> trackpath;
void DFSUtil(vi adj[], int s, int d, vector<bool> &visited)
{
    if (s == d)
    {
        path++;
        for (int pathnode : trackpath)
        {
            cout << pathnode << "->";
        }
        cout << d << endl;
        return;
    }
    trackpath.push_back(s);
    visited[s] = true;
    for (int child : adj[s])
    {
        if (!visited[child])
        {
            DFSUtil(adj, child, d, visited);
        }
    }
    visited[s] = false; // backtracking
    trackpath.pop_back();
}

int CountPath(vi adj[], int v, int source, int dst)
{
    vector<bool> visited(v, false);
    DFSUtil(adj, source, dst, visited);
    return path;
}

int main()
{
    boost;
    path = 0;
    int v, e;
    cin >> v >> e;
    vi adj[v];
    for (int i = 0; i < e; i++)
    {
        int src, dst;
        cin >> src >> dst;
        adj[src].push_back(dst);
    }
    int source, destination;
    cin >> source >> destination;
    cout << CountPath(adj, v, source, destination);
    return 0;
}

// https://practice.geeksforgeeks.org/problems/possible-paths-between-2-vertices-1587115620/1/?track=P100-Graph&batchId=197
// O(E+V) using adjancency list Simple DFS