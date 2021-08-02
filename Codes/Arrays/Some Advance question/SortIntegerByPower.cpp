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
    int calcpower(int a)
    {
        int count = 0;
        while (a != 1)
        {
            cout << a << endl;
            if (a % 2 == 0)
            {
                a = a / 2;
            }
            else
            {
                a = 3 * a + 1;
            }
            count++;
        }
        cout << "final count = " << count << endl;
        return count;
    }
    int getKth(int lo, int hi, int k)
    {
        vector<pair<int, int>> sorted_arr;
        for (int i = lo; i <= hi; i++)
            sorted_arr.push_back({0, i});
        // for (auto sorted : sorted_arr)
        //     cout << sorted.first << " " << sorted.second << endl;
        int index = 0;
        for (int i = lo; i <= hi; i++)
        {
            cout << "hello";
            sorted_arr[index].first = calcpower(i);
            index++;
        }
        stable_sort(sorted_arr.begin(), sorted_arr.end());
        return sorted_arr[k - 1].second;
    }
};
int main()
{
    // boost;
    Solution obj;
    cout << obj.getKth(12, 15, 2);
    return 0;
}