#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <queue>

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

int checkcond(int grid[][4], int x, int y, int m, int n)
{
    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1)
        return 0;
    return 1;
}
int RottenOrange(int grid[][4], int m, int n)
{
    queue<pair<int, int>> q;
    int countone = 0;
    rep(i, m)
    {
        rep(j, n)
        {
            if (grid[i][j] == 2)
                q.push(MP(i, j));
            if (grid[i][j] == 1)
                countone++;
        }
    }
    int ans = 0;
    int rottenfrwd = 0;
    while (!q.empty())
    {
        int countpresent = q.size();
        int torot = 0;
        for (int i = 0; i < countpresent; i++)
        {
            pair<int, int> p = q.front();
            cout << p.first << " - " << p.second << endl;
            q.pop();
            int x = p.first;
            int y = p.second;

            int leftcheck = checkcond(grid, x, y - 1, m, n);
            int leftelement = grid[x][y - 1];
            if (leftcheck)
            {
                grid[x][y - 1] = 2;
                torot++;
                q.push(MP(x, y - 1));
            }
            int rightcheck = checkcond(grid, x, y + 1, m, n);
            int rightelement = grid[x][y + 1];
            if (rightcheck)
            {
                grid[x][y + 1] = 2;
                torot++;
                q.push(MP(x, y + 1));
            }
            int upcheck = checkcond(grid, x - 1, y, m, n);
            int upelement = grid[x - 1][y];
            if (upcheck)
            {
                grid[x - 1][y] = 2;
                torot++;
                q.push(MP(x - 1, y));
            }
            int downcheck = checkcond(grid, x + 1, y, m, n);
            int downelement = grid[x + 1][y];
            if (downcheck)
            {
                grid[x + 1][y] = 2;
                torot++;
                q.push(MP(x + 1, y));
            }
        }
        if (torot != 0)
            ans++;
        cout << torot << endl;
        rottenfrwd += torot;
        if (rottenfrwd == countone)
            break;
    }
    if (ans != 0 && rottenfrwd == countone)
        return ans;
    return -1;
}

int main()
{
    boost;
    int grid[5][4] = {{1, 0, 2, 2}, {1, 1, 1, 2}, {1, 1, 2, 2}, {1, 2, 2, 2}, {2, 2, 2, 2}};
    cout << RottenOrange(grid, 5, 4);

    return 0;
}

// TC: O(m*n)
