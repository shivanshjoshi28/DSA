#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int fact(int f)
{
    if(f==1) return 1;
    else return f*fact(f-1);
}

int calculaterank(string s)
{
    int count[256]={0};
    for (size_t i = 0; i < s.length(); i++)
    {
        count[s[i]]++; 
    }
    for (size_t i = 1; i < 256; i++)   // it will calculate the cummulative freq of each character
    {
        count[i]=count[i]+count[i-1];
    }

    int rank=0;
    int mul=fact(s.length());
    
    

    for(int i=0;i<s.length();i++)
    {
        mul= mul/(s.length()-i);
        rank+=mul*count[s[i]-1];
        for(int j=s[i];j<256;j++)
        {
            count[j]--;
        }
    }
    return rank;
}
int main()
{
    string s;
    cout<<"Enter the string of whom you want to find the lexicographic rank : ";
    cin>>s;
    cout<<calculaterank(s)+1;
    return 0;
}