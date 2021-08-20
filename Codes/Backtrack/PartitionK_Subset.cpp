// https://www.geeksforgeeks.org/partition-set-k-subsets-equal-sum/
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
bool recur(int arr[],int n,int k,int subset,int subsetSum[],int curridx,bool taken[],int startend)
{
    if(subsetSum[curridx]==subset)
    {
        if(curridx==k-2) return true;  // means filled till second last , no need to fill last 
        return recur(arr,n,k,subset,subsetSum,curridx+1,taken,n-1);
    }
    for(int i=startend;i>=0;i--)
    {
        if(taken[i])continue;
        if((subsetSum[curridx]+arr[i])<=subset)
        {
            taken[i]=true;
            subsetSum[curridx]+=arr[i];
            if(recur(arr,n,k,subset,subsetSum,curridx,taken,i-1)) return true;
            subsetSum[curridx]-=arr[i];
            taken[i]=false;
        }
    }
    cout<<"Return"<<endl;
    cout<<curridx<<" "<<startend<<endl;
    return false;
}
bool isKPartitionPossible(int arr[],int n,int k)
{
    if(k==1) return true;
    if(n<k) return false;
    int sum=0;
    rep(i,n)
    {
        sum+=arr[i];
    }
    if(sum%k!=0) return false;
    int subset=sum/k;
    int subsetSum[k]={0};
    bool taken[n];
    rep(i,n) taken[i]=false;

    subsetSum[0]=arr[n-1];
    taken[n-1]=true;
    return recur(arr,n,k,subset,subsetSum,0,taken,n-1);

}

int main()
{
    boost;
    int arr[] = {2, 1, 4, 5, 6};
    // int arr[] = {2, 1, 5, 5, 6};
	int N = sizeof(arr) / sizeof(arr[0]);
	int K = 3;

	if (isKPartitionPossible(arr, N, K))
		cout << "Partitions into equal sum is possible.\n";
	else
		cout << "Partitions into equal sum is not possible.\n";
    return 0;
}