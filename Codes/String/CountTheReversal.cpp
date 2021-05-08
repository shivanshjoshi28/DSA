// https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1
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
int count(string s)
{
    if(s.length()&1) return -1;
    stack<char>st;
    int c=0,c2=0;
    for(int i=0;i<s.length();i++)
    {
        char brckt=s[i];
        if(brckt=='{')
        {
            st.push(brckt);
            c2++;
        }
        else if(brckt=='}' and !st.empty() and st.top()=='{')
        {
            st.pop();
            c2--;
        }
        else
            c++;
    }
    if(c&1) c=(c/2)+1;
    else c=c/2;
    if(c2&1) c2=(c2/2)+1;
    else c2/=2;
    return c+c2;
}
int main()
{
    string s="{{}{{{}{{}}{{";
    cout<<count(s);
    return 0;
}
// this is stack+string problem