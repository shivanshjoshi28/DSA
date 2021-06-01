/*Author : Shivansh Joshi
Btech: 2nd yr(Batch: 2019-23)
*/
///====================== TEMPLATE STARTS HERE =====================///
#include <bits/stdc++.h>
using namespace std;
#include <vector>

//#include <sys/resource.h>     // for linux stack memory increase
//#define gc getchar_unlocked   // for linux fast io
//#define gc getchar            // for windows fast io
#define ONLINE_JUDGE

#define endl "\n"
#define boost                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define dbg(x, y) cout << (x) << " -->  " << (y) << endl
#define F first
#define S second
#define ST startTime = (double)clock();
const int N = 2e2 + 20;
const int inf = (int)1e18;
const int ninf = (int)-1e17;
const int mod = 1e9 + 7;
#define rep(a, b) for (int a = 0; a < b; a++)
#define per(a, b) for (int a = b - 1; a >= 0; a--)
#define FOR(it, start, end) for (auto it = start; it != end; it++)

#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n ", x)
#define pl(x) printf("%lld\n ", x)
#define ps(s) printf("%s\n ", s)

double startTime;

double getCurrentTime()
{
    return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
///======================  TEMPLATE ENDS HERE  =====================///

pair<int, int> findfirstnum(int G, int x)
{
    for (int i = 1; i <= G; i++)
    {
        int start = i;
        if (start == G)
            return make_pair(G, G);
        int sum = 0;
        while (sum < x && start < G)
        {
            sum += start;
            // cout << sum << endl;
            start++;
        }
        if (sum == x)
        {
            return make_pair(i, start - 1);
        }
    }
    return make_pair(0, 0);
}

int solve(int G, int x)
{
    pair<int, int> first_till_its_end = findfirstnum(G, G);
    if (first_till_its_end.first == G)
        return 1;
    int count = 1;

    int start = first_till_its_end.first;
    // cout << "start" << start << endl;
    int end = first_till_its_end.second;
    int sumgot = G;
    for (int i = start + 1; i <= G; i++)
    {
        start = i;
        sumgot -= (start - 1);
        // sumgot+=end;
        // cout << "sumgot = " << sumgot << endl;
        // cout << "start=" << start << " end= " << end << endl;
        while (sumgot < G && end <= G)
        {
            sumgot += (end + 1);
            end++;
        }
        // cout << "sumgot afater = " << sumgot << endl;
        // cout << end << endl;
        if (sumgot == x)
        {
            count++;
        }
        else
        {
            sumgot -= end;
            end--;
        }
    }
    return count;
}

int main()
{
    ST;
    // freopen("inp.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    boost;
    // srand(time(NUll));
    // rand()%1Eno.of digit you want-1;
    int t;
    cin >> t;
    rep(i, t)
    {
        int G;
        cin >> G;
        int ans = solve(G, G);
        // int ans;
        cout << "Case #" << i + 1 << ":";
        cout << ans << endl;
    }
    return 0;
}