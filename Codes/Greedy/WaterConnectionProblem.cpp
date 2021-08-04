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

#define MAX 100
int checkl[MAX];
int checkr[MAX];
int dia[MAX];
int n, p;
int ans;
vector<int> q;
vector<int> r;
vector<int> t;
int dfs(int w)
{
    if (checkr[w] == 0)
        return w;
    if (dia[w] < ans)
        ans = dia[w];
    return dfs(checkr[w]);
}
void solve(int arr[][3])
{
    for (int i = 0; i < p; i++) // preprocessing
    {
        int a = arr[i][0];
        int b = arr[i][1];
        int c = arr[i][2];
        checkl[b] = a;
        checkr[a] = b;
        dia[a] = c;
    }
    // q.clear();
    // r.clear();
    // t.clear();

    for (int i = 1; i <= n; i++)
    {
        if (checkl[i] == 0 and checkr[i])
        {
            ans = INT_MAX;
            int j = dfs(i); // then we include path from i to j
            q.push_back(i);
            r.push_back(j);
            t.push_back(ans);
        }
    }
    for (int i = 0; i < q.size(); i++)
    {
        cout << q[i] << " - " << r[i] << " - " << t[i] << endl;
    }
}
int main()
{
    boost;
    n = 9, p = 6;

    memset(checkl, 0, sizeof(checkl));
    memset(checkr, 0, sizeof(checkr));
    memset(dia, 0, sizeof(dia));

    int arr[][3] = {{7, 4, 98},
                    {5, 9, 72},
                    {4, 6, 10},
                    {2, 8, 22},
                    {9, 7, 17},
                    {3, 1, 66}};
    solve(arr);
    return 0;
}