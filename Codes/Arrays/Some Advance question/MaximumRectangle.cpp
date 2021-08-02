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
    int largestareahistogram(vector<int> height)
    {
        stack<int> s;
        int maxArea = 0;
        height.push_back(0);
        s.push(0);
        // cout << "Hello" << endl;
        for (int i = 1; i < height.size(); i++)
        {
            cout << "hello" << endl;
            while (!s.empty() && height[s.top()] >= height[i])
            {
                int temp = height[s.top()];
                int rl = i;
                s.pop();
                int ll;
                if (s.empty())
                    ll = -1;
                else
                    ll = s.top();
                maxArea = max(maxArea, temp * (rl - ll - 1));
                cout << "*" << maxArea << endl;
            }
            s.push(i);
        }
        // cout << maxArea;
        // return 0;
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.size() == 0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;
        vector<int> height(matrix[0].size(), 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '0')
                {
                    height[j] = 0;
                }
                else
                    height[j]++;
            }
            for (auto it : height)
                cout << it << " ";
            cout << endl;
            maxArea = max(maxArea, largestareahistogram(height));
        }

        return maxArea;
    }
};
int main()
{
    // boost;
    Solution obj;
    vector<vector<char>> matrix;
    vector<char> v;
    v.push_back('0');
    // v.push_back('1');
    // v.push_back('0');
    // v.push_back('1');
    // v.push_back('0');
    // v.push_back('0');
    // matrix.push_back(v);
    // v.clear();
    // v.push_back('1');
    // v.push_back('0');
    // v.push_back('1');
    // v.push_back('1');
    // v.push_back('1');
    // matrix.push_back(v);
    // v.clear();
    // v.push_back('1');
    // v.push_back('1');
    // v.push_back('1');
    // v.push_back('1');
    // v.push_back('1');
    // matrix.push_back(v);
    // v.clear();
    // v.push_back('1');
    // v.push_back('0');
    // v.push_back('0');
    // v.push_back('1');
    // v.push_back('0');
    matrix.push_back(v);
    cout << obj.maximalRectangle(matrix);
    return 0;
}