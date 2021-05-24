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

int MinSwap(int nums[], int size)
{
    pair<int, int> gr[size];
    rep(i, size)
    {
        gr[i] = MP(nums[i], i);
    }
    sort(gr, gr + size);
    vector<bool> visited(size, false);
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        if (visited[i] || gr[i].second == i)
            continue;

        int j = i;
        int countcyclemember = 0;
        while (!visited[j])
        {
            visited[j] = true;
            j = gr[i].second;
            countcyclemember++;
        }
        if (countcyclemember > 0)
        {
            ans += (countcyclemember - 1);
        }
    }
    return ans;
}
int main()
{
    boost;
    int nums[5] = {1, 5, 4, 3, 2};
    cout << MinSwap(nums, 5);

    return 0;
}
// https://practice.geeksforgeeks.org/problems/minimum-swaps/1/?track=P100-Graph&batchId=197

// TC: O(nlogn )

// Graph approach --> as there will be the cycle