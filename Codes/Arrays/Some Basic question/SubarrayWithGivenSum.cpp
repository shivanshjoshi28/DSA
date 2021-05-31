// wap to check if there exist a subarray with given sum in the array.
// // there can be negative integer in the array also
// the previous question that we did was that in that there was only the +ve integer in the array

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

bool subarrayfound(int arr[], int sum, int n)
{
    unordered_map<int, int> um;
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        if (curr_sum == sum)
        {
            cout << "From " << 0 << "to " << i << endl;
            return true;
        }
        if (um.find(curr_sum - sum) != um.end())
        {
            cout << "From " << um[curr_sum - sum] + 1 << "to " << i << endl;
            return true;
        }
        um[curr_sum] = i;
    }
    return false;
}

int main()
{
    boost;
    int arr[5] = {4, -2, -3, 5, 1};
    int sum = 0;
    int n = 5;
    if (subarrayfound(arr, sum, n))
        cout << "There exist a subarray with the given sum";
    else
        cout << "The subarray doesn't exist ";
    return 0;
}
//O(n)