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
class Solution
{
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void BFSUtil(vector<vector<int>> &arr, int x, int y, int m, int n, int Color)
    {
        queue<pair<int, int>> q;
        q.push({x, y});
        int originalColor = arr[x][y];
        arr[x][y] = Color;

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newx = dx[i] + front.first;
                int newy = dy[i] + front.second;
                cout << newx << " " << newy << endl;
                if (newx >= 0 and newx < m and newy >= 0 and newy < n and arr[newx][newy] == originalColor)
                {
                    arr[newx][newy] = Color;
                    q.push({newx, newy});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int m = image.size();
        int n = image[0].size();
        BFSUtil(image, sr, sc, m, n, newColor);
        return image;
    }
};

int main()
{
    // boost;
    Solution obj;
    vector<vector<int>> arr;
    vector<int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    arr.push_back(v);
    v.clear();
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    arr.push_back(v);
    // v.clear();
    // v.push_back(1);
    // v.push_back(0);
    // v.push_back(1);
    // arr.push_back(v);
    for (auto it : arr)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    vector<vector<int>> a = obj.floodFill(arr, 1, 1, 1);
    for (auto it : a)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}