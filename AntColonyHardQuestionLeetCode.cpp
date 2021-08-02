#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<long long> fact;
    vector<long long> invfact;
    unordered_map<long long, vector<long long>> AdjList;
    long long mod = 1000000007;
    long long pow(long long a, long long b, long long MOD)
    {
        long long x = 1, y = a;
        while (b > 0)
        {
            if (b % 2 == 1)
            {
                x = (x * y);
                if (x > mod)
                    x %= mod;
            }
            y = (y * y);
            if (y > mod)
                y %= mod;
            b /= 2;
        }
        return x;
    }
    void setup(long long n)
    {
        fact.resize(n);
        invfact.resize(n);
        fact[0] = 1;
        invfact[0] = pow(fact[0], mod - 2, mod);
        for (long long i = 1; i < n; i++)
        {
            fact[i] = (fact[i - 1] * i) % mod;
            invfact[i] = pow(fact[i], mod - 2, mod);
        }
    }
    long long dfs(long long curr, long long &count)
    {
        if (AdjList.find(curr) == AdjList.end()) // it means the leaf node.
        {
            return 1;
        }

        long long ways = 1;
        long long currNodeCount = 0;

        for (auto child : AdjList[curr]) // iterate through all child of curr
        {
            long long SubTreeNodeCnt = 1;
            long long SubTreeWays = dfs(child, SubTreeNodeCnt);
            long long combinations = (fact[currNodeCount + SubTreeNodeCnt] % mod * invfact[currNodeCount] % mod * invfact[SubTreeNodeCnt] % mod) % mod;
            ways = (ways % mod * combinations % mod * SubTreeWays % mod) % mod;
            currNodeCount += SubTreeNodeCnt;
        }
        count = currNodeCount + 1;
        return ways;
    }
    long long waysToBuildRooms(vector<int> &prevRoom)
    {
        long long n = prevRoom.size();
        setup(n);
        for (long long i = 0; i < prevRoom.size(); i++)
        {
            AdjList[prevRoom[i]].push_back(i);
        }
        long long count = 1;
        return dfs(0, count);
    }
};
int main()
{
    // boost;
    Solution obj;
    vector<int> v;
    v.push_back(-1);
    v.push_back(0);
    v.push_back(1);

    cout << obj.waysToBuildRooms(v);
    return 0;
}