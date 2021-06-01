// peak element is that whose just left and right side element is less than that particular element
// print any of the peak element in the array.
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

int main()
{
    boost;
    int arr[5] = {5, 10, 20, 15, 7};
    int n = 5;
    int low = 0;
    int high = n - 1;
    if (n >= 2 && arr[0] > arr[1])
    {
        cout << 0 << endl;
        return 0;
    }
    if (n >= 2 && arr[n - 1] > arr[n - 2])
    {
        cout << 0 << endl;
        return 0;
    }
    while (low < high)
    {
        int mid = (low + high) / 2;
        if ((mid == 0 || arr[mid - 1] < arr[mid]) && (mid == n - 1 || arr[mid] > arr[mid + 1]))
        {
            cout << mid;
            return 0;
        }
        if (mid > 0 && arr[mid - 1] > arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}