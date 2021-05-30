// find the majority element in the array i.e the element that comes more than n/2 times in an array

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

bool checkmajority(int arr[], int n, int me)
{
    int count = 0;
    rep(i, n)
    {
        if (arr[i] == me)
            count++;
    }
    if (count <= n / 2)
        return false;
    else
        return true;
}
int main()
{
    boost;
    int arr[5] = {8, 3, 4, 8, 8};
    int result = 0;
    int n = 5;
    int majorityelement = arr[0];
    int curr = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == majorityelement)
            curr++;
        else
        {
            curr = 1;
            majorityelement = arr[i];
        }
    }
    if (checkmajority(arr, n, majorityelement))
        cout << majorityelement << endl;
    else
        cout << " Majority element doesn't exist" << endl;
    return 0;
}

// it will find the majority element in the TC of O(n)