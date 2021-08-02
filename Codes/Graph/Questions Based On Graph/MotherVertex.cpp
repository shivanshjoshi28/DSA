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

void DFSUtil(vi adj[], int u, vector<bool> &visited)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            DFSUtil(adj, v, visited);
        }
    }
}

int MotherVertex(vi adj[], int v)
{
    vector<bool> visited(v, false);
    int maybe_mother;
    rep(i, v)
    {
        if (!visited[i])
        {
            DFSUtil(adj, i, visited);
            maybe_mother = i;
        }
    }
    rep(i, v)
    {
        visited[i] = false;
    }
    DFSUtil(adj, maybe_mother, visited);
    for (bool vs : visited)
        if (vs == false)
            return -1; // not visited node exist there

    return maybe_mother;
}

int main()
{
    boost;
    int v, e;
    cin >> v >> e;
    vi adj[v];
    for (int i = 0; i < e; i++)
    {
        int src, dst;
        cin >> src >> dst;
        adj[src].push_back(dst);
    }
    cout << MotherVertex(adj, v);
    return 0;
}

// https://practice.geeksforgeeks.org/problems/mother-vertex/1/?track=P100-Graph&batchId=197

// O(V+e)*2
// =Tc-> O(V+e)

// sample input 1
// 5 5
// 1 0
// 0 2
// 2 1
// 0 3
// 3 4
// 0

// sample input 2
// 3 2
// 0 1
// 2 1
// -1