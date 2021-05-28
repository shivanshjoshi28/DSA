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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char movement[4] = {'D', 'U', 'R', 'L'};
bool checkrange(int N, int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= N)
        return false;
    return true;
}
void DFSUtil(vector<vector<char>> &Path, int arr[][4], int N, int x, int y, vector<vector<bool>> &visited, vector<char> &str)
{
    if (x == N - 1 && y == N - 1)
    {
        Path.push_back(str);
        return;
    }

    rep(i, 4)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (checkrange(N, newx, newy) && !visited[newx][newy] && arr[newx][newy] == 1)
        {
            visited[newx][newy] = true;
            str.push_back(movement[i]);
            DFSUtil(Path, arr, N, newx, newy, visited, str);
            str.pop_back();
            visited[newx][newy] = false;
        }
    }
}
void RatPath(int arr[][4], int N)
{
    vector<vector<char>> Path;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<char> str;
    DFSUtil(Path, arr, N, 0, 0, visited, str);
    if (Path.size() == 0)
        cout << -1;
    else
    {
        for (auto i : Path)
        {
            for (auto c : i)
                cout << c << " ";
            cout << endl;
        }
    }
}
int main()
{
    // boost;
    int N = 4;
    int arr[4][4] = {{1, 0, 0, 0},
                     {1, 1, 0, 1},
                     {1, 1, 0, 0},
                     {0, 1, 1, 1}};

    RatPath(arr, N);
    return 0;
}