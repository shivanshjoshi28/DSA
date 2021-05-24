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

void run()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int DfsCount(int grid[][3], int x, int y, int m, int n, int count)
{
    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 2)
        return -1;

    if (grid[x][y] == 1)
        return count;

    int element = grid[x][y];

    grid[x][y] = 2;

    int down = DfsCount(grid, x + 1, y, m, n, count + 1);

    int rightgot = DfsCount(grid, x, y + 1, m, n, count + 1);

    int up = DfsCount(grid, x - 1, y, m, n, count + 1);

    int left = DfsCount(grid, x, y - 1, m, n, count + 1);
    grid[x][y] = element;
    int min = INT_MAX;
    if (down == -1 && rightgot == -1 && up == -1 && left == -1)
        return -1;

    else
    {
        if (down != -1 && down < min)
        {
            min = down;
        }
        if (rightgot != -1 && rightgot < min)
        {
            min = rightgot;
        }
        if (left != -1 && left < min)
        {
            min = left;
        }
        if (up != -1 && up < min)
        {
            min = up;
        }
    }
    return min;
}
void Change(int grid[][3], int m, int n)
{
    rep(i, m)
    {
        rep(j, n)
        {
            if (grid[i][j] == 0)
            {
                int count = 0;
                cout << "i=" << i << " j=" << j << endl;
                int anscount = DfsCount(grid, i, j, m, n, count);
                cout << anscount << endl;
                if (anscount != -1)
                    grid[i][j] = count; // changing the value at that location
            }
        }
    }
}
int main()
{
    boost;
    int grid[3][3] = {{1, 0, 0}, {1, 1, 0}, {1, 0, 0}};
    Change(grid, 3, 3);
    return 0;
}