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
#define N 3
int getminindex(vector<int> arr)
{
    int min = arr[0];
    int minind = 0;
    rep(i, arr.size())
    {
        if (arr[i] < min)
        {
            min = arr[i];
            minind = i;
        }
    }
    return minind;
}
int getmaxindex(vector<int> arr)
{
    int max = arr[0];
    int maxind = 0;
    rep(i, arr.size())
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxind = i;
        }
    }
    return maxind;
}
void solverecur(vector<int> amt)
{
    int DebtPerson = getminindex(amt);
    int CreditPerson = getmaxindex(amt);
    if (amt[DebtPerson] == 0 and amt[CreditPerson] == 0)
        return;
    int x = min(-amt[DebtPerson], amt[CreditPerson]);
    amt[DebtPerson] += x;
    amt[CreditPerson] -= x;
    cout << "Person " << DebtPerson << " pays " << x << " to Person " << CreditPerson << endl;
    solverecur(amt);
}
void minCashFlow(int graph[][N])
{
    vector<int> amt(N, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            amt[i] += (graph[j][i] - graph[i][j]);
        }
    }
    solverecur(amt);
}

int main()
{
    boost;
    int graph[N][N] = {
        {0, 1000, 2000},
        {0, 0, 5000},
        {0, 0, 0},
    };

    // Print the solution
    minCashFlow(graph);
    return 0;
}