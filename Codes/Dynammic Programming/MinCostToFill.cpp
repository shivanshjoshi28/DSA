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


int recur(int arr[],int n,int sum)
	{
        cout<<n<<" "<<sum<<endl;
	    if(sum==0) return 0;
	    if(n==0) return INT_MAX;
	   // int res=-1;
	    int res=recur(arr,n-1,sum);
	    if(n<=sum and arr[n-1]!=-1)
	    {
            cout<<"yes"<<endl;
	        int a= recur(arr,n,sum-(n));
	        if(a!=INT_MAX)
	        {
	            res=min(res,arr[n-1]+a);
	        }
	    }
	    return res;
	}

int main()
{
    // boost;
    int arr[5]={-1, -1, 4, 3, -1};
    int n=5;
    int sum=5;
    int res= recur(arr,n,sum);
    if(res==INT_MAX) cout<<-1;
    else cout<<res;
    return 0;
}