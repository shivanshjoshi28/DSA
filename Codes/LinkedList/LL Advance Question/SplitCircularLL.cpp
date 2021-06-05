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

void Display(Node *root)
{
    cout << root->data << " ";
    Node *curr = root->next;
    while (curr != root)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
void Split(Node *head, Node **h1, Node **h2)
{
    *h1 = head;
    Node *slow = head;
    Node *fast = head->next;
    while (fast != head && fast->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *start = slow->next;
    *h2 = slow->next;
    slow->next = *h1;
    while (start->next != head)
    {
        start = start->next;
    }
    start->next = *h2;
}
int main()
{
    // boost;
    Node *root = new Node(5);
    root->next = new Node(3);
    root->next->next = new Node(2);
    root->next->next->next = root;
    Node *h1 = NULL;
    Node *h2 = NULL;
    Node **ref1 = &h1;
    Node **ref2 = &h2;
    Split(root, ref1, ref2);
    Display(h1);
    cout << endl;
    Display(*ref2);
    return 0;
}
