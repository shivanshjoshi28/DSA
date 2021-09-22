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


class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int arr[n][m];
        int res=0;
        for(int i=0;i<n;i++)
        {
            arr[i][0]=mat[i][0];
            res=max(res,arr[i][0]);
        }
        for(int i=0;i<m;i++)
        {
            arr[0][i]=mat[0][i];
            res=max(res,arr[0][i]);
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                arr[i][j]=0;
                if(mat[i][j]==1)
                {
                    arr[i][j]=1+min(arr[i][j-1],min(arr[i-1][j],arr[i-1][j-1]));
                }
                res=max(res,arr[i][j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<arr[i][j]<< " ";
            }
            cout<<endl;
        }
        return res;
    }
    
};

int main()
{
    // boost;
    Solution obj;
    vector<vector<int>>mat={
        {0, 1 ,0 ,1, 0, 1},
        {1, 0 ,1 ,0, 1, 0},
        {0, 1 ,1 ,1, 1, 0},
        {0, 0 ,1 ,1, 1, 0},
       { 1, 1 ,1 ,1, 1, 1},
    };
    cout<<obj.maxSquare(5,6,mat);
    
    return 0;
}