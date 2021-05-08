// Author : Shivansh Joshi
// BST basics
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node * left;
    Node *right;
    Node (int k)
    {
        key=k;
        left=right=NULL;
    }
};

Node * insert(Node * root,int x)   // insert recursively
{
    if(root==NULL) return new Node(x);
    if(x<root->key)
    root->left= insert(root->left,x);
    else
    root->right= insert(root->right,x);
    return root;
}
Node * insertiterative(Node *root,int x)   // insert iteratively
{
    Node * parent=NULL;
    Node * temp =new Node(x);
    Node *curr=root;

    while(curr!=NULL)
    {
        parent =root;
        if(x<curr->key)
            curr=curr->left;
        else if(x>curr->key)
            curr=curr->right;
        else
            return root;  // x already present 
    }
    if(parent==NULL) return temp;
    else if(x<parent->key) parent->left= temp;
    else parent->right=temp;
    return root;
}

int getInorderSuccesor(Node *root)
{
    // in this function only we are deleting the inorder succesor
    Node* move=root->right;
    Node * prev =NULL;
    while(move!=NULL && move->left!=NULL)
    {
        prev=move;
        move=move->left;
    }
    int answer= move->key;
    if(move== root->right) {root->right=NULL; delete move;}
    else { prev->left= NULL; delete move;}
    return answer;
}

Node *deleteNode(Node *root,int x)
{
    if(root==NULL) return root;

    if(x<root->key) 
        root->left= deleteNode(root->left,x);
    else if(x>root->key)
        root->right= deleteNode(root->right,x);
    
    else
    {
        if(root->left==NULL) // has no subtree of has right subtree
        {
            Node *temp= root->right; 
            delete root;
            return temp;
        }
        else if(root->right==NULL)  // has only left subtree;
        {
            Node *temp= root->left;
            delete root;
            return temp; 
        }
        else // has both the subtree
        {
            int succ= getInorderSuccesor(root);
            root->key=succ;
            // root->right = deleteNode(root->right,succ->key);
        }
    }

    return root;
}


Node * Succesor(Node *root)
{
    root=root->right;
    while(root!=NULL && root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

Node *deleteNode2method(Node *root,int x)
{
    if(root==NULL) return root;

    if(x<root->key) 
        root->left= deleteNode2method(root->left,x);
    else if(x>root->key)
        root->right= deleteNode2method(root->right,x);
    
    else
    {
        if(root->left==NULL) // has no subtree of has right subtree
        {
            Node *temp= root->right; 
            delete root;
            return temp;
        }
        else if(root->right==NULL)  // has only left subtree;
        {
            Node *temp= root->left;
            delete root;
            return temp; 
        }
        else // has both the subtree
        {
            Node * succ= Succesor(root);
            root->key=succ->key;
            root->right = deleteNode2method(root->right,succ->key);   //delete that inorder successor node 
        }
    }

    return root;
}


void inorder(Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

int main()
{
    Node * root =NULL;
    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,70);
    root=insert(root,10);
    root=insert(root,40);
    root=insert(root,60);
    root=insert(root,80);
    inorder(root);
    cout<<endl;
    root=deleteNode2method(root,50);
    inorder(root);
    return 0;
}