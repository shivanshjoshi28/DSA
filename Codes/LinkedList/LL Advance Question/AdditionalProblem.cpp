
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
	int key;
	Node *next;
	Node(int k)
	{
		key = k;
		next = NULL;
	}
};

Node *insert(Node *root, int data)
{
	if (root == NULL)
		return new Node(data);

	root->next = insert(root->next, data);
	return root;
}

void display(Node *root)
{
	if (root == NULL)
		return;
	else
		cout << root->key << " ";
	display(root->next);
}

Node *reversepart(Node *root, int k)
{
	Node *prev = NULL;
	Node *next = NULL;
	int count = 0;
	Node *curr = root;
	while (curr != NULL && count < k)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}
	if (next != NULL)
	{
		Node *rest_head = reversepart(next, k);
		root->next = rest_head;
	}
	return prev;
}

Node *addOne(Node *root, int &carry)
{
	if (root == NULL)
		return NULL;
	Node *curr = addOne(root->next, carry);
	// cout<<"at root= "<<root->key<<" carry = "<<carry<<endl;
	if (root != NULL && root->next == NULL)
	{
		// carry=0;
		// cout<<"inside first"<<endl;
		if (root->key + 1 >= 10)
		{
			root->key = 0;
			carry = 1;
		}
		else
		{
			root->key = root->key + 1;
			carry = 0;
		}
	}
	else
	{
		// cout<<"inside second"<<endl;
		if (root->key + carry >= 10)
		{
			root->key = 0;
			carry = 1;
		}
		else
		{
			root->key = root->key + carry;
			carry = 0;
		}
	}
	return root;
}

Node *combinezero(int n, Node *root)
{
	Node *newroot = new Node(0);
	if (n == 0)
		return root;
	else
	{

		Node *prev = newroot;
		for (int i = 0; i < n - 1; ++i)
		{
			Node *curr = new Node(0);
			prev->next = curr;
			prev = curr;
		}
		prev->next = root;
	}
	return newroot;
}
Node *addLL(Node *first, Node *second, int &carry)
{
	if (first == NULL)
		return NULL;
	Node *curr = addLL(first->next, second->next, carry);

	// if(first!=NULL && first->next==NULL)
	// {
	int firstkeyinitial = first->key;
	first->key = (first->key + second->key + carry) % 10;
	carry = (firstkeyinitial + second->key + carry) / 10;

	// }
	// else
	// {
	// 	// cout<<"inside second"<<endl;
	// 	if(root->key+carry>=10)
	// 	{
	// 		root->key=0;
	// 		carry=1;
	// 	}
	// 	else
	// 	{
	// 		root->key=root->key+carry;
	// 		carry=0;
	// 	}
	// }
	return first;
}
void addTwoLL(Node *first, Node *second)
{
	int countfirst = 0;
	Node *currfirst = first;
	while (currfirst != NULL)
	{
		countfirst++;
		currfirst = currfirst->next;
	}

	int countsecond = 0;
	Node *currsecond = second;
	while (currsecond != NULL)
	{
		countsecond++;
		currsecond = currsecond->next;
	}
	int maximum = max(countfirst, countsecond);
	first = combinezero(abs(maximum - countfirst), first);
	second = combinezero(abs(maximum - countsecond), second);
	display(first);
	cout << endl;
	display(second);
	int carry = 0;
	Node *newr = addLL(first, second, carry);
	cout << endl;
	display(newr);
}
int main()
{
	// Node *root= new Node(10);
	// root=insert(root,20);
	// root=insert(root,30);
	// root=insert(root,40);
	// root=insert(root,50);
	// root=insert(root,60);
	// root=insert(root,70);
	// root=insert(root,80);
	// root=insert(root,90);
	// root=insert(root,100);
	// display(root);
	// cout<<endl;
	// int k=3;

	// root=reversepart(root,k);
	// display(root);

	Node *root = new Node(6);
	root = insert(root, 3);
	// root=insert(root,8);
	// root=insert(root,9);
	// root=insert(root,9);
	Node *second = new Node(7);
	addTwoLL(root, second);

	return 0;
}