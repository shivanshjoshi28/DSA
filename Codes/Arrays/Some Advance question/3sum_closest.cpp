// // // https://leetcode.com/problems/3sum-closest/
// // #include<bits/stdc++.h>
// // #include <iostream>
// // using namespace std;

// // void run()
// // {
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(NULL);
// // #ifndef ONLINE_JUDGE
// //     freopen("inp.txt","r",stdin);
// //     freopen("out.txt","w",stdout);
// // #endif
// // }

// // int main()
// // {
// //     vector<int>v{0,2,1,-3};
// //     int n=4;
// //     int target =-5;
// //     int start=0;
// //     sort(v.begin(),v.end());
// //     int end=v.size()-1;
// //     int absdiff=abs( v[0]+v[1]-target);
// //     int answer= v[0]+v[1];
// //     while(start<end)
// //     {
// //         if(v[start]+v[end]==target)
// //         {
// //             cout<<"BIngo"<<endl;
// //             cout<<target<<endl;
// //             return 0;
// //         }
// //         else if(v[start]+v[end]>target)
// //         {
// //             int j=end;
// //             while(start<j && v[start]+v[j]>target)
// //             {
// //                 if(abs(v[start]+v[j]-target)<absdiff)
// //                 {
// //                     cout<<answer<<endl;

// //                     absdiff=abs(v[start]+v[j]-target);
// //                     answer= v[start]+v[j];
// //                 }
// //                 j--;
// //             }
// //             if(j!=-1 && v[start]+v[j]<target)
// //             {
// //                 if(abs(v[start]+v[j]-target)<absdiff)
// //                 {
// //                     cout<<answer<<endl;

// //                     absdiff=abs(v[start]+v[j]-target);
// //                     answer= v[start]+v[j];
// //                 }
// //             }
// //             end--;
// //         }
// //         else
// //         {
// //             int j=start;
// //             while(j<end && v[end]+v[j]<target)
// //             {
// //                 if(abs(v[end]+v[j]-target)<absdiff)
// //                 {
// //                     cout<<answer<<endl;
// //                     absdiff=abs(v[end]+v[j]-target);
// //                     answer= v[end]+v[j];
// //                 }
// //                 j++;
// //             }

// //             if(j!=n && v[j]+v[end]>target)
// //             {
// //                 if(abs(v[end]+v[j]-target)<absdiff)
// //                 {
// //                     cout<<answer<<endl;
// //                     absdiff=abs(v[end]+v[j]-target);
// //                     answer= v[end]+v[j];
// //                 }
// //             }
// //             start++;
// //         }
// //     }
// //     cout<<answer<<endl;
// //     return 0;
// // }   
// #include<bits/stdc++.h>
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

// vector<pair<int,int>> searchremaining(vector<int> nums, int start,int target)
//     {
//         int s= start;
//         int e= nums.size()-1;
//         vector<pair<int,int>>v;
//         while(s<e)
//         {
//             cout<<s<<" "<<e<<endl;
//             if(nums[s]+nums[e]==target)
//             {
//                 v.push_back({nums[s],nums[e]});
//                 s++;
//                 e--;
//             }
//             else if(nums[s]+nums[e]>target)
//             {
//                 e--;
//             }
//             else s++;
//         }
//         return v;
//     }
    
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         vector<vector<int>>v;
//         set<pair<int,pair<int,pair<int,int>>>>s;
//         if(n<4) return v;
//         for(int i=0;i<=n-4;i++)
//         {
//             if(i>0 && nums[i]==nums[i-1]) continue;
//             cout<<i<<endl;
//             int threepartner = target - nums[i];
//             for(int j=i+1;j<=n-3;j++)
//             {
//                 if(j>i+1 && nums[j]==nums[j-1]) continue;
//                 cout<<j<<endl;
//                 int twopartner =threepartner-nums[j];
//                 vector<pair<int,int>> coming = searchremaining(nums,j+1,twopartner);
//                 if(coming.size()!=0)
//                 {
//                     for(auto it:coming)
//                         s.insert({nums[i],{nums[j],{it.first,it.second}}});
//                 }
//             }
//         }
//         for(auto it:s)
//         {
//             int a=it.first;
//             int b= it.second.first;
//             int c= it.second.second.first;
//             int d= it.second.second.second;
//             vector<int>vr;
//             vr.push_back(a);
//             vr.push_back(b);
//             vr.push_back(c);
//             vr.push_back(d);
//             v.push_back(vr);
//         }
//         return v;
    
//     }

    
// int main()
// {
//     vector<int>v{2,2,2,2,2};
//     int target=8;
//     vector<vector<int>> ans=fourSum(v,target);
//     for(auto it:ans)
//     {
//         for(auto it1:it) cout<<it1<<" ";
//         cout<<endl;
//     }
//     return 0;
// }




// // #include<bits/stdc++.h>
// #include<vector>
// #include<algorithm>
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

// int main()
// {
//     vector<int>v{1,3,2};
//     vector<int>vcopy=v;
//     sort(v.begin(),v.end());
//     reverse(vcopy.begin(),vcopy.end());
//     int count=0;
//     for(int i=0;i<v.size();i++)
//     {
//         if(v[i]==vcopy[i]) count++;
//     }
//     reverse(vcopy.begin(),vcopy.end());
//     if(count!=v.size())
//     {
//         while(1)
//         {
//                 count=0;
//                 for(int i=0;i<v.size();i++)
//                 {
//                     if(v[i]==vcopy[i]) count++;
//                 }
//                 cout<<"* count "<<count<<endl;
//         for(auto i:vcopy) cout<<i<<" ";
//         cout<<endl;
//                 if(count==v.size()) break;
//                 next_permutation(vcopy.begin(),vcopy.end());

//         }
//         next_permutation(vcopy.begin(),vcopy.end());

//         for(int i=0;i<v.size();i++)
//         {
//             v[i]=vcopy[i];
//         }
//     }
//     for(auto i:v) cout<<i<<endl;

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
    freopen("out.txt","w",stdout);
#endif
}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v{-1,-1};
        int start= 0,end=nums.size()-1;
        while(start<=end)
        {
            // cout<<start<<" "<<end<<endl;
            int mid= start+(end-start)/2;
            if(nums[mid]==target)
            {
                if(mid==0 || nums[mid]!=nums[mid-1])
                {
                    v[0]=mid;
                    break;
                }
                else end=mid-1;
            }
            else if(target>nums[mid]) start=mid+1;
            else end =mid-1;
        }
        
        
        start= 0,end=nums.size()-1;
        while(start<=end)
        {
            int mid= start+(end-start)/2;
            if(nums[mid]==target)
            {
                cout<<mid<<endl;
                if(mid==nums.size()-1 || nums[mid]!=nums[mid+1])
                {
                    v[1]=mid;
                    break;
                }
                else start=mid+1;
            }
            else if(target>nums[mid]) start=mid+1;
            else end =mid-1;
        }
        return v;
    }

int main()
{
    vector<int>v{2,2};
    int target=2;
    vector<int>ans=searchRange(v,target);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}