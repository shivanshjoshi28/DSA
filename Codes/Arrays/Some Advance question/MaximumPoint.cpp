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
    int maxScore(vector<int> &arr, int k)
    {
        int leftside[k + 1], rightside[k + 1];
        leftside[0] = 0;
        int index = 1;
        for (int i = 0; i < k; i++)
        {
            leftside[index] = leftside[index - 1] + arr[i];
            index++;
        }
        rightside[k] = 0;
        index = k - 1;
        int count = 0;
        int j = arr.size() - 1;
        while (count <= k)
        {
            rightside[index] = rightside[index + 1] + arr[j];
            j--;
            count++;
            index--;
        }
        //         for(int j=arr.size()-1;j>=arr.size()-k;j--)
        //         {
        //             rightside[index]=rightside[index+1]+arr[j];
        //                 index--;
        //         }

        int ans = INT_MIN;
        for (int i = 0; i < k + 1; i++)
        {
            ans = max(ans, leftside[i] + rightside[i]);
        }
        return ans;
    }
};

int main()
{
    // boost;
    Solution obj;
    // int a[3] = {1, 1000, 1};
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1000);
    arr.push_back(1);
    for (auto it : arr)
        cout << it << endl;
    int k = 1;
    cout << obj.maxScore(arr, k);

    return 0;
}

// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// #include <vector>
// typedef pair<int, int> pii;
// typedef vector<int> vi;
// #define pb push_back
// #define MP make_pair
// #define endl "\n"
// #define boost                         \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL)
// #define F first
// #define S second
// const int inf = (int)1e18;
// const int ninf = (int)-1e17;
// #define rep(a, b) for (int a = 0; a < b; a++)
// #define per(a, b) for (int a = b - 1; a >= 0; a--)
// #define FOR(it, start, end) for (auto it = start; it != end; it++)

// class Solution
// {
// public:
//     void solve(vector<vector<int>> &result, int idx, vector<int> &nums, vector<int> &v)
//     {
//         cout << idx << " " << nums.size() << endl;
//         if (idx == nums.size())
//         {
//             result.push_back(v);
//             return;
//         }
//         solve(result, idx + 1, nums, v);
//         v.push_back(nums[idx]);
//         solve(result, idx + 1, nums, v);
//         v.pop_back();
//     }
//     vector<vector<int>> subsets(vector<int> &nums)
//     {
//         vector<vector<int>> result;
//         vector<int> v;
//         solve(result, 0, nums, v);
//         return result;
//     }
// };
// int main()
// {
//     // boost;
//     vector<int> v;
//     v.push_back(1);
//     v.push_back(2);
//     v.push_back(3);
//     Solution obj;
//     vector<vector<int>> a = obj.subsets(v);
//     for (auto it : a)
//     {
//         for (int i : it)
//             cout << i << " ";
//         cout << endl;
//     }
//     return 0;
// }