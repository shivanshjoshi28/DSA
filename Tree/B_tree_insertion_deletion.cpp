#include<bits/stdc++.h>
#include <iostream>
using namespace std;
class BtreeNode
{
    private:
        int *k;
        BtreeNode **child;
        int n;
        int t;   //it is the min no. of key
        bool leaf;
    public:
        BtreeNode(int _t, bool leaff );
        void traverse();
        BtreeNode * search(int key);
        void insertNonFull(int key);
        void splitChild(int i,BtreeNode * y);

    friend class BTree;
};

class BTree
{
    private:
        int t;
        BtreeNode * root;
    public:
        BTree(int _t)
        {
            t=_t;
            root=NULL;
        }
        void traverse()
        {
            if(root!=NULL) root->traverse();
        }
        BtreeNode * search(int k)
        {
            if(root!=NULL)
            {
                return root->search(k);
            }
            else
            {
                return NULL;
            }
            
        }
        void insert(int key);

    

};
BtreeNode::BtreeNode(int _t,bool leaff)
{

    t=_t;
    leaf=leaff;
    n=0;
    k=new int[2*t-1];
    child= new BtreeNode * [2*t];
}
void BTree::insert(int key)
{
    if(!root)
    {
        root=new BtreeNode(t,true);
        root->k[0]=key;
        root->n=1;
    }
    else
    {
        if(root->n==2*t-1)
        {
            BtreeNode * s= new BtreeNode(t,false);
            s->child[0]=root;
            s->splitChild(0,root);
            int i=0;
            if(key>s->k[0])
            {
                i++;
            }
            s->child[i]->insertNonFull(key);
            root=s;

        }
        else
        {
            root->insertNonFull(key);
        }
        
    }
}
void BtreeNode::insertNonFull(int key)
{
    int i=n-1;
    if(leaf==true)
    {
        while(i>=0 and k[i]>key)
        {
            k[i+1]=k[i];
            i--;
        }
        k[i+1]=key;
        n++;
    }
    else
    {
        while(i>=0 and k[i]>key)
        {
            i--;
        }
        if(child[i+1]->n==(2*t-1))
        {
            splitChild(i+1,child[i+1]);
            if(key>k[i+1]) i++;
        }

        child[i+1]->insertNonFull(key);
    }
}
void BtreeNode::splitChild(int j,BtreeNode * y)
{
    BtreeNode * z= new BtreeNode(y->t, y->leaf);
    z->n=t-1;
    for(int i=0;i<t-1;i++)
    {
        z->k[i]=y->k[i+t];
    }
    if(y->leaf==false)
    {
        for(int i=0;i<t;i++)
        {
            z->child[i]=y->child[i+t];
        }
    }
    y->n=t-1;
    int i;

    for(i=n;i>=j+1;i--)
    {
        child[i+1]=child[i];
    }
    child[i+1]=z;
    for(int i =n ;i>=j;i--)
    {
        k[i]=k[i-1];
    }
    k[i]=y->k[t-1];

    n=n+1;
}
// Function to traverse all nodes in a subtree rooted with this node 
void BtreeNode::traverse() 
{ 
    // There are n keys and n+1 children, traverse through n keys 
    // and first n children 
    int i; 
    for (i = 0; i < n; i++) 
    { 
        // If this is not leaf, then before printing key[i], 
        // traverse the subtree rooted with child C[i]. 
        if (leaf == false) 
            child[i]->traverse(); 
        cout << " " << k[i]; 
    } 
  
    // Print the subtree rooted with last child 
    if (leaf == false) 
        child[i]->traverse(); 
} 
  
// Function to search key k in subtree rooted with this node 
BtreeNode *BtreeNode::search(int key) 
{ 
    // Find the first key greater than or equal to k 
    int i = 0; 
    while (i < n && key > k[i]) 
        i++; 
  
    // If the found key is equal to k, return this node 
    if (k[i] == key) 
        return this; 
  
    // If key is not found here and this is a leaf node 
    if (leaf == true) 
        return NULL; 
  
    // Go to the appropriate child 
    return child[i]->search(key); 
} 
int main()
{
    BTree t(3); // B tree with order 6
    t.insert(10); 
    t.insert(20); 
    t.insert(5); 
    t.insert(6); 
    t.insert(12); 
    t.insert(30); 
    t.insert(7); 
    t.insert(17); 
  
    cout << "Traversal of the constucted tree is "; 
    t.traverse(); 
  
    int k = 6; 
    (t.search(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present"; 
  
    k = 15; 
    (t.search(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present"; 
  
    return 0;
}