// https://practice.geeksforgeeks.org/problems/word-break1352/1
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void run()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}
unordered_map<string,int>dp;
calc(string s, vector<string> &dic)
{
    int sz=s.length();
    if(sz==0) return 1;
    if(dp[s]!=0) return dp[s];


    for(int i=1;i<=sz;i++)
    {
        int f=0;
        string ss=s.substr(0,i);
        for(int j=0;j<dic.size();j++)
        {
            if(ss.compare(dic[j])==0)
            {
                f=1;
                break;
            }
        }
        if(f==1 and calc(s.substr(i,sz-i),dic)==1) return dp[s]=1;
    }

    return dp[s]=-1;
}
int wordBreak(string A, vector<string> &B) {
    if(calc(A,B)==1) return 1;
    else return 0;
}

int main()
{
    string s="ilikesamsung";
    vector<string>v{ "i", "like", "sam", "sung", "samsung", "mobile",
"ice","cream", "icecream", "man", "go", "mango" };
    cout<<wordBreak(s,v);
    return 0;
}
// this is solved using DP
// memoization concept