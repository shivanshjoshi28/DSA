// https://www.geeksforgeeks.org/find-count-number-given-string-present-2d-character-array/


// &


// https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1


// are same 
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

// void run()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("inp.txt","r",stdin);
//     freopen("out.txt","w",stdout);
// #endif
// }
int countString(int i,int j, string s,vector<vector<char>>input,int size,int indStr,int path)
{
    int found=0;
    if(i>=0 && j>=0 && i<input.size() && j<input[0].size() && s[indStr]==input[i][j])
    {
        char temp=s[indStr];
        input[i][j]='0';
        indStr++;
        if(indStr==size)
        {
            found=1;
        }
        else
        {
            if(path==-1)
            {
            found+=countString(i+1,j,s,input,size,indStr,1);
            found+=countString(i-1,j,s,input,size,indStr,2);
            found+=countString(i,j+1,s,input,size,indStr,3);
            found+=countString(i,j-1,s,input,size,indStr,4);

            found+=countString(i+1,j+1,s,input,size,indStr,5);
            found+=countString(i-1,j-1,s,input,size,indStr,6);
            found+=countString(i-1,j+1,s,input,size,indStr,7);
            found+=countString(i+1,j-1,s,input,size,indStr,8);
            }
            else if(path==1) 
            found+=countString(i+1,j,s,input,size,indStr,1);
            else if(path==2)
            found+=countString(i-1,j,s,input,size,indStr,2);
            else if(path==3)
            found+=countString(i,j+1,s,input,size,indStr,3);

            else if(path==4)
            found+=countString(i,j-1,s,input,size,indStr,4);

            else if(path==5)
            found+=countString(i+1,j+1,s,input,size,indStr,5);

            else if(path==6)
            found+=countString(i-1,j-1,s,input,size,indStr,6);
            else if(path==7)
            found+=countString(i-1,j+1,s,input,size,indStr,7);

            else
            found+=countString(i+1,j-1,s,input,size,indStr,8);

        }
        input[i][j]=temp;        // backtracking 
    }
    return found;
}

int main()
{

    int m,n;
    cin>>m>>n;
    vector<vector<char>>input;
    for(int i=0;i<m;i++)
    {
        vector<char>push;
        for(int j=0;j<n;j++)
        {
            char temp;
            cin>>temp;
            push.push_back(temp);
        }
        input.push_back(push);
    }
    string s;
    cin>>s;
    // vector<vector<int>>v=searchWord(input,s);
    // for(auto i:v)
    // {
    //     for(auto it:i) cout<<it<<" ";
    //     cout<<endl;
    // }

    int size=s.length();
    int ans=0;
    int prevans=0;
    for(int i=0;i<input.size();i++)
    {
        for(int j=0;j<input[0].size();j++)
        {
            ans+=countString(i,j,s,input,size,0,-1);
            if(ans>prevans)
            {
                cout<<i<<' '<<j<<endl;
                prevans=ans;
            }
        }
    }
    return 0;
}


