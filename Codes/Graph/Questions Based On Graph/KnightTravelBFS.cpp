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

struct cell
{
    int x;
    int y;
    int dist;
    cell(int x, int y, int dist)
    {
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
};

bool check(int n, int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n)
        return false;
    return true;
}
int Solve(int n, int sx, int sy, int tx, int ty)
{
    int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
    int x, y, dist;
    queue<cell> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    cell t(sx, sy, 0); // source is at distance from source.
    visited[x][y] = true;
    q.push(t);
    while (!q.empty())
    {
        cell u = q.front();
        cout << u.x << " - " << u.y << endl;
        q.pop();
        if (u.x == tx && u.y == ty)
            return u.dist;
        rep(i, 8)
        {
            x = u.x + dx[i];
            y = u.y + dy[i];
            dist = u.dist + 1;

            if (check(n, x, y) && !visited[x][y])
            {
                cell a(x, y, dist);
                cout << "new cell is made with x= " << x << " y= " << y << " Dist = " << dist << endl;
                visited[x][y] = true;
                q.push(a);
            }
        }
    }
    return -1;
}
void KnightTravel(int n, int sx, int sy, int tx, int ty)
{
    int srx, sry, trx, tryi;
    srx = n - sy;
    sry = sx - 1;
    trx = n - ty;
    tryi = tx - 1;
    cout << "hello" << endl;
    int ans = Solve(n, srx, sry, trx, tryi);
    if (ans == -1)
        cout << "Sorry the target cannot be reached";
    else
        cout << ans << endl;
}
int main()
{
    // boost;
    int n;
    cin >> n;
    cout << "Enter sx, sy, tx,ty ";
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    KnightTravel(n, sx, sy, tx, ty);
    return 0;
}

// https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1/?track=P100-Graph&batchId=197
// TC- O(n^2)