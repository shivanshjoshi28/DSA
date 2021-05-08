#include<bits/stdc++.h>
#include <iostream>
using namespace std;


typedef struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *next;
    Node(int k)
    {
        data=k;
        left=right=next=NULL;
    }
}Node;

void inorder(Node *root)
{
    if (root==NULL) return;
    inorder(root->left);
    if(root->next!=NULL) cout<<" * "<<root->next->data<<endl;
    cout<<" "<<root->data<<" ";
    inorder(root->right);
}
Node *head=NULL;
void populateNext(Node* root)
{
    if(root==NULL) return;
    static Node *prev=NULL;
    populateNext(root->left);
    if(prev)
    {
        prev->next=root;
    }
    else
    {
        head=root;
    }
    prev=root;
    populateNext(root->right);
}
void displayLL(Node *root)
{
    while(root)
    {
        cout<<root->data<<" ";
        root=root->next;
    }
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(0);
    root->right = new Node(3);
 
    root->right->left = new Node(2);
    root->right->right = new Node(4);

    root->left->left = new Node(-4);
    inorder(root);
    cout<<endl;
    populateNext(root);
    Node *curr=root;
    while(curr->right!=NULL)
    {
        curr=curr->right;
    }
    curr->next=NULL;
    cout<<endl;
    displayLL(head);
    return 0;
}