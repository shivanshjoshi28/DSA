#include <bits/stdc++.h>
#include <iostream>
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
int time1 = 0;

void DFSUtil(vi adj[], int u, bool *visited, int *dfn, int *low, int *parent, bool *art)
{
    visited[u] = true;
    dfn[u] = low[u] = ++time1;
    int children = 0;

    for (int V : adj[u])
    {
        if (!visited[V])
        {
            children++;
            parent[V] = u;
            DFSUtil(adj, V, visited, dfn, low, parent, art);

            low[u] = min(low[u], low[V]);
            if (dfn[u] < low[V])
            {
                cout << u << " - " << V << endl;
            }
        }
        else if (V != parent[u])
        {
            low[u] = min(low[u], dfn[V]); // this is for backtrack
        }
    }
}

void TarjanBridge(vi adj[], int v)
{
    bool visited[v];
    int parent[v];
    int dfn[v];
    int low[v];
    bool art[v];
    rep(i, v)
    {
        visited[i] = false;
        parent[i] = -1;
        art[i] = false;
    }
    cout << "The bridge present in graph are: " << endl;
    rep(i, v)
    {
        if (!visited[i])
        {
            DFSUtil(adj, i, visited, dfn, low, parent, art);
        }
    }
}

int main()
{
    boost;
    int v, e;
    cin >> v >> e;
    vi adj[v];
    rep(i, e)
    {
        int src, dst;
        cin >> src >> dst;
        adj[src].push_back(dst);
        adj[dst].push_back(src);
    }
    TarjanBridge(adj, v);

    return 0;
}

//O(E+v)   there is only one difference in articulation point and bridge finding , that's the logic of finding the bridge

// 5 5
// 1 0
// 0 2
// 2 1
// 0 3
// 3 4
// The bridge present in graph are:
// 3 - 4
// 0 - 3