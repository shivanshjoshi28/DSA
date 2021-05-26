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
    int cost;
    cell(int x, int y, int cost) : x(x), y(y), cost(cost) {}
};
class Comparator
{
public:
    bool operator()(const cell &a, const cell &b) const
    {
        return a.cost > b.cost;
    }
};
bool check(int n, int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n)
        return false;
    return true;
}
void MinimumCost(int grid[][4], int n)
{
    priority_queue<cell, vector<cell>, Comparator> pq;
    pq.push(cell(0, 0, grid[0][0]));

    int dx[8] = {1, 0, 0, -1, 1, -1, 1, -1};
    int dy[8] = {0, 1, -1, 0, 1, -1, -1, 1};
    vector<vector<bool>> foundpath(n, vector<bool>(n, false));
    vector<vector<int>> key(n, vector<int>(n, INT_MAX));
    key[0][0] = grid[0][0];
    while (!pq.empty())
    {
        cell minHeapTop = pq.top();
        int x = minHeapTop.x;
        int y = minHeapTop.y;
        // cout << " X= " << x << " Y= " << y << " Cost = " << minHeapTop.cost << endl;
        pq.pop();
        if (foundpath[x][y])
            continue;
        foundpath[x][y] = true;

        for (int i = 0; i < 8; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (check(n, newx, newy) && !foundpath[newx][newy])
            {
                if (key[x][y] + grid[newx][newy] < key[newx][newy])
                {
                    key[newx][newy] = key[x][y] + grid[newx][newy];
                    cell newinsert(newx, newy, key[newx][newy]);
                    // cout << "Insert :::: cell with x= " << newx << " y=" << newy << " cost =" << key[newx][newy] << endl;
                    pq.push(newinsert);
                }
            }
        }
    }
    cout << key[n - 1][n - 1];
}
int main()
{
    int n = 4;
    // int grid[3][3] = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};
    int grid[4][4] = {{9, 4, 9, 9}, {6, 7, 6, 4}, {8, 3, 3, 7}, {7, 4, 9, 10}};
    MinimumCost(grid, 4);
    return 0;
}