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

bool isSafe(int currRow, int currCol, int n, int m)
{
    return currRow >= 0 && currRow < n && currCol >= 0 && currCol < m;
}

int bfs(int currX, int currY, vector<int> matrix[], int n, int m)
{
    queue<pair<int, int>> q;
    q.push(make_pair(currX, currY));
    static int rows[] = {0, -1, 0, 1};
    static int columns[] = {1, 0, -1, 0};
    int flag = 0;
    int dist = 0;
    while (flag == 0 && !q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (isSafe(p.first + rows[i], p.second + columns[i], n, m))
            {
                if (matrix[p.first + rows[i]][p.second + columns[i]])
                {
                    dist = abs(p.first + rows[i] - currX) + abs(p.second + columns[i] - currY);
                    flag = 1;
                    break;
                }
                else
                {
                    q.push(make_pair(p.first + rows[i], p.second + columns[i]));
                }
            }
        }
    }

    return dist;
}

void minDist(vector<int> matrix[], int n, int m)
{
    int dist[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout << i << " " << j << endl;
            if (matrix[i][j])
            {
                dist[i][j] = 0;
            }
            else
            {
                dist[i][j] = bfs(i, j, matrix, n, m);
            }
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // boost;
    int n = 5;
    vector<int> mat[5];
    for (int i = 0; i < 5; i++)
    {
        vector<int> v;

        for (int j = 0; j < 5; j++)
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        mat[i] = v;
    }
    minDist(mat, 5, 5);
    return 0;
}

// Above approach will give TLE

//Instead do bfs one time   ---- below

void minDist(vector<int> matrix[], int n, int m)
{
    int dist[n][m];
    vector<pair<int, int>> q; // in this method, we have enough with vector

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j])
            {
                dist[i][j] = 0;
                q.push_back(make_pair(i, j));
            }
            else
            {
                dist[i][j] = -1; // undefined distance
            }
        }
    }
    // bfs
    static int rows[] = {0, -1, 0, 1};
    static int columns[] = {1, 0, -1, 0};
    int curdist = 1;
    while (!q.empty())
    {
        vector<pair<int, int>> q2; // use separate vector for the next extension
        while (!q.empty())
        {
            pair<int, int> p = q.back();
            q.pop_back();
            for (int i = 0; i < 4; i++)
            {
                if (isSafe(p.first + rows[i], p.second + columns[i], n, m))
                {
                    if (dist[p.first + rows[i]][p.second + columns[i]] == -1)
                    {
                        dist[p.first + rows[i]][p.second + columns[i]] = curdist;
                        q2.push_back(make_pair(p.first + rows[i], p.second + columns[i]));
                    }
                }
            }
        }
        q = q2; // Now copy that extension back into the original vector
        curdist++;
    }
    // output
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}