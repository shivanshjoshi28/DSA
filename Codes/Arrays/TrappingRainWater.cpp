
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

int main()   // O(n) Tc with O(1) space
{
    int arr[6]={4,2,0,3,2,5};
    int n=6;
    int maxl=0;
    int maxr=0;
    int low=0;
    int high=n-1;
    int total=0;
    while(low<high)
    {
        if(arr[low]<arr[high])
        {
            cout<<"First arr[low]="<<arr[low]<<" < arr[high]="<<arr[high]<<endl;
            if(arr[low]>maxl) maxl=arr[low];
            else
            {
                total+=maxl-arr[low];
            }
                low++;
            cout<<"\t total = "<<total<<endl;
        }
        else
        {
            cout<<"Second arr[low]="<<arr[low]<<" > arr[high]="<<arr[high]<<endl;
            if(arr[high]>maxr) maxr=arr[high];
            else
            {
                total+=maxr-arr[high];
            }
                high--;
            cout<<"\t total = "<<total<<endl;

        }

    }
    cout<<total;
    
    return 0;
}

/*

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

    int maxArea(vector<int>& height) {
        vector<int>lmax;
        vector<int>rmax;
        lmax.push_back(height[0]);
        for(int i=1;i<height.size();i++)
        {
            if(height[i]>lmax[i-1]) lmax.push_back(height[i]);
            else lmax.push_back(lmax[i-1]);
        }
        int n= height.size();
        
        rmax.push_back(height[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            if(height[i]>rmax[(n-2)-i]) rmax.push_back(height[i]);
            else rmax.push_back(rmax[(n-2)-i]);
        }
        for(auto it:rmax) cout<<it<<endl;
        reverse(rmax.begin(),rmax.end());
        // vector<int>diff;
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
            // diff.push_back(min(lmax[i],rmax[i]));
            m[min(lmax[i],rmax[i])]++;
        }
        int count=n;
        int ans=INT_MIN;
        for(auto it:m ) cout<<it.first<<" "<<it.second<<endl;
        for(auto it= m.begin();it!=m.end();it++)
        {
            int remaining_above= count-(it->second);
            int area= (it->first) *(remaining_above+(it->second)-1 );
            ans= max(ans,area);
            count-=(it->second);
        }
        return ans;
    }

    int main()
    {
        vector<int>v{4,2,0,3,2,5};
        cout<<maxArea(v);
        return 0;
    }

*/