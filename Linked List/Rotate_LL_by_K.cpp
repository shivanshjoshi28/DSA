#include<bits/stdc++.h>
#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node * next;
} Node;

Node * push(Node * head, int data)
{
    Node * newnode= new Node;
    newnode->data=data;
    if( head==NULL) return newnode;
    else
    {
        newnode->next=head;
        head=newnode;
        return head;
    }
    

}
void printList(Node * Head1)
{
    Node * Head=Head1;
    while(Head!=NULL)
    {
        cout<<Head->data<<" ";
        Head=Head->next;
    }
    cout<<endl;

}
Node * rotate(Node * root, int k)
{
    int count=0;
    Node * ptr= root;
    while(count!=k-1)
    {
        count++;
        ptr=ptr->next;
    }
    Node * last= ptr;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=root;
    root= ptr->next;
    ptr->next=NULL;
    return root;

}
int main()
{
    Node * Head= NULL;
    for(int i=60;i>=10;i-=10)
    {
        Head=push(Head,i);
    }
    printList(Head);
    Head=rotate(Head,4);
    printList(Head);
    // cout<<Head->data;
    // cout<<printList(Head);
    return 0;
}