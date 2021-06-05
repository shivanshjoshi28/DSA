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
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
Node *SwapTwo(Node *root)
{
    if (root == NULL || root->next == NULL)
        return root;
    Node *prev = root;
    Node *curr = root->next->next;
    root = root->next;
    root->next = prev;
    while (curr != NULL && curr->next != NULL)
    {
        prev->next = curr->next;
        Node *next = curr->next->next;
        prev = curr;
        curr->next->next = curr;
        curr = next;
    }
    prev->next = curr;
    return root;
}
void Display(Node *root)
{
    Node *curr = root;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
int main()
{
    boost;
    Node *root = new Node(5);
    root->next = new Node(2);
    root->next->next = new Node(1);
    root->next->next->next = new Node(6);
    root->next->next->next->next = new Node(8);
    root = SwapTwo(root);
    Display(root);
    return 0;
}