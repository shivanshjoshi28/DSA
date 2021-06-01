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

double getMedian(int a1[], int a2[], int n1, int n2)
{
    int begin = 0, end = n1; // assumption n1<=n2
    while (begin < end)
    {
        int i1 = (begin + end) / 2;
        int i2 = (n1 + n2 + 1) / 2 - i1;

        int max1 = (i1 == 0) ? INT_MIN : a1[i1 - 1];
        int max2 = (i2 == 0) ? INT_MIN : a2[i2 - 1];
        int min1 = (i1 == n1) ? INT_MAX : a1[i1];
        int min2 = (i2 == n2) ? INT_MAX : a2[i2];

        if (max1 < min2 && max2 < min1)
        {
            if ((n1 + n2) % 2 == 0)
                return (max(max1, max2) + min(min1, min2)) / 2.0;
            else
                return (max(max1, max2));
        }
        else if (max1 > min2)
        {
            end = i1 - 1;
        }
        else
            begin = i1 + 1;
    }
    return -1;
}
int main()
{
    boost;
    int arr1[5] = {10, 20, 30, 40, 50};
    int arr2[5] = {5, 15, 25, 35, 45};
    // naive solution first merging the both sorted array into one, whose time complexity is n1+n2. then finally printing the mid;
    // efficient solution - O(n1log n1)          if n1<n2; else O(n2log n2)
    cout << getMedian(arr1, arr2, 5, 5);

    return 0;
}