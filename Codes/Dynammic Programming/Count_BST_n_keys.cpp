#include<bits/stdc++.h>
#include <iostream>
using namespace std;

#include<vector>
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back
#define MP make_pair
#define endl "\n"
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
const int inf =(int) 1e18;
const int ninf = (int)-1e17;
#define rep(a, b) for (int a = 0; a < b; a++)
#define per(a, b) for (int a = b - 1; a >= 0; a--)
#define FOR(it, start, end) for (auto it = start; it != end; it++)

int countBST(int n)     // O (n^2)
{
    int count[n+1];
    count[0]=1;
    for(int i=1;i<=n;i++)
    {
        count[i]=0;
        for(int j=0;j<i;j++)
        {
            count[i]+=(count[j]*count[i-j-1]);
        }
    }
    return count[n];
}

int main()
{
    boost;
    int n=5;
    cout<<countBST(n);
    return 0;
}

// ex n= 3
// 1,2,3  

// make BST

// first ->       1                                   second ->              2                                       third->           3
//                 on right side ( 2,3 )                    on left side(1)     on right side(3)                            on left side(1,2)

//                 2                        +                               1 *  1                             +                       2

//         Final ans = 5




// this is also be done using the Catalan series , as it is directly the finding the n th element in Catalan series
// Ans(n) = 1               2n
//         ......     X        C
//           (n+1)               n