// https://leetcode.com/problems/4sum/
// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]

// Constraints:

// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

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

vector<pair<int, int>> SearchPair(vector<int> &arr, int n, int start, int target)
{
    int s = start, e = arr.size() - 1;
    vector<pair<int, int>> res;
    while (s < e)
    {
        if (arr[s] + arr[e] == target)
        {
            res.push_back(MP(arr[s], arr[e]));
            s++;
            e--;
        }
        else if (arr[s] + arr[e] > target)
            e--;
        else
            s++;
    }
    return res;
}
set<vector<int>> FourSum(vector<int> &arr, int trg)
{
    sort(arr.begin(), arr.end());
    set<vector<int>> result;
    int n = arr.size();
    for (int i = 0; i <= n - 4; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue; // as the starting from that is alreaay so , its not complusory to iterate through this , as it will automatically ignored by the set
        int threetarget = trg - arr[i];
        for (int j = i + 1; j <= n - 3; j++)
        {
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;
            // as the starting from that is alreaay so , its not complusory to iterate through this , as it will automatically ignored by the set
            int twotarget = threetarget - arr[j];
            vector<pair<int, int>> gotpairs = SearchPair(arr, n, j + 1, twotarget);
            if (gotpairs.size() != 0)
            {
                for (auto eachpair : gotpairs)
                {
                    vector<int> v;
                    v.push_back(arr[i]);
                    v.push_back(arr[j]);
                    v.push_back(eachpair.first);
                    v.push_back(eachpair.second);
                    result.insert(v);
                }
            }
        }
    }
    return result;
}

int main()
{
    // boost;
    int a[6] = {1, 0, -1, 0, -2, 2};
    vector<int> arr(a, a + 6);
    int target = 0;
    set<vector<int>> v = FourSum(arr, target);
    for (auto U : v)
    {
        for (int k : U)
            cout << k << " ";
        cout << endl;
    }
    return 0;
}

// TC- O(N^3)