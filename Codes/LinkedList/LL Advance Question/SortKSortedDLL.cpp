#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#include <vector>
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back
#define MP make_pair
#define endl "\n"
#define boost                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define F first
#define S second
const int inf = (int)1e18;
const int ninf = (int)-1e17;
#define rep(a, b) for (int a = 0; a < b; a++)
#define per(a, b) for (int a = b - 1; a >= 0; a--)
#define FOR(it, start, end) for (auto it = start; it != end; it++)

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};
void Display(Node *root)
{
    Node *curr = root;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
void run()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
struct compare // comparator to form min heap
{
    bool operator()(Node *first, Node *second)
    {
        return (first->data > second->data);
    }
};
Node *SortK(Node *root, int k)
{
    if (root == NULL)
        return root;
    priority_queue<Node *, vector<Node *>, compare> pq;
    int count = 0;
    Node *curr;
    for (curr = root; curr != NULL && count <= k; count++) // insert first k element in heap TC: O(k log k)
    {
        pq.push(curr);
        curr = curr->next;
    }

    Node *NewHead = NULL;
    Node *prev1 = NULL;
    while (!pq.empty())
    {
        if (NewHead == NULL)
        {
            NewHead = pq.top();
            NewHead->prev = NULL;
            prev1 = NewHead;
        }
        else
        {
            prev1->next = pq.top();
            pq.top()->prev = prev1;
            prev1 = pq.top();
        }
        pq.pop();
        if (curr != NULL)
        {
            pq.push(curr);
            curr = curr->next;
        }
    }
    prev1->next = NULL;
    return NewHead;
}

int main()
{
    boost;
    Node *root = new Node(3);
    root->prev = NULL;
    root->next = new Node(6);
    root->next->prev = root;
    root->next->next = new Node(2);
    root->next->next->prev = root->next;
    root->next->next->next = new Node(12);
    root->next->next->next->prev = root->next->next;
    root->next->next->next->next = new Node(56);
    root->next->next->next->next->prev = root->next->next->next;
    root->next->next->next->next->next = new Node(8);
    root->next->next->next->next->next->prev = root->next->next->next->next;
    root = SortK(root, 2);
    Display(root);
    return 0;
}