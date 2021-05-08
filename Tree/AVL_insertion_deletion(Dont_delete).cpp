// Author : Shivansh Joshi
// AVL Basics
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
    int key;
    Node * left;
    Node *right;
    int height;
    Node(int k)
    {
        key=k;
        left=right=NULL;
        height=1;
    }
};

void preorder(Node *root)
{
    if(root!=NULL)
    {
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int getHeight(Node * root)
{
    if(root ==NULL) return 0;
    return root->height;
}

int getBalanceFactor(Node *root)
{
    if(root==NULL) return 0;
    else 
        return (getHeight(root->left) - getHeight(root->right));
}

Node * rightRotation(Node *root)
{
    Node * left_of_root = root->left;
    Node *right_of_left = left_of_root->right;
    left_of_root->right= root;
    root->left= right_of_left;

    root->height =1+max(getHeight(root->left),getHeight(root->right));
    left_of_root->height =1+max(getHeight(left_of_root->left),getHeight(left_of_root->right));
    return left_of_root;
}

Node *leftRotation(Node *root)
{
    Node *right_of_root= root->right;
    Node *left_of_right = right_of_root->left;
    right_of_root->left=root;
    root->right= left_of_right;

    root->height= 1+max(getHeight(root->left),getHeight(root->right));   // keep this is mind to change the height of root first , as it is not below parent
    right_of_root->height= 1+max(getHeight(right_of_root->left),getHeight(right_of_root->right));
    return right_of_root;
}

Node * insert(Node * root,int x) 
{
    if(root==NULL) return new Node(x);
    if(x<root->key)
        root->left= insert(root->left,x);
    else if(x>root->key)
        root->right= insert(root->right,x);
    else    // if element to be inserted is already there 
        return root;
    



    /*  This is starting of the extra code that is added to Simple non balanced BST */
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    int BalanceFactor= getBalanceFactor(root);
    if(BalanceFactor>1 && x<root->left->key)  // left side height is more because BalanceFactor is greater than 1    --- Case 1 LEFT LEFT as x<root->left
    {
        return rightRotation(root);
    }
    if(BalanceFactor<-1 && x>root->right->key) // right side height is more because BalanceFactor is less than -1     --- Case 2 RIGHT RIGHT as x>root->right
    {
        return leftRotation(root);
    }
    if(BalanceFactor>1 && x>root->left->key)   // left side height is more because BalanceFactor is greater than 1    --- Case 3 LEFT RIGHT as x>root->left
    {
        root->left=leftRotation(root->left);
        return rightRotation(root);
    }
    if(BalanceFactor<-1 && x<root->right->key)   // right side height is more because BalanceFactor is less than -1    --- Case 4 RIGHT LEFT as x<root->right
    {
        root->right= rightRotation(root->right);
        return leftRotation(root);
    }
    /*End of extra code added */

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



    /*  This is starting of the extra code that is added to Simple non balanced BST */
    root->height=1+ max(getHeight(root->left),getHeight(root->right));
    int BalanceFactor= getBalanceFactor(root);
    if(BalanceFactor>1 and getBalanceFactor(root->left)>=0) // LL rotation
    {
        return rightRotation(root);
    }
    if(BalanceFactor>1 and getBalanceFactor(root->left)<0) //LR rotation
    {
        root->left=leftRotation(root->left);
        return rightRotation(root);
    }
    if( BalanceFactor<-1 and getBalanceFactor(root->right)<=0)  //RR rotation
    {
        return leftRotation(root);
    }
    if(BalanceFactor<-1 and getBalanceFactor(root->right)>0) //RL rotation
    {
        root->right= rightRotation(root->right);
        return leftRotation(root);
    }
    /*End of extra code added */


    return root;
}

int main()
{
    Node * root =NULL;
    root = insert(root, 9); 
    root = insert(root, 5); 
    root = insert(root, 10); 
    root = insert(root, 0); 
    root = insert(root, 6); 
    root = insert(root, 11); 
    root = insert(root, -1); 
    root = insert(root, 1); 
    root = insert(root, 2); 
  
    cout<<endl;
    preorder(root);
    cout<<endl;
    root=deleteNode2method(root,10);
    preorder(root);
    cout<<endl;
    root=deleteNode2method(root,9);
    preorder(root);
    return 0;
}