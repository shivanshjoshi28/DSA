
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define COUNT 2
struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};
struct Node * createNode(int data)
{
    struct Node * newnode= new Node;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->data=data;
    return newnode;
}

void printinorder(struct Node * root)
{
    if(root==NULL) return;
     printinorder( root->left);
    cout<<root->data<<" ";
     printinorder(root->right);
    
}

// struct Node * insert(struct Node * root, int data)
// {
//     if( root == NULL)
//     {
//         root=createNode(data);
//         return root;
//     }
//     else
//     {
//         struct Node * newnode= createNode(data);
//         Node * parent = root;
//         Node * curr=root;
//         while(curr!=NULL)
//         {
//             parent= curr;
//             if(data== curr->data) return root;
//             else if(data<curr->data) curr=curr->left;
//             else curr=curr->right;
//         }
//         if(data< parent->data) parent->left=newnode;
//         else parent->right=newnode;
//         return root;
//     }
    
// }

void findposition(struct Node * root,int data, struct Node ** p, struct Node **par)
{
    if(root==NULL)
    {
        *p=NULL;
        *par=NULL;

    }
    else if( root->data==data)
    {
        *p=root;
        *par=NULL;
    }
    else
    {
        struct Node * ptr=root;
        if(data<ptr->data) {*par= ptr; ptr= ptr->left;*p= ptr;}
        else {*par= ptr; ptr= ptr->right;*p= ptr;};
        while(ptr!=NULL)
        {
            if(data==ptr->data)
            {
                // cout<<"Breaked"<<endl;
                break;
            }
            *par= ptr;
            if(data<ptr->data) ptr=ptr->left;
            else ptr=ptr->right;
            *p=ptr;
        }
    }
    
}
struct Node * insert( struct Node * root, int data)
{
    struct Node * p=NULL;
    struct Node * par=NULL;
    findposition(root,data, &p, &par);
    if(p==NULL & par==NULL)
    {
        root=createNode(data);
        return root;
    }
    else if(par==NULL & p!=NULL)
    {
        if(root->data==data) cout<<"Already inserted"<<endl;
        return root;
    }
    else
    { 
        if(par!=NULL and p!=NULL and  p->data == data)
        {
            cout<<"Already inserted "<<endl;
            return root;
        }
        else
        {
            if(data<par->data) par->left=createNode(data);
            else par->right=createNode(data);
            return root;
        }
    }
    
}

void removeonechild(struct Node ** root,int data, struct Node * p, struct Node * par)
{
    struct Node * child=NULL;
    if(p->left==NULL and p->right==NULL) child=NULL;
    else if(p->left!=NULL and p->right==NULL) child=p->left;
    else child=p->right;
    if(par!=NULL)
    {
        if(p==par->left) par->left=child;
        else par->right=child;
    }
    else
    {
        *root=child;
    }
    cout<<"Deleted "<<p->data<<endl;

    // delete p;
}
void removewithtwochild(struct Node **root,int data, struct Node * p, struct Node * par)
{
    struct Node *ptr= p->right;
    struct Node *parentinordersuc= p;
    struct Node *inordersuc= p->right;

    while(ptr->left!=NULL)
    {
        parentinordersuc=ptr;
        ptr=ptr->left;
        inordersuc=ptr;
    }
    removeonechild(root,data,inordersuc,parentinordersuc);
    if(par!=NULL)
    {
        if(p==par->left) par->left=inordersuc;
        else par->right=inordersuc;
    }
    else
    {
        *root=inordersuc;
        cout<<inordersuc->data<<endl;
    }
    inordersuc->left=p->left;
    inordersuc->right=p->right;
    cout<<" Delelted "<<p->data<<endl;
    delete p;
}
void removenode(struct Node ** root, int data )
{
    struct Node * p=NULL;
    struct Node * par=NULL;
    findposition(*root,data, &p, &par);
    if(p==NULL)
    {
        if(par==NULL) cout<<"Tree is empty"<<endl;
        else cout<<data<<" not present in BST"<<endl;
    }
    else
    {
        if(p->left!=NULL and p->right!=NULL)
        {
            removewithtwochild(root,data,p,par);
        }
        else
        {
            removeonechild(root,data,p,par);
        }
        
        
    }
 
}

void printTree(Node *root, int space){
   if (root == NULL)
      return;
   space += COUNT;
   printTree(root->right, space);
   for (int i = COUNT; i < space; i++)
      cout<<"\t";
   cout<<root->data<<"\n";
   printTree(root->left, space);
}

int main()
{
    struct Node * root=NULL;
    char ch;
    do
    {
        int data;
        cout<<"Enter the data you want to insert  in the BST :: ";
        cin>>data;
        root=insert(root,data);
        cout<<"Press Y to continue : ";
        cin>>ch;
    } while (ch=='y' or ch=='Y');
    // printinorder(root);
    printTree(root,0);
    cout<<endl;

    do
    {
        int data;
        cout<<"Enter the data you want to delete from the BST :: ";
        cin>>data;
        removenode(&root,data);
        cout<<"Now the content of tree is :: "<<endl;
        // printinorder(root);
        printTree(root,0);
        cout<<"Press Y to continue : ";
        cin>>ch;
    } while (ch=='y' or ch=='Y');
    // printinorder(root);
    printTree(root,0);
    cout<<endl;

    return 0;
}