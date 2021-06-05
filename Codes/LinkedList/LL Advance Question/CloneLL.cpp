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
    Node *random;
    Node(int d)
    {
        data = d;
        next = NULL;
        random = NULL;
    }
};
void Display(Node *root)
{
    Node *curr = root;
    while (curr != NULL)
    {
        cout << curr->data << " - " << curr << endl;
        curr = curr->next;
    }
}
void Clone1(Node *root)
{
    Display(root);
    unordered_map<Node *, Node *> um;
    Node *curr = root;
    while (curr != NULL)
    {
        um[curr] = new Node(curr->data);
        curr = curr->next;
    }
    curr = root;
    while (curr != NULL)
    {
        Node *temp = um[curr];
        if (curr->random != NULL)
            temp->random = um[curr->random];
        temp->next = um[curr->next];
        curr = curr->next;
    }
    cout << endl;
    Display(um[root]);
}
void Clone2(Node *root)
{
    Node *curr = root;
    while (curr != NULL) // inserting duplicate
    {
        Node *next = curr->next;
        curr->next = new Node(curr->data);
        curr->next->next = next;
        curr = next;
    }
    curr == root;
    while (curr != NULL) // joining the nodes
    {
        if (curr->random != NULL)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    Node *newHead = root->next;
    curr = newHead;
    while (curr->next != NULL && curr != NULL) //removing the original node
    {
        Node *next = curr->next->next;
        free(curr->next);
        curr->next = next;
        curr = next;
    }

    Display(newHead);
}
int main()
{
    boost;
    Node *root = new Node(10);
    root->next = new Node(5);
    root->next->next = new Node(20);
    root->next->next->next = new Node(15);
    root->next->next->next->next = new Node(20);
    root->random = root->next->next;
    root->next->random = root->next->next->next;
    root->next->next->random = root;
    root->next->next->next->random = root->next->next;
    root->next->next->next->next->random = root->next->next->next;
    Clone1(root); // using hashtable   TC: O(n)           SC: O(n)
    Clone2(root); // without using hashtable O(n)          SC:O(1)

    return 0;
}