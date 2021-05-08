// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

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
bool complete(map<char,int>pm,map<char,int>sm)
{
    int good=0;
    for(auto it:pm)
    {
        int count=it.second;
        char character=it.first;
        auto it1= sm.find(character);
        if(it1!=sm.end() && count<=(*it1).second)
        {
            good++;
        }
        else
        {
            return false;
        }
    }
    return true;
}
void smallestwindow(string s,string p)
{
    map<char,int>pm;
    for(int i=0;i<p.length();i++) pm[p[i]]++;
        //     cout<<"pm"<<endl;
        // for(auto it:pm)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
    map<char,int>sm;
    int i;
    for(i=0;i<s.length();i++)
    {
        if(pm.find(s[i])!=pm.end()){ sm[s[i]]++;
        break;}
    }
    int start=i;
    int end=i+1;
    int count=1;
    int min=INT_MAX;
    int firstpos=0;
    int lastpos=0;
        //     cout<<"pm"<<endl;
        // for(auto it:pm)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        // cout<<"sm"<<endl;
        // for(auto it:sm)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        // cout<<"Hello\n\n\n";
    while(start<end && end<s.length())
    {
        // cout<<start<<" "<<end<<endl;
        if(!complete(pm,sm))
        {
            sm[s[end]]++;
            end++;
        }
        // cout<<"pm"<<endl;
        // for(auto it:pm)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        // cout<<"sm"<<endl;
        // for(auto it:sm)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        if(complete(pm,sm))
        {
            if(end-start<min)
            {
                min=end-start;
                firstpos=start;
                lastpos=end-1;
            }
            sm[s[start]]--;
            start++;
        }
    }
        // cout<<start<<" "<<end<<endl;

        // cout<<firstpos<<" "<<lastpos<<endl;
        while(complete(pm,sm))
        {
            if(end-start<min)
            {
                min=end-start;
                firstpos=start;
                lastpos=end-1;
            }
            sm[s[start]]--;
            start++;
        }
        if(firstpos==0 && lastpos==0) {cout<<-1; return;}

        for(int i=firstpos;i<=lastpos;i++)
        {
            cout<<s[i];
        }
}

string hashedfun(string s,string p)
{

    int n1=s.length();
    int n2=p.length();
    if(n1<n2) return "-1";
    int hashs[256]={0};
    int hashp[256]={0};
    for(int i=0;i<n2;i++)
    {
        hashp[p[i]]++;
    }

    int start=0,end=1;
    int startindex=-1;
    int count=0;
    int min=INT_MAX;
    hashs[s[start]]++;
    if(hashs[s[start]]<=hashp[s[start]]) count++;
    while(start<end && end<s.length())
    {
        // cout<<start<<" "<<end<<endl;
        hashs[s[end]]++;
        if(hashs[s[end]]<=hashp[s[end]]) count++;
        // cout<<count<<endl;

        if(count==n2)
        {
            // cout<<"Got inside here "<<endl;
            while(hashs[s[start]]>hashp[s[start]] || hashp[s[start]]==0)
            {
                // cout<<hashs[s[start]]<<hashp[s[start]]<<endl;
                if(hashs[s[start]]>hashp[s[start]])
                {
                    hashs[s[start]]--;
                }
                start++;
            }

            if(end-start+1<min)
            {
                min=end-start+1;
                startindex=start;
            }
        }
        end++;
    }
    if(startindex==-1) return "-1";
    else return s.substr(startindex,min);
}
int main()
{
    string s="timetopractice";
    string p="toc";
    smallestwindow(s,p);
    cout<<endl;
    cout<<hashedfun(s,p);    // efficient method 
    return 0;
}
