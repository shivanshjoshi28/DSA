// https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1
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

int minswapreq(string s)
{
    int ans=0;
    vector<int>v;
    int count=0,idx=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='[') v.push_back(i);
    }
    for(int i=0;i<s.length();i++)
    {
        char curr=s[i];
        if(curr=='[')
        {
            count++;
            idx++;
        }
        else
        {
            count--;
            if(count<0)
            {
                ans+=v[idx]-i;
                swap(s[i],s[v[idx]]);
                idx++;
                count=1;
            }
        }
    }
    return ans;
}
int main()
{
    string brckt="]]][[[";
    cout<<minswapreq(brckt);
    return 0;
}

/*

]]][[[           []]][[   3-0
]][][[1
][]][[2
[]]][[3    3-0

[]][][ 4
[][]][ 5         [][]][   4-2
[][][] 6         [][][]   5-4 =1


3+2+1=6



*/