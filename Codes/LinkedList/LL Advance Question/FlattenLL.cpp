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
    Node *bottom;
    Node(int d)
    {
        data = d;
        next = NULL;
        bottom = NULL;
    }
};
void Displaybottom(Node *root)
{
    Node *curr = root;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->bottom;
    }
}
Node *Merge(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    Node *head = NULL;
    if (a->data <= b->data)
    {
        head = a;
        a = a->bottom;
    }
    else
    {
        head = b;
        b = b->bottom;
    }
    Node *curr = head;
    while (a != NULL && b != NULL)
    {
        if (a->data <= b->data)
        {
            curr->bottom = a;
            curr = curr->bottom;
            a = a->bottom;
        }
        else
        {
            curr->bottom = b;
            curr = curr->bottom;
            b = b->bottom;
        }
    }
    if (a != NULL)
    {
        curr->bottom = a;
    }
    if (b != NULL)
    {
        curr->bottom = b;
    }

    return head;
}

Node *Flatten(Node *root)
{
    if (root == NULL or root->next == NULL)
        return root;
    return Merge(root, Flatten(root->next));
}
int main()
{
    boost;
    // 5 -> 10 -> 19 -> 28
    // |     |     |     |
    // 7     20    22   35
    // |           |     |
    // 8          50    40
    // |                 |
    // 30               45
    Node *root = new Node(5);
    root->bottom = new Node(7);
    root->bottom->bottom = new Node(8);
    root->bottom->bottom->bottom = new Node(30);
    root->next = new Node(10);
    root->next->bottom = new Node(20);
    root->next->next = new Node(19);
    root->next->next->bottom = new Node(22);
    root->next->next->bottom->bottom = new Node(50);
    root->next->next->next = new Node(28);
    root->next->next->next->bottom = new Node(35);
    root->next->next->next->bottom->bottom = new Node(40);
    root->next->next->next->bottom->bottom->bottom = new Node(45);
    root = Flatten(root);
    Displaybottom(root);
    return 0;
}