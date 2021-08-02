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

struct Info
{
    int i;
    int j;
    int dist;
    Info(int i, int j, int dist)
    {
        this->i = i;
        this->j = j;
        this->dist = dist;
    }
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void BfsUtil(int matrix[][3], vector<vector<bool>> &visited, queue<Info> q, int n, int m)
{
    while (!q.empty())
    {
        Info topinf = q.front();
        q.pop();
        rep(i, 4)
        {
            int newx = topinf.i + dx[i];
            int newy = topinf.j + dy[i];
            if (newx >= 0 and newx < n and newy >= 0 and newy < m and !visited[newx][newy] and matrix[newx][newy] == -1)
            {
                matrix[newx][newy] = topinf.dist + 1;
                Info ins(newx, newy, matrix[newx][newy]);
                q.push(ins);
                visited[newx][newy] = true;
            }
        }
    }
}
void Change(int matrix[][3], int n, int m)
{
    queue<Info> q;
    int zero = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    rep(i, n)
    {
        rep(j, m)
        {
            if (matrix[i][j])
            {
                Info temp(i, j, 0);
                q.push(temp);
                visited[i][j] = true;
                matrix[i][j] = 0;
            }
            else
            {
                matrix[i][j] = -1;
                zero++;
            }
        }
    }
    if (!q.empty())
    {
        BfsUtil(matrix, visited, q, n, m);
    }
}

int main()
{
    // boost;
    int grid[3][3] = {{1, 0, 0}, {1, 1, 0}, {1, 0, 0}};
    Change(grid, 3, 3);
    rep(i, 3)
    {
        rep(j, 3)
                cout
            << grid[i][j] << " ";
        cout << endl;
    }
    return 0;
}