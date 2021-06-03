// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

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

int BestTimeToBuy(int arr[], int n)
{
    int Price = INT_MAX;
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < Price)
        {
            Price = arr[i];
        }
        else
        {
            if ((arr[i] - Price) > profit)
                profit = arr[i] - Price;
        }
    }
    return profit;
}

int main()
{
    boost;
    int prices[5] = {7, 6, 4, 3, 1};
    int n = 5;
    cout << BestTimeToBuy(prices, n);
    return 0;
}