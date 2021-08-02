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

class Solution {
public:
    double Pow(double x, int n) {   
        double res=1;
        while(n)
        {
            if(n%2!=0)  // odd
            {
                res=res*x;
            }
            
            n=n>>1;
            x=x*x;
        }
        return res;
    }
        double myPow(double x, int n) {
            if(n==0) return 1;
            else if(n>1) return Pow(x,n);
            else return 1/Pow(x,-1*n);
    }
};

int main()
{
    boost;
    Solution obj;
    cout<<obj.m
    return 0;
}