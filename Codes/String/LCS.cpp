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
int dp[1001][1001];

lcsusingRecursion(int x,int y, string s1,string s2)   // O(x*y) TC & O(x*y) SC
{
    if(x==-1 or y==-1) return 0;
    if(dp[x][y]!=-1) return dp[x][y];

    if(s1[x]==s2[y]) return dp[x][y]=1+lcsusingRecursion(x-1,y-1,s1,s2);

    int a= lcsusingRecursion(x-1,y,s1,s2);
    int b= lcsusingRecursion(x,y-1,s1,s2);
    return dp[x][y]=max(a,b);
}
int Dp2dArraySolution(string s1,string s2)
{
    int x=s1.length(),y=s2.length();
    int DpArray[x+1][y+1];
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            if(i==0 or j==0) DpArray[i][j]=0;
            else if(s1[i-1]==s2[j-1])
            {
                DpArray[i][j]=1+DpArray[i-1][j-1];
            }
            else
            {
                DpArray[i][j]=max(DpArray[i][j-1],DpArray[i-1][j]);
            }
        }
    }

    char lcs[DpArray[x][y]+1];
    lcs[DpArray[x][y]]='\0';
    int i=x,j=y;
    int index= DpArray[x][y]-1;
    while(i>0 or j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            lcs[index]=s1[i-1];
            i--;
            j--;
            index--;
        }
        else if(DpArray[i-1][j]>DpArray[i][j-1]) i--;
        else j--;
    }
    cout<<"Subsequence is : "<<lcs<<endl;
    return DpArray[x][y];

}

int DP2dArrayOptimizedSolution(string s1,string s2)
{
    int x=s1.length(),y=s2.length();
    int DpArray[2][y+1];
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            if(i==0 or j==0) DpArray[i%2][j]=0;

            else if(s1[i-1]==s2[j-1])
            {
                DpArray[i%2][j]=1+DpArray[(i+1)%2][j-1];
            }
            else
            {
                DpArray[i%2][j]=max(DpArray[i%2][j-1],DpArray[(i+1)%2][j]);
            }
        }
    }
    return DpArray[x%2][y];
}

int main()
{
    string s1="ABCDGH",s2="AEDFHR";
    memset(dp,-1,sizeof(dp));
    cout<<lcsusingRecursion(s1.length()-1,s2.length()-1,s1,s2)<<endl;
    cout<<Dp2dArraySolution(s1,s2)<<endl;
    cout<<DP2dArrayOptimizedSolution(s1,s2);
    return 0;
}



// this method is also using in maximum recurring subsequence