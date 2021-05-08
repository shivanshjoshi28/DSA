#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define COUNT 2;
typedef struct tree
{
    int data;
    struct tree * left;
    struct tree * right;
    int height;

}Tree;

void printTree(Tree * root,int space)
{
    if(root==NULL) return;
     printTree( root->left,space);
    cout<<root->data<<" ";
     printTree(root->right,space);
    
}

int getheight(Tree * node )
{
    if(node==NULL)
    {
        return 0;
    }
    else
    {
        return node->height;
    }
}
int getorder(Tree * node )
{
    if(node==NULL) return 0;
    return getheight(node->left)- getheight(node->right);
}
Tree * createNode( int data)
{
    Tree * newNode = new Tree;
    newNode->data=data;
    newNode->height=1;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
Tree * rightrotation(Tree * y)
{
    Tree * x= y->left;
    Tree * rightofx= x->right;

    x->right=y;
    y->left=rightofx;

    y->height=max(getheight(y->left),getheight(y->right))+1;
    x->height=max(getheight(x->left),getheight(y))+1;

    return x;
}
Tree * leftrotation(Tree * y)
{
    Tree * x= y->right;
    Tree * leftofx= x->left;

    x->left=y;
    y->right=leftofx;

    y->height=max(getheight(y->left),getheight(y->right))+1;
    x->height=max(getheight(x->right),getheight(y))+1;
    
    return x;
}
void inordergetheight(Tree *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" "<<root->height<<endl;
        inordergetheight(root->left);
        inordergetheight(root->right);
    }
}
Tree * insert(Tree * root, int data,Tree * original)
{
    if( root == NULL)
    {
        cout<<endl<<data<<" Inserted "<<endl;
        return (createNode(data));
    }
    else if( data<root->data)
    {
        root->left= insert(root->left,data,original);
    }
    else if(data>root->data)
    {
        root->right= insert(root->right,data,original);
    }
    else
    {
        return root;
    }

    root->height=1+max(getheight(root->left),getheight(root->right));

    int order=getorder(root);
    if(order>1 and data<root->left->data)  // LL rotation - applying the Right rotation
    {
        cout<<"Before LL Rotation logic applied"<<endl;
        printTree(original,0);
        return rightrotation(root);
    }
    if(order<-1 and data>root->right->data) // RR rotation - applying the Left rotation
    {
        cout<<"Before RR Rotation logic applied"<<endl;
                printTree(original,0);
        return leftrotation(root);

    }
    if( order >1 and data>root->left->data)  // LR rotation - first apply left rotation then right .
    {
        cout<<"Before LR Rotation logic applied"<<endl;
                printTree(original,0);
        root->left=leftrotation(root->left);
        return rightrotation(root);
    }

    if( order <-1 and data<root->right->data)  // RL rotation - first apply left rotation then right .
    {
        cout<<"Before RL Rotation logic applied"<<endl;
                printTree(original,0);
        root->right=rightrotation(root->right);
        return leftrotation(root);
    }
    return root;
}

Tree * getinordersucessor(Tree * root)
{
    Tree * ptr=root;
    while(ptr->left!=NULL)
    {
        ptr=ptr->left;
    }
    return ptr;

}
Tree * deletenode(Tree * root, int data)
{
    if(root==NULL)
    {
        return root;
    }
    else if( data< root->data)
    root->left=deletenode(root->left,data);
    else if(data>root->data)
    root->right=deletenode(root->right,data);
    else // this means root->data= data
    {
        if(root->left==NULL or root->right==NULL)
        {
            Tree * child;
            if(root->left) child= root->left;
            else child= root->right;
            if(child==NULL)
            {
                child=root;
                root=NULL;
            }
            else
            {
                *root=*child;
            }
            delete child;
        }
        else
        {
            Tree * minimum;
            minimum=getinordersucessor(root->right);
            root->data=minimum->data;
            root->right=deletenode(root->right,minimum->data);
        }
    }

    if (root == NULL)  
    return root;  
  
    root->height=1+ max(getheight(root->left),getheight(root->right));
    cout<<"root = "<<root->data<<" height = "<<root->height<<endl;
    int order= getorder(root);
    if(order>1 and getorder(root->left)>=0) // LL rotation
    {
        cout<<"right rotation "<<getorder(root->left)<<endl;
        return rightrotation(root);
    }
    if(order>1 and getorder(root->left)<0) //LR rotation
    {
        cout<<"left and right rotation "<<getorder(root->left)<<endl;
        root->left=leftrotation(root->left);
        return rightrotation(root);
    }
    if( order<-1 and getorder(root->right)<=0)  //RR rotation
    {
        cout<<"Right rotation "<<getorder(root->right)<<endl;
        return leftrotation(root);
    }
    if(order<-1 and getorder(root->right)>0) //RL rotation
    {
        cout<<"Right and left rotation "<<getorder(root->right)<<endl;
        root->right= rightrotation(root->right);
        return leftrotation(root);
    }



    return root;
}
void preOrder(Tree *root)  
{  
    if(root != NULL)  
    {  
        cout << root->data << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  
int main()
{
    Tree * root=NULL;
    char ch;
    // do
    // {
    //     int data;
    //     cout<<"Enter the data you want to insert  in the BST :: ";
    //     cin>>data;
    //     root=insert(root,data,root);
    //     cout<<"Press Y to continue : ";
    //     cin>>ch;
    // } while (ch=='y' or ch=='Y');
    // cout<<"Final AVL Tree is ::"<<endl;
    // printTree(root,0);
    root = insert(root, 20,root);  
    inordergetheight(root);

    root = insert(root, 15,root);  
    inordergetheight(root);

    root = insert(root, 5,root);  
    inordergetheight(root);

    root = insert(root, 40,root);  
    inordergetheight(root);

    root = insert(root, 50,root);  
    inordergetheight(root);

    root = insert(root, 18,root);  
    inordergetheight(root);

    // root = insert(root, -1,root);  
    // root = insert(root, 1,root);  
    // root = insert(root, 2,root);  
    cout<<endl<<" The preorder is :: ";
    preOrder(root);
    cout<<endl;
    inordergetheight(root);
    do
    {
        int data;
        cout<<"Enter the data you want to delete from the BST :: ";
        cin>>data;
        root=deletenode(root,data);
        cout<<root->data<<endl;
        cout<<"Now the content of tree is :: "<<endl;
        // printinorder(root);

        preOrder(root);
        cout<<"Press Y to continue : ";
        cin>>ch;
    } while (ch=='y' or ch=='Y');
    preOrder(root);
    cout<<endl;
    cout<<endl;
    return 0;
}


