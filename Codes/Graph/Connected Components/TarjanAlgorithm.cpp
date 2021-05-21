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

void TarjanAlgo_Util(vi adj[], int v, vector<bool> &inStack, vi &dsc, vi &low, int u, stack<int> &st)
{
    static int time1 = 0;
    dsc[u] = low[u] = ++time1;
    inStack[u] = true;
    st.push(u);

    for (int V : adj[u])
    {
        if (dsc[V] == -1)
        {
            TarjanAlgo_Util(adj, v, inStack, dsc, low, V, st);
            low[u] = min(low[u], low[V]); // updating the low
        }
        else if (inStack[V]) // For Back Edge , Cross edge is ignored by this. as it is not present in inStack
        {
            low[u] = min(low[u], dsc[V]);
        }
    }

    // There is no edge now we need to check the condition

    if (low[u] == dsc[u])
    {
        cout << "SCC is : ";
        while (st.top() != u)
        {
            cout << st.top() << " ";
            inStack[st.top()] = false;
            st.pop();
        }
        cout << st.top() << endl;
        inStack[st.top()] = false;
        st.pop();
    }
}
void SCC_TarjansAlgo(vi adj[], int v)
{
    vector<bool> inStack(v, false);
    vi dsc(v, -1);
    vi low(v, -1);
    stack<int> st;
    rep(i, v)
    {
        if (dsc[i] == -1)
        {
            TarjanAlgo_Util(adj, v, inStack, dsc, low, i, st);
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
    }
    SCC_TarjansAlgo(adj, v);
    return 0;
}

// TC(O(V+E)) single DFS traversal

// Input and output sample

// 15 19
// 0 1
// 1 2
// 2 3
// 2 5
// 3 0
// 3 4
// 4 0
// 6 5
// 6 3
// 5 7
// 7 8
// 8 9
// 9 10
// 10 8
// 10 12
// 12 11
// 11 13
// 13 12
// 9 14
// SCC is : 13 11 12
// SCC is : 14
// SCC is : 10 9 8
// SCC is : 7
// SCC is : 5
// SCC is : 4 3 2 1 0
// SCC is : 6

// 2nd input and output sample
// 7 10
// 0 1
// 1 2
// 1 3
// 3 4
// 4 5
// 5 6
// 4 6
// 6 5
// 5 2
// 4 0
// SCC is : 2
// SCC is : 6 5
// SCC is : 4 3 1 0