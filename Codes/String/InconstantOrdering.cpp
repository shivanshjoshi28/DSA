// https://codingcompetitions.withgoogle.com/codejamio/round/00000000004360f2/00000000007772ed#problem
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void inserteven(int start,int end , vector<char>&ch,vector<int>v,int i)
{
    char curr='B';
    // cout<<"i= "<<i<<endl;
    int k=i;
    // cout<<i<<" to "<<k+start-1<<endl;
    // cout<<start<<" "<<end<<endl;
    for(i;i<=k+start-1;i++)
    {
        ch[i]=curr;
        curr++;
    }
    curr='A';
    int j;
    // cout<<i+end-1<<" to "<<i<<endl;
    for(j=i+end-1;j>=i;j--)
    {
        ch[j]=curr;
        curr++;
    }
    if(ch[i-1]<=ch[j+1])
    {
        ch[i-1]=ch[j+1]+1;
    }

}
void solve(int n,vector<int>v,int count)
{
    int sum=1;
    for(auto i:v) sum+=i;
    vector<char>ch(sum,' ');
    ch[0]='A';
    if(n==1)
    {
        char curr='B';
        for(int i=1;i<=v[0];i++)
        {
            ch[i]=curr;
            curr++;
        }
    }
    if(n==2)
    {
        int start= v[0];
        int end= v[1];
        int index=1;
        inserteven(start,end,ch,v,index);
    }

    if(n%2==0)
    {
        int grp= n/2;
        int index=1;
        for(int i=0;i<grp;i++)
        {
            int start= v[i*2];
            int end= v[(i*2)+1];
            inserteven(start,end,ch,v,index);
            index+=(start+end);
        }
    }
    else
    {
        int grp= n/2;
        int index=1;
        for(int i=0;i<grp;i++)
        {
            int start= v[i*2];
            int end= v[(i*2)+1];
            inserteven(start,end,ch,v,index);
            index+=(start+end);
        }
        // cout<<"index= "<<index<<endl;
        char curr='B';
        for(int i=index;i<=index+v[n-1]-1;i++)
        {
            ch[i]=curr;
            curr++;
        }
    }
    cout<<"Case #"<<count<<": ";
    for(char c:ch) cout<<c;
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    int count=1;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        solve(n,v,count);
        count++;
    }
    return 0;
}