#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int countofArray(int n, int m)
{
    int dp[n + 1][m + 1];

    // to store factors
    vector<int> fa[MAX];

    // to store multiples
    vector<int> mu[MAX];

    //initialize elements of dp, fa, mu by 0
    memset(dp, 0, sizeof(dp));
    memset(fa, 0, sizeof(fa));
    memset(mu, 0, sizeof(mu));

    // for calculating factors and multiples of elements
    for (int i = 1; i <= m; i++)
    {
        fa[i].push_back(i); //every no is a factor of itself
        for (int j = 2; j * i <= m; j++)
        {
            int k = j * i;
            mu[i].push_back(k); //n is a multiple of i
            fa[k].push_back(i); //i is a factor of n
        }
    }
    for (auto it : fa)
    {
        for (int I : it)
        {
            cout << I << " ";
        }
        cout << endl;
    }

    for (auto it : mu)
    {
        for (int I : it)
        {
            cout << I << " ";
        }
        cout << endl;
    }

    // number of arrays possible of
    //size 1 starting with i is always 1
    for (int i = 1; i <= m; i++)
        dp[1][i] = 1;

    // number of arrays possible of
    // size i and starting with j
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // Adding number of factors
            for (auto x : fa[j])
                dp[i][j] += dp[i - 1][x];

            // Adding number of multiples
            for (auto x : mu[j])
                dp[i][j] += dp[i - 1][x];
        }
    }

    // Adding the elements of last row
    int ans = 0;
    for (int j = 1; j <= m; j++)
    {
        ans += dp[n][j];
        mu[j].clear();
        fa[j].clear();
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << countofArray(n, m) << "\n";
    return 0;
}