// leet code Combination Sum problem
// https://leetcode.com/problems/combination-sum/

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

void backtrack(vector<int> &arr, int idx, int target, vector<int> &v, vector<vector<int>> &result)
{
    if (target == 0)
    {
        result.push_back(v);
        return;
    }
    if (target < 0)
        return;

    for (int i = idx; i < arr.size(); i++)
    {
        if (arr[i] <= target)
        {
            target -= arr[i];
            v.push_back(arr[i]);
            backtrack(arr, i, target, v, result);
            target += arr[i];
            v.pop_back();
        }
        else
            break;
    }
}

vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    vector<int> v;
    backtrack(arr, 0, target, v, result);
    return result;
}
int main()
{
    boost;
    int a[4] = {10, 2, 3, 5};
    vector<int> arr(a, a + 3);
    int target = 8;
    vector<vector<int>> v = combinationSum(arr, target);
    for (auto U : v)
    {
        for (int k : U)
            cout << k << " ";
        cout << endl;
    }
    return 0;
}