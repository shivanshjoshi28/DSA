#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
// typedef vector<int> vi;
typedef vector<vector<int>> vvi;
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

void DFSUtils(vvi &matrix, int x, int y, int m, int n)
{
    // cout << matrix[x][y] << endl;
    if (x < 0 || x >=m || y < 0 || y >=n || matrix[x][y] !=1 )
        return;

    matrix[x][y] = 2;

    DFSUtils(matrix, x + 1, y, m, n);
    DFSUtils(matrix, x, y + 1, m, n);
    DFSUtils(matrix, x - 1, y, m, n);
    DFSUtils(matrix, x, y - 1, m, n);
    DFSUtils(matrix, x + 1, y + 1, m, n);
    DFSUtils(matrix, x - 1, y - 1, m, n);
    DFSUtils(matrix, x + 1, y - 1, m, n);
    DFSUtils(matrix, x - 1, y + 1, m, n);
}

void NoOfIsland(vvi adj, int m, int n)
{
    int Island = 0;
    rep(i, m)
    {
        rep(j, n)
        {
            cout << adj[i][j] << endl;
            if (adj[i][j]==1)
            {
                DFSUtils(adj, i, j, m, n);
                Island++;
            }
        }
    }
    cout << "Total no. of islands are : " << Island;
}

int main()
{
    boost;
    vvi adj;
    int m, n;
    cin >> m >> n;
    rep(i, m)
    {
        vector<int> sample;
        rep(j, n)
        {
            int temp;
            cin >> temp;
            sample.push_back(temp);
        }
        adj.push_back(sample);
    }
    NoOfIsland(adj, m, n);
    return 0;
}