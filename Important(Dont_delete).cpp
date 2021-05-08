// #include<bits/stdc++.h>
// #include <iostream>
// using namespace std;
// // void partition(int arr[],int l,int h, int p)
// // {
// //     int temp[h-l+1],index=0;
// //     for(int i=l;i<=h;i++)
// //     {
// //         if(arr[i]<=arr[p])
// //         {
// //             temp[index]=arr[i];
// //             index++;
// //         }
// //     }

// //     for(int i=l;i<=h;i++)
// //     {
// //         if(arr[i]>arr[p])
// //         {
// //             temp[index]=arr[i];
// //             index++;
// //         }
// //     }

// //     for(int i=l;i<=h;i++)
// //         arr[i]=temp[i-l];
// // }

// // int partition_Lomuto(int arr[],int l,int h)
// // {
// //     int pivot = arr[h];  // setting pivot as last element
// //     int index=l;
// //     for(int j=l;j<=h;j++)
// //     {
// //         if(arr[j]<pivot)
// //         {
// //             swap(arr[index],arr[j]);
// //             index++;
// //         }
// //     }
// //     swap(arr[index],arr[h]);
// //     return index;
// // }

// int partition_Hoare(int arr[],int l,int h)
// {
//     int pivot = arr[l];  // setting pivot as fast element
//     int i=l-1,j=h+1;
//     while(true)
//     {
//         do
//         {
//             i++;
//         } while (arr[i]<pivot);
//         do
//         {
//             j--;
//         } while (arr[j]>pivot);

//         if(i>=j) return j;
//         swap(arr[i],arr[j]);
        
//     }
// }


// int main()
// {
//     int sampleinput[8]={5,3,8,4,2,7,1,10};
//     int a=partition_Hoare(sampleinput,0,7);// l=0,h=7
//     for(int it:sampleinput)
//         cout<<it<<" ";
//     return 0;
// }



// #include <iostream>
// #include <cmath>
// #include <vector>
// #include<algorithm>
// #include<climits>
// using namespace std;

// int subset_and_calc(int n)
// {

//     int totalSubset=pow(2,n);
//     vector<int>v;
//     for(int i=1;i<=n;i++)
//         v.push_back(i);
//     vector<int>group1;
//     vector<int>group2;
//     int answer=INT_MAX;
    
//     for(int i=0;i<totalSubset;i++) // loop through all the subset of the array from 1 to n 
//     {
//         vector<int>firstgroup;
//         vector<int>secondgroup;
//         int sum1=0,sum2=0;

//         int counter=0;
//         int j=i;
//         while(j!=0)  // check the counter that is set and keep the track of all those. 
//         {
//             if(j&1==1) 
//             {
//                 firstgroup.push_back(v[counter]);
//                 sum1+=v[counter];
//             }
//             j=j>>1;
//             counter++;
//         }
//         j=(~i);   // complement the counter
//         counter=0;
//         while(j!=0)     // check the complement counter that is set and keep the track of all those. 
//         {
//             if(j&1==1) 
//             {
//                 secondgroup.push_back(v[counter]);
//                 sum2+=v[counter];
//             }
//             j=j>>1;
//             counter++;
//             if(counter==n) break;
//         }
//         if(answer>fabs(sum1-sum2))    //check for minimum absoluter difference and update the answer
//         {
//             answer=fabs(sum1-sum2);
//             group1.assign(firstgroup.begin(),firstgroup.end());
//             group2.assign(secondgroup.begin(),secondgroup.end());

//         }
        
//     }
//     cout<<"First group : ";
//         for(int i:group1) cout<<i<<" ";
//         cout<<endl;
//     cout<<"Second group : ";
//         for(int i:group2) cout<<i<<" ";
//         return answer;
// }

// int main()
// {
//     int n;
//     cin>>n;
//     int diff= subset_and_calc(n);
//     cout<<"\nMinimum absolute difference is : "<<diff;
//     return 0;
// }


// #include <bits/stdc++.h>

// using namespace std;
// int greedydiff(int n)
// {
//     //Setting half sum value
//     int track = (n*(n+1)/2)/2;

//     //Initializing counter variable
//     int sum1 = 0, sum2 = 0;

//     //Maintaining two groups
//     vector<int> group1, group2;

//     //Running loop from n to 1
//     for(int i=n;i>=1;i--){
//         if(track-i>=0){
//             group1.push_back(i);
//             track -= i;
//             sum1 += i;
//         }else{
//             group2.push_back(i);
//             sum2 += i;
//         }
//     }


//     //Printing the elements of the two groups
//     cout<<"First group : \n";
//     for(int i:group1){
//         cout <<i<< " ";
//     }
//     cout << endl;
//     cout<<"Second group : \n";
//     for(int i:group2){
//         cout << i<< " ";
//     }
//     return abs(sum1-sum2);


// }
// int main()
// {
//     int n;
//     cin >> n;
//     int diff= greedydiff(n);
//     cout<<"\nThe minimum absolute difference between two groups is : "<<diff;

    
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     std::vector<int> set{1,10,9};
//     int set_size = set.size();
//     unsigned int pow_set_size = pow(2, set_size);
//     int counter, j;
//     int total = 0;
//     for (int i = 0; i < set_size; i++)
//         total += set[i];

//     for (counter = 0; counter < pow_set_size; counter++)
//     {
//         int sum = 0;
//         int count = 0;
//         cout<<"counter = "<<counter<<endl;
//         for (j = 0; j < set_size; j++)
//         {

//             if (counter & (1 << j))
//             {
//                 cout<<"counter & (1 << j)"<<(counter & (1 << j))<<" ";
//                 sum += set[j];
//                 cout<<"set[j] = "<<set[j]<<endl;
//                 count++;
//             }

//         }
//         cout<<endl;

//         if (sum > (total - sum))
//         {
//             cout<<"sum = "<<sum<<endl;
//             cout << "The smallest subset with sum greater with all other elements is " <<count;
//             break;
//         }
//     }

//     return 0;
// }



// #include<bits/stdc++.h>
// #include <iostream>
// using namespace std;

// int calc(int arr[],int n)
// {
//     int power_set_size= pow(2,n);
//     int total=0;
//     for(int i=0;i<n;i++)
//     {
//         total+=arr[i];
//     }
//     for(int i=0;i<power_set_size;i++)
//     {
//         int j=i;
//         int sum=0;
//         int counter=0;
//         int answer=0;
//         while(j!=0)
//         {
//             if(j&1) 
//             {
//                 sum+=arr[counter];
//                 answer++;
//             }
//             j=j>>1;
//             counter++;
//         }
//         if(sum>(total-sum))
//         {
//             cout<<sum<<endl;
//             return answer;
//         }
//     }
//     return total;
// }
// int main()
// {
//     int arr[4]={6,3,4,9};
//     int s= calc(arr,4);
//     cout<<s;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	vector <int> v {6,3,4,9};
// 	int n = v.size();
// 	int counter = 0;
// 	int total  = 0;
// 	int Sum = 0;
	
// 	for(int i=0;i<n;i++)
// 	    total += v[i];
	    
// 	sort(v.begin(),v.end(),greater<int>()); 
	
// 	for(int i=0;i<n;i++)
// 	{
// 	    if(Sum <= (total - Sum))
// 	    {
// 	        Sum += v[i];
// 	        counter++;
// 	    }
// 	    else
// 	        break;
// 	}
	
// 	cout << "The smallest subset with sum greater with all other elements is :" << counter ;
// 	return 0;
// }



// #include<bits/stdc++.h>
// #include <iostream>
// using namespace std;
// //Time complexity - > O(N)       Space complexity - > O(256)= O(1)
// int calc(string s)
// {
//     int len= s.length();
//     // vector<int>alphaindex(256,-1);   
//     int alphaindex[256];
//     memset(alphaindex,-1,256*sizeof(int));   // this will make full 256 size array as{-1,-1,-1,........,-1(256 times)}
//     int start=0;
//     int result=0;
//     for(int i=0;i<len;i++)
//     {
//         if(alphaindex[s[i]]>=start)
//         {
//             start= alphaindex[s[i]]+1;
//         }
//         result= max(result,i-start+1);
//         cout<<result<<endl;
//         alphaindex[s[i]]=i;
//     }
//     return result;
// }
// int main()
// {
//     string s;
//     cin>>s;
//     int a=calc(s);
//     cout<<a;
//     return 0;
// }


// #include<bits/stdc++.h>
// #include <iostream>
// using namespace std;

// int main()
// {
//     int **arr= new int* [3];  //array of pointers 
//     for(int i=0;i<3;i++)
//     {
//         int n;
//         cin>>n;
//         arr[i]= new int[n];
//         for (size_t j = 0; j < n; j++)
//         {
//             cin>>arr[i][j];
//         }
//         for(int j=0;j<n;j++)
//         {
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }

//     return 0;
// }




// #include <stdio.h>
// #include<string.h>
// int main()
// {
//     char s[100];
//     scanf("%s",s);
  
//     int l=strlen(s);
//     int m=0;
//     int a[26];
//     int count=0;
//     int temp=0;

//     for(int i=0;i<26;i++)
//         a[i]=-1;

//     for(int i=0;i<l;i++)
//     {
//         if(a[s[i]-97]==-1)  // bc yaha dimaage ni lagana .... bkl chutiya kaat diya phle hi
//         {    
//             temp++;
//             a[s[i]-97]=i;
//         }
//         else
//         {
//             m=a[s[i]-97];
//             // printf("a[%d]=%d; %c\n",s[i]-97,m,s[i]);
//             // printf("temp= %d ; count= %d\n",temp,count);
//             // for(int j=0;j<m;j++)
//             //     a[s[j]-97]=-1;

//             if(temp>count)  
//                 count=temp;
            
//             // temp=i-m;
//             if((i-m)>temp) temp=temp;
//             else temp=i-m;


//             a[s[i]-97]=i;
//         }
//         if(temp>count)  
//             count=temp;
//         // printf("%d \n",temp);
//     }
//     printf("%d",count);
//     return 0;
// }


// #include<vector>
// #include<algorithm>
// #include<stack>
// #include <iostream>
// using namespace std;

// vector<int> leftsidefirstsmallest(vector<int>&v)
// {
//     stack<int>s;
//     s.push(0);
//     vector<int>ps;
//     ps.push_back(-1);
//     for(int i=1;i<v.size();i++)
//     {
//         while(s.empty()==false && v[s.top()]>=v[i])
//         s.pop();

//         int ls= (s.empty())?-1:s.top();
//         ps.push_back(ls);
//         s.push(i);
//     }
//     return ps;
// }
// vector<int> rightsidefirstsmallest(vector<int>&v)
// {
//     stack<int>s;
//     s.push(v.size()-1);
//     vector<int>ns;
//     ns.push_back(v.size());
//     for(int i=v.size()-2;i>=0;i--)
//     {
//         while(s.empty()==false && v[s.top()]>=v[i])
//         s.pop();

//         int ls= (s.empty())?v.size():s.top();
//         ns.push_back(ls);
//         s.push(i);
//     }
//     reverse(ns.begin(),ns.end());
//     return ns;
    
// }
// int findarea(vector<int>&v)
// {
//     vector<int>ps=leftsidefirstsmallest(v);
//     vector<int>ns=rightsidefirstsmallest(v);
//     for(int i:ps)  cout<<i<<" ";
//     cout<<endl;
//     for(int i:ns)  cout<<i<<" ";
//     int result=0;

//     for(int i=0;i<v.size();i++)
//     {
//         int curr= v[i];
//         curr+=((i-ps[i]-1)*v[i]);
//         curr+=((ns[i]-i-1)*v[i]);
//         result=max(result,curr);
//     }
//     return result;
// }
// int main()
// {
//     vector<int>v;
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         int temp;
//         cin>>temp;
//         v.push_back(temp);
//     }
//     int area= findarea(v);
//     cout<<endl;
//     cout<<area<<endl;
//     return 0;
// }

// // stack using queue
// #include<queue>
// #include <iostream>
// using namespace std;
// class Stack
// {
//     public :
//     queue<int>q;
//     void display()
//     {
//         queue<int>q1=q;
//         cout<<"\ndisplay q size = ";
//         cout<<q.size()<<endl;
//         while(q1.empty()==false)
//         {
//             cout<<q1.front()<<" ";
//             q1.pop();
//         }
//     }
//     void push(queue<int>&q, int x,int size)
//     {
//         if(size==-1) 
//         {
//             q.push(x);
//             return ;
//         }
//         else
//         {
//             int top= q.front();
//             if(size==0) 
//             {
//                 q.push(x);
//                 return;
//             }
//             q.push(x);
//             q.pop();
//             push(q,top,size-1);
//         }
//     }
// };
// int main()
// {
//     Stack s;
//     // s.q.push(10);
//     // s.q.push(20);
//     // s.q.push(30);
//     s.push(s.q,30,0);
//     s.push(s.q,20,1);
//     s.push(s.q,10,2);
//     s.push(s.q,40,3);
//     s.display();
//     return 0;
// }



//O(n) solution for petrol distance problem . 
// #include<deque>
// #include <iostream>
// using namespace std;
// int calc(int p[],int ds[],int n)
// {
//     deque<int>dq;
//     int start =0;
//     int curr_petrol=0;
//     int breakfound=0;
//     while(true)
//     {
//         while(!dq.empty()&& curr_petrol<0)
//         {
//             curr_petrol=curr_petrol-(p[dq.front()]-ds[dq.front()]);
//             if(dq.front()==n-1) 
//             {
//                 breakfound=1;
//                 break;
//             }
//             dq.pop_front();
//         }
//         if(breakfound) break;
//         curr_petrol+=p[start]-ds[start];
//         dq.push_back(start);
//         if(dq.back()==dq.front() && dq.size()==n+1) return start+1;
//         cout<<"Deque at start = "<<start <<" : ";
//         deque<int>dq1=dq;
//         // below just to debug
//         cout<<"sum = "<<curr_petrol<<" ";
//         while(!dq1.empty()) {
//             cout<<dq1.front()<<" ";
//             dq1.pop_front();
//         }
//         cout<<endl;
//         //above just to debug
//         start=(start+1)%n;
//     }
//     return -1;
// }
// int calcbest(int p[],int ds[],int n)
// {
//     int curr=0,prev=0;
//     int start=0;
//     for(int i=0;i<n;i++)
//     {
//         curr+=(p[i]-ds[i]);
//         if(curr<0)
//         {
//             start=i+1;
//             // prev=prev+curr;
//             //prev=curr;
//             curr=0;
//         }
//         cout<<curr<<endl;
//     }
//     cout<<"prev = "<<prev<<endl;
//     cout<<"curr = "<<curr<<endl;
//     return ((prev+curr)>=0)?(start+1):-1;
// }
// int main()
// {
//     int p[4]={55, 52, 33, 100};
//     int ds[4]={77 ,61 ,40 ,69};
//     // int answer=calc(p,ds,4);
//     int answer=calcbest(p,ds,4);
//     cout<<answer<<endl;
//     return 0;
// }



// #include<bits/stdc++.h>
// #include <iostream>
// using namespace std;

// int josephus(int n,int k)
// {
//     if(n==1) return 0;
//     else return ((josephus(n-1,k)+k)%n);
// }
// int main()
// {
//     int n;
//     cout<<"n= :";
//     cin>>n;
//     int k;
//     cout<<"k= :";
//     cin>>k;
//     int answer= josephus(n,k);
//     cout<<answer<<" is only left alone "<<endl;

//     return 0;
// }

//Tree DS
#include<unordered_map>
#include<stack>
#include <iostream>
#include <climits>
#include<queue>
using namespace std;
typedef struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key=k;
        left=right=NULL;
    }
}Node;
int a=3;
int maximum=INT_MIN;
void getMax(Node *root)  //using the concept of traversal get maximum in the tree
{
    if(root!=NULL)
    {
        maximum=max(maximum,root->key);
        getMax(root->left);
        getMax(root->right);
    }
}
void preorder(Node *root)  // print in preorder
{
    if(root!=NULL)
    {
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void preorderiterative(Node *root)  // print in preorder iteratively
{
    Node *curr = root;
    stack<Node *> st;
    while(curr!=NULL || st.empty()==false)
    {
        // if(curr!=NULL)
        // {
        //     cout<<curr->key<<" ";
        //     st.push(curr);
        // }
        while(curr!=NULL)
        {
            cout<<curr->key<<" ";
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        // cout<<"\npopped "<<curr->key<<endl;
        curr=curr->right;
        // if(curr!=NULL)
        // cout<<" \ncurr at "<<curr->key<<endl;
    }
}
void postorderiterative(Node *root) // print in postorder iteratively
{
    Node *curr=root;
    stack<Node * > st;
    while(st.empty()==false || curr!=NULL)
    {
        while(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }
        Node *temp=st.top()->right;
        if(temp!=NULL)
        {
            curr=temp;
        }
        else
        {
            temp=st.top();
            st.pop();
            cout<<temp->key<<" ";
            while(st.empty()==false && temp==st.top()->right)
            {
                cout<<st.top()->key<<" ";
                temp=st.top();
                st.pop();
            }
        }
    }
}
bool calculate(Node *root)    //Checking whether the tree is balanced or not by the iterative method
{
    if(root ==NULL) return true;
    queue<Node *>q;
    Node *curr=root;
    q.push(curr);
    bool Moveforward= true;
    while(!q.empty())
    {
        int k= q.size();
        for(int i=0;i<k;i++)
        {
            Node *temp=q.front();
            cout<<"checking "<<temp->key<<endl;
            int sum=0;
            bool leftpresent=false;
            bool rightpresent=false;
            
            if(temp->left!=NULL){ q.push(temp->left);sum+=temp->left->key; leftpresent=true;}
            if(temp->right!=NULL){ q.push(temp->right);sum+=temp->right->key;rightpresent=true;}
            cout<<"Sum ="<<sum<<" temp->key = "<<temp->key<<endl;

            if((rightpresent || leftpresent)&& sum==temp->key)   Moveforward=true;
            else if(!rightpresent && !leftpresent) Moveforward=true;
            else Moveforward= false;
            if(Moveforward==false) return Moveforward;
            q.pop();
        }
    }
    return Moveforward;
}

void convert(Node *root, Node **head)   // convert BT To DL implace.
{
    // Base case
    if (root == NULL) return;
 
    // Initialize previously visited node as NULL. This is
    // static so that the same value is accessible in all recursive
    // calls
    static Node* prev = NULL;
 
    // Recursively convert left subtree
    convert(root->left, head);
 
    // Now convert this node
    if (prev == NULL)
        {*head = root;}
    
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    if(head==NULL) cout<<"At root = "<<root->key<<" head =NULL"<<endl;
    else cout<<"At root = "<<root->key<<" head "<<(*head)->key<<endl;
 
    // Finally convert right subtree
    convert(root->right, head);
}
int postIndex=7;
Node * convertBT(int in[],int post[],int si ,int ei)  // convert to BT using inorder and postorder array given 
{
    if(si>ei) return NULL;
    Node * root = new Node(post[postIndex--]);
    int inIndex;
    for(int i=si;i<=ei;i++)
    {
        if(root->key==in[i])
        {
            inIndex=i;
            break;
        }
    }

    root->right= convertBT(in,post,inIndex+1,ei);
    root->left= convertBT(in,post,si,inIndex-1);
    return root;
}
unordered_map<Node *,int>um;
int height(Node * root)    // get the height and also setting map um to NOde and height.
{
    if(root==NULL) return 0;
    else
    {
        int h=1+max(height(root->left),height(root->right));
        um[root]=h;
        return h;
    }
}
int result=0;
int burnTime(Node * root, int leaf,int &dist)   // here dist is the distance of root->data node from leaf node, if it is a descendant.
{
    if(root==NULL) return 0;  
    if(root->key==leaf) // if root is the leaf
    {
        dist=0;
        int a=height(root->left);  // checking left height 
        int b= height(root->right);// checking right height
        result=max(result,max(a,b));   // if any of these two are greater than result than initialize result to maximum. 
        return 1+max(a,b);  // return height ( this will be 1 for leaf node )
    }
    int ldist=-1,rdist=-1;
    int lh= burnTime(root->left,leaf,ldist);
    int rh= burnTime(root->right,leaf,rdist);
    if(ldist!=-1)   // if leaf is in left subtree than ldist>-1 
    {
        dist=ldist+1;
        result=max(result,dist+rh);   // maximum of result or current node distance from leaf + maximum height to the right side ( as leaf is on left subtree )
    }
    else if(rdist!=-1) // if leaf is in right subtree than rdist>-1 
    {
        dist=rdist+1;
        result=max(result,dist+lh);   // maximum of result or current node distance from leaf + maximum height to the lef side ( as leaf is on right subtree )
    }
    return (1+max(lh,rh));    // this is return height that will be maximum height of either left or right subtree +1
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(13);
 
    root->right->left = new Node(14);
    root->right->right = new Node(15);
 
    root->right->left->left = new Node(21);
    root->right->left->right = new Node(22);
    root->right->right->left = new Node(23);
    root->right->right->right = new Node(24);
    // Node *root =new Node(10);
    // root->left= new Node (20);
    // root->right= new Node (30);
    // root->left->left=new Node(40);
    // root->left->right=new Node(50);
    // root->left->left->left=new Node(60);
    // root->left->left->left->left=new Node(70);
    // root->left->right->right=new Node(60);
    // root->left->right->right->left=new Node(80);
    // root->left->right->right->right=new Node(70);
    // getMax(root);
    // cout<<maximum;
    // Node* root = new Node(10);
    // root->left = new Node(20);
    // root->right = new Node(30);
    // root->left->left = new Node(40);
    // root->left->left->left = new Node(70);
    // root->left->right = new Node(50);
    // root->right->left = new Node(60);
    // root->left->left->right = new Node(80);
    // preorder(root);
    // cout<<endl;
    // preorderiterative(root);
    // postorderiterative(root);
    // if(calculate(root) ) cout<<"Yes ";
    // else cout<<"No ";
    // Node *ans= NULL;
    // convert(root,&ans);
    // cout<<ans->key<<" is the answer";
    // int in[8]={4,8,2,5,1,6,3,7};
    // int post[8]={8,4,5,2,6,7,3,1};
    // Node * newroot= convertBT(in,post,0,7);
    // preorder(newroot);
    // height(root);
    // for(auto it:um)
    // {
    //     cout<<it.first->key<<" "<<it.second<<endl;
    // }
    int aa=-1;
    int s=burnTime(root,14,aa);
    cout<<s<<endl;
    cout<<result;

    return 0;
}
// #include<climits>
// #include<deque>
// #include <iostream>
// using namespace std;

// void calculate(int arr[],int n,int k){
//     deque<int>dq;
//     dq.push_back(0);
//     for(int i=1;i<k;i++)
//     {
//         while(!dq.empty() && arr[dq.back()]<=arr[i])
//         {
//             dq.pop_back();  //pop from back till the element before deque is less than arr[i]
//         }
//         dq.push_back(i);
//     }
//     cout<<arr[dq.front()]<<" ";
//     for(int i=k;i<n;i++)
//     {
//         if(dq.front()==i-k)   dq.pop_front();// as it might be the prev element of that window . so remove that 
//         while(dq.empty()==false && arr[dq.back()]<=arr[i])
//         {
//             dq.pop_back();  //pop from back till the element before deque is less than arr[i]
//         }
//         dq.push_back(i);
//         cout<<arr[dq.front()]<<" ";
//     }
// }
// void calc(int arr[],int n,int k)
// {
//     for(int start=0;start<=n-k;start++)
//     {
//         int max_element=INT_MIN; 
//         for(int index=start;index<start+k;index++)
//         {
//             max_element= max(max_element,arr[index]);
//         }
//         cout<<max_element<<" ";
//     }
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     int k;
//     cin>>k;
//     calc(arr,n,k);
//     return 0;
// }
