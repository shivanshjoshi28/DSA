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

class Solution
{
public:
    int DFS(vector<int> adj[], int u, vector<bool> &visited, int level, int X)
    {
        visited[u] = true;
        if (u == X)
            return level;

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                level++;
                int got = DFS(adj, v, visited, level, X);
                if (got != -1)
                    return got;
            }
        }
        return -1;
    }
    //Function to find the level of node X.
    int nodeLevel(int V, vector<int> adj[], int X)
    {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                int level = 0;
                int gotlevel = DFS(adj, i, visited, level, X);
                if (gotlevel != -1)
                    return gotlevel;
            }
        }
        return -1;
    }
};

int main()
{
    boost;
    Solution ob;
    int v, e;
    cin >> v >> e;
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        int src, dst;
        cin >> src >> dst;
        adj[src].push_back(dst);
        adj[dst].push_back(src);
    }
    int X;
    cin >> X;
    cout << ob.nodeLevel(v, adj, X);
    return 0;
}

//O(V+E)

// https://practice.geeksforgeeks.org/problems/level-of-nodes-1587115620