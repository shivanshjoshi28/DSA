// https://www.geeksforgeeks.org/given-a-string-print-all-possible-palindromic-partition/
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

bool isPalindrome(int l,int h,string str)
{
    while(l<h)
    {
        if(str[l]!=str[h])
        return false;
        l++;
        h--;
    }
    return true;
}
void BackTrack(vector<vector<string>>&all,vector<string>&curr,int start,int n,string str)
{
    if(start>=n)
    {
        all.push_back(curr);
        return;
    }
    for(int i=start;i<n;i++)
    {
        if(isPalindrome(start,i,str))
        {
            curr.push_back(str.substr(start,i-start+1));
            BackTrack(all,curr,i+1,n,str);
            curr.pop_back();
        }
    }
}
void solve(string str)
{
    vector<vector<string>>all;
    vector<string>curr;
    int n=str.length();
    BackTrack(all,curr,0,n,str);

    for(auto it:all)
    {
        for(auto itt:it)
        {
            cout<<itt<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    boost;
    string str;
    cin>>str;
    solve(str);
    
    return 0;
}