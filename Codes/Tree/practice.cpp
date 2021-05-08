#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int k)
    {
        data=k;
        left=right=NULL;
    }
}Node;
void inorder(Node *root)
{
    if (root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int change(Node * root)
{

    // if(!root->left && !root->right) return 0;
    if(root==NULL) return 0;
    int L,R,Newl,Newr;

    if(root->left ==NULL ) 
        L=0;
    else
        L= root->left->data;

    if(root->right ==NULL ) 
        R=0;
    else
        R=root->right->data;
    cout<<"At root = "<<root->data<<" L= "<<L<<" R= "<<R<<endl;

    Newl= change(root->left);
    Newr= change(root->right); 
    cout<<"Root = "<<root->data<<" Newl = "<<Newl<<" Newr = "<<Newr<<endl;

    root->data= L+R+Newl+Newr;
    cout<<"Changed root to "<<root->data<<endl;
    return root->data;
}
int ans=INT_MAX;

void KthAncestor(Node *root, int value,int &k,int&move)
{

    if(!root) return;
    if(root->data==value)
    {
        cout<<"Done move = 0 at root = "<<root->data<<endl;
        move=0;
        // k--;
        return;
    }
        if(move)
        KthAncestor(root->left,value,k,move);
        if(move)
        KthAncestor(root->right,value,k,move);
    cout<<"root= "<<root->data<<" move= "<<move<<" k= "<<k<<endl;
    if(move==0)
    k--;
        if(k==0 && move==0)
        {
            ans=root->data;
            cout<<"* "<<root->data<<endl;
            return;
        }
} 

string subtree(Node *root,unordered_map<string ,int> & m)
{
    if(root==NULL) return "$";
    // if(!root->left && !root->right) return to_string(root->data);
    string lside="",rside="";
    lside+= subtree(root->left,m);
    rside+=subtree(root->right,m);
    string orig= to_string(root->data)+lside+rside;
    cout<<orig<<endl;
    m[orig]++;
    return orig;
    
}
bool dupSub(Node *root)
{
     //your code here
     unordered_map<string,int>m;
     m.clear();
     subtree(root,m);
     for(auto it:m)
     {
         cout<<it.first<<" "<<it.second<<endl;
     }
     return true;
}
int movef=0;
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

    if(root==NULL ) return;
    if(root->data>key)
    {
        suc=root;
        findPreSuc(root->left,pre,suc,key);
    }
    else if(root->data==key)
    {
        if(root->left!=NULL)
        {
            Node * curr= root->left->right;
            Node * prev= root->left;
            while(curr)
            {
                prev=curr;
                curr=curr->right;
            }
            pre=prev;
        }
        if(root->right!=NULL)
        {
            Node * curr= root->right->left;
            Node * prev= root->right;
            while(curr)
            {
                prev=curr;
                curr=curr->left;
            }
            suc=prev;
        }
    }
    else
    {
        pre=root;
        findPreSuc(root->right,pre,suc,key);
    }
}

int treesize(Node*root)
{
    if(root==NULL) return 0;
    return 1+treesize(root->left)+treesize(root->right);
}
void Kthsmall(Node *root,int& k,int &ans)
{
    if(root==NULL) return;
    Kthsmall(root->left,k,ans);
    k--;
    cout<<"at root= "<<root->data<<" k= "<<k<<endl;
    if(k==0) {ans= root->data;return;}
    Kthsmall(root->right,k,ans);
}

int kthLargest(Node *root, int K)
{
    //Your code here
    int n= treesize(root);
    cout<<"n= "<<n<<endl;
    int pos= n-K+1;
    cout<<"pos= "<<pos<<endl;
    int ans;
    Kthsmall(root,pos,ans);
    return ans;
}

void findMedian(Node *root, int first,int second,int& count,float &ans)
{
    static Node *prev=NULL;
    if(root==NULL) return;
    findMedian(root->left,first,second,count,ans);
    count++;
    if(count==second)
    {
        if(second!=1)
        {
            if(first==second)
            {
                ans= root->data;
            }
            else
            {
                ans=(prev->data+root->data)/2.0;
            }
        }
        else
        {
            ans= root->data;
        }
    }
    prev=root;
    findMedian(root->right,first,second,count,ans);
}
float median(Node *root)
{
    int n= treesize(root);
    int medianpos1,medianpos2;
    if(n%2==1)
    {
        medianpos1=(n+1)/2;
        medianpos2=(n+1)/2;
    }
    else
    {
        medianpos1=n/2;
        medianpos2=(n/2)+1;
    }
    int count=0;
    float ans;
    findMedian(root,medianpos1,medianpos2,count,ans);
    return ans;
}
void postorder(Node *root)
{
    stack<Node * > s1;
    stack<Node * > s2;
    while(true)
    {
        while(root!=NULL)
        {
            s1.push(root);
            s2.push(root);
            root=root->right;
        }
        if(s1.empty())
        {
            break;
        }
        Node *top= s1.top();
        s1.pop();
        root=top;
        root=root->left;
    }
    while(!s2.empty())
    {
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}
int main()
{
    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(9);
 
    // root->right->left = new Node(2);
    // root->right->left->left = new Node(4);
    // root->right->right = new Node(10);

    root->left->left = new Node(2);
    root->left->right = new Node(5);
    inorder(root);
    cout<<endl;
    // dupSub(root);

    // int ignore= change(root);
    // cout<<endl;
    // inorder(root);
    // int move=1;
    // int k=1;

    // KthAncestor(root,6,k,move);
    // cout<<ans;
    cout<<kthLargest(root,4);
    cout<<endl;
    cout<<median(root);
    cout<<endl;
    postorder(root);
    return 0;
}