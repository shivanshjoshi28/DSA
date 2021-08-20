// #include<bits/stdc++.h>
// #include <iostream>
// using namespace std;

// #include<vector>
// typedef pair<int, int> pii;
// typedef vector<int> vi;
// #define pb push_back
// #define MP make_pair
// #define endl "\n"
// #define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
// #define F first
// #define S second
// const int inf =(int) 1e18;
// const int ninf = (int)-1e17;
// #define rep(a, b) for (int a = 0; a < b; a++)
// #define per(a, b) for (int a = b - 1; a >= 0; a--)
// #define FOR(it, start, end) for (auto it = start; it != end; it++)

// void WordBreak(int pos,string ans,string curr,string str,unordered_set<string>um)
// {
//     if(pos==str.length()-1)
//     {
//         curr+=str[pos];
//         if(um.find(curr)!=um.end())
//         {
//             ans+=curr;
//             curr="";
//         cout<<ans<<endl;
//         }
//         return;
//     }
//     curr+=str[pos];
//     if(um.find(curr)!=um.end())
//     {
//         string temp=curr;
//         string anstemp=ans;
//         ans+=curr;
//         ans+=" ";
//         curr="";
//         WordBreak(pos+1,ans,curr,str,um);
//         curr=temp;
//         ans=anstemp;
//         WordBreak(pos+1,ans,curr,str,um);
//     }
//     else
//     {
//         WordBreak(pos+1,ans,curr,str,um);
//     }
// }

// int main()
// {
//     boost;
//     string str="catsandog";
//     int n=5;
//     unordered_set<string>um;
//     um.insert("cats");
//     um.insert("cat");
//     um.insert("and");
//     um.insert("sand");
//     um.insert("dog");
//     string ans="";
//     string curr="";
//     WordBreak(0,ans,curr,str,um);
    
//     return 0;
// }





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

void WordWrap(string str,int l,unordered_set<string>um,string res)
{
    for(int i=1;i<=l;i++)
    {
        string temp=str.substr(0,i);
        if(um.find(temp)!=um.end()) // it is present in set
        {
            if(i==l)
            {
                res+=temp;
                cout<<res<<endl;
            }
            WordWrap(str.substr(i,l-i),l-i,um,res+temp+" ");
        }
    }
}

int main()
{
    boost;
    string str="catsanddog";
    int n=5;
    unordered_set<string>um;
    um.insert("cats");
    um.insert("cat");
    um.insert("and");
    um.insert("sand");
    um.insert("dog");
    WordWrap(str,str.length(),um,"");
    return 0;
}