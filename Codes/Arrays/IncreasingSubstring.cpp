// #include<bits/stdc++.h>
// #include<deque>
// #include <iostream>
// using namespace std;

// void run()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("inp.txt","r",stdin);
//     freopen("out.txt","w",stdout);
// #endif
// }
// void solve(string s, int count)
// {
//     deque<char>dq;
//     cout<<"Case #"<<count<<": ";
//     dq.push_back(s[0]);
//     cout<<dq.size()<<" ";
//     for(int i=1;i<s.length();i++)
//     {
//         char curr=s[i];
//         while(!dq.empty()&& dq.back()>=curr)
//             dq.pop_front();
//         dq.push_back(curr);
//         cout<<dq.size()<<" ";
//     }
// }
// int main()
// {
//     int t;
//     cin>>t;
//     int count=1;
//     while(t--)
//     {
//         int n;
//         cin>>n;
//         string s;
//         cin>>s;
//         solve(s,count);
//     }
//     return 0;
// }


#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void run()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inp.txt","r",stdin);
    // freopen("out.txt","w",stdout);
#endif
}
int result=INT_MIN;
void calculateansvector(vector<int>v,vector<pair<int,pair<int,int>>>&ans)
{
    int count1=0;
    int diff=v[1]-v[0];
    for(int i=1;i<v.size();i++)
    {
        if(v[i]-v[i-1]==diff)
            count1++;
        else
        {
            break;
        }
    }
    ans.push_back({0,{diff,count1+1}});

    int c=0;
    int start=count1+1;
    diff= v[start]-v[start-1];
    int move=0;
    for(int i=start;i<v.size();i++)
    {
        move=1;
        // cout<<"i = "<<i<<endl;
        if(v[i]-v[i-1]==diff)
            c++;
        else
        {
            ans.push_back({start-1,{diff,c+1}});
            c=0;
            start=i;
            // cout<<"\nstart = "<<start<<endl;
            diff=v[start]-v[start-1];
            i=start-1;
        }
    }
    if(move)
        ans.push_back({start-1,{diff,c+1}});

    for(int i=0;i<v.size();i++)
    {
        ans.push_back({i,{0,1}});
    }

}

void solve(vector<int>v,int count)
{
    vector<pair<int,pair<int,int>>>ans;
    calculateansvector(v,ans);
    // for(auto it:ans)
    // {
    //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
    // }
    for(auto it:ans)
    {
        result=max(result,it.second.second);
    }
// cout<<endl;
// cout<<endl;
    for(auto it:ans)
    {
        if(it.first+it.second.second<v.size())
        {
            // cout<<"change v["<<it.first+it.second.second<<"] to "<<(v[it.first]+it.second.first*it.second.second)<<endl;
            int temp=v[it.first+it.second.second];
            v[it.first+it.second.second]=v[it.first]+it.second.first*it.second.second;
            vector<pair<int,pair<int,int>>>ans;
            calculateansvector(v,ans);
                // for(auto it:ans)
                // {
                //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
                // }
            for(auto it:ans)
            {
                result=max(result,it.second.second);
            }
            v[it.first+it.second.second]=temp;



            // cout<<endl;
            // cout<<endl;
        }
        if(it.first-1>=0)
        {

            // cout<<"change v["<<it.first-1<<"] to "<<(v[it.first]-it.second.first)<<endl;
            int temp=v[it.first-1];
            v[it.first-1]=v[it.first]-it.second.first;
            vector<pair<int,pair<int,int>>>ans;
            calculateansvector(v,ans);
                // for(auto it:ans)
                // {
                //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
                // }
            for(auto it:ans)
            {
                result=max(result,it.second.second);
            }
            v[it.first-1]=temp;
            // cout<<endl;
            // cout<<endl;
        }
    }
    cout<<"Case #"<<count<<": "<<result<<endl;
}
int main()
{
    run();
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
        solve(v,count);
        result=INT_MIN;
        count++;
    }
    return 0;
}
// #include <iostream>
// #include<cmath>
// using namespace std;


// void run()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("inp.txt","r",stdin);
//     freopen("out.txt","w",stdout);
// #endif
// }
// bool isprime(long long int n)
// {
//     if(n==0 || n==1) return false;

//     for(int i=2;i<=n/2;i++)
//     {
//         if(n%i==0)
//         {
//             return false;
//         }
//     }
//     return true;
// }
// long long int findprevprime(long long int n)
// {
//     for(int i=n-1;i>=2;i--)
//     {
//         if(isprime(i)) return i;
//     }
// }

// long long int findnextprime(long long int n)
// {
//     for(int i=n+1;i<=1000000000000000000;i++)
//     {
//         if(isprime(i)) return i;
//     }
// }



// int main()
// {
//     run();
//     int t;
//     cin>>t;int count=1;
//     while(t--)
//     {
        
//     long long int num;
//     cin>>num;
//     if(num==6||num==7||num==8)
//     {
//         cout<<"Case #"<<count<<": "<<6<<endl;
//         count++;
//         continue;
//     }
    
//     long long int sqrt1=sqrt(double(num));
//     if(isprime(sqrt1))
//     {
//         long long int prevprime= findprevprime(sqrt1);
//         long long int nextprime= findnextprime(sqrt1);
//         // cout<<prevprime<<" "<<nextprime<<endl;
//         if((nextprime*sqrt1)<=num && (num-(nextprime*sqrt1))<(num-(sqrt1*prevprime)))
//             cout<<"Case #"<<count<<": "<<nextprime*sqrt1<<endl;
//         else
//             cout<<"Case #"<<count<<": "<<sqrt1*prevprime<<endl;
//         // cout<<"Case #"<<count<<": "<<prevprime*sqrt1<<endl;
//     }
//     else
//     {
//         long long int prevprime= findprevprime(sqrt1);
//         long long int prev_prevprime= findprevprime(prevprime);
//         long long int nextprime= findnextprime(sqrt1);
//         // cout<<prevprime<<" "<<prev_prevprime<<" "<<nextprime<<endl;
//         if((nextprime*prevprime)<=num && (num-(nextprime*prevprime))<(num-(prev_prevprime*prevprime)))
//             cout<<"Case #"<<count<<": "<<prevprime*nextprime<<endl;
//         else
//             cout<<"Case #"<<count<<": "<<prevprime*prev_prevprime<<endl;
//     }
//     count++;
//     }
    
//     return 0;
// }