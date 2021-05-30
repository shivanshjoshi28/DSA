// given an unsorted array of non negative integer. find if there is a subarray with the given sum
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

bool SubarrayFind(int arr[], int n, int sum)
{
    int s = 0, e = 1;
    int sumcurr = arr[s];
    for (e = 1; e < n; e++)
    {
        while (sumcurr > sum && s < e - 1)
        {
            sumcurr -= arr[s];
            s++;
        }
        if (sumcurr == sum)
        {

            cout << s << " " << e << endl;
            return true;
        }
        if (e < n)
            sumcurr += arr[e];
    }

    while (sumcurr > sum && s < e - 1)
    {
        sumcurr -= arr[s];
        s++;
    }
    cout << s << " " << e << endl;
    return sumcurr == sum;
}

int main()
{
    boost;
    int arr[6] = {1, 40, 5, 3, 10, 20};
    int sum = 33;
    if (SubarrayFind(arr, 6, sum))
        cout << "There is a subarray";
    else
        cout << " There is no subarray with given sum";
    return 0;
}