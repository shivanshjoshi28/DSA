// wap to count a particular no. in an sorted array

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
    int arr[10] = {1, 2, 3, 4, 4, 5, 5, 5, 5, 2};
    int x = 5; // this is item to be searched and whose frequency is to be counted.
    int n = 10;
    // First approach can be to count the frequency simply by linear search

    // But We will do it by O(log n),using the concept of Binary Search

    int start = 0;
    int end = n - 1;
    int StartIndex = -1, EndIndex;

    while (start <= end)
    {
        int mid = (end - start) / 2 + start;
        if (arr[mid] < x)
        {
            start = mid + 1;
        }
        else if (arr[mid] > x)
        {
            end = mid - 1;
        }
        else
        {
            if (mid == 0 || arr[mid - 1] != arr[mid])
            {
                StartIndex = mid;
                break;
            }
            else
                end = mid - 1;
        }
    }
    if (StartIndex == -1)
    {
        cout << "Sorry the answer is not possible ";
        return 0;
    }

    start = 0, end = n - 1, EndIndex = -1;

    while (start <= end)
    {
        int mid = (end - start) / 2 + start;
        if (arr[mid] < x)
        {
            start = mid + 1;
        }
        else if (arr[mid] > x)
        {
            end = mid - 1;
        }
        else
        {
            if (mid == n - 1 || arr[mid + 1] != arr[mid])
            {
                EndIndex = mid;
                break;
            }
            else
                start = mid + 1;
        }
    }

    cout << EndIndex - StartIndex + 1;
    return 0;
}