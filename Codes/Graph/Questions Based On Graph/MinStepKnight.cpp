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

int Solve(vector<vector<int>> &board, int x, int y, int tpx, int tpy, int n, int count)
{
    // cout << "x= " << x << " - " << y << endl;
    if (x < 0 || x >= n || y < 0 || y >= n || board[x][y] == 2)
        return INT_MAX;

    if (x == tpx && y == tpy)
        return count;

    board[x][y] = 2; // setting it as visited

    int downleft = Solve(board, x + 2, y - 1, tpx, tpy, n, count + 1);

    int downright = Solve(board, x + 2, y + 1, tpx, tpy, n, count + 1);

    int upleft = Solve(board, x - 2, y - 1, tpx, tpy, n, count + 1);

    int upright = Solve(board, x - 2, y + 1, tpx, tpy, n, count + 1);

    int leftup = Solve(board, x - 1, y - 2, tpx, tpy, n, count + 1);

    int leftdown = Solve(board, x + 1, y - 2, tpx, tpy, n, count + 1);

    int rightup = Solve(board, x - 1, y + 2, tpx, tpy, n, count + 1);

    int rightdown = Solve(board, x + 1, y + 2, tpx, tpy, n, count + 1);

    board[x][y] = 0;
    return min(downleft, min(downright, min(upleft, min(upright, min(leftup, min(leftdown, min(rightup, rightdown)))))));
}

int Track(int knightPos[], int targetPos[], int n)
{
    int kpx = n - knightPos[1];
    int kpy = knightPos[0] - 1;

    int tpx = n - targetPos[1];
    int tpy = targetPos[0] - 1;
    vector<vector<int>> board;
    rep(i, n)
    {
        vector<int> sample;
        rep(j, n)
            sample.push_back(0);
        board.push_back(sample);
    }
    board[kpx][kpy] = 1; // source;
    board[tpx][tpy] = 1; // destination
    int count = 0;
    return Solve(board, kpx, kpy, tpx, tpy, n, count);
}

int main()
{
    boost;
    int n;
    cin >> n;
    int knightPos[2] = {4, 5};
    int targetPos[2] = {1, 1};
    cout << Track(knightPos, targetPos, n);
    return 0;
}

// It is based on DFS traversal technique. It moves through all the path that might be possible the the target node
