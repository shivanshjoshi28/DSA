//wap to remove the loop
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
    Node *curr = root;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
void LoopRemove(Node *root)
{
    Node *slow = root;
    Node *fast = root;
    bool found = false;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            found = true;
            break;
        }
    }
    if (!found)
        return;
    slow = root;
    while (fast->next != slow->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL; // this is from where the loop start
}
int main()
{
    // boost;
    Node *root = new Node(6);
    root->next = new Node(3);
    root->next->next = new Node(6);
    root->next->next->next = new Node(5);
    root->next->next->next->next = new Node(3);
    root->next->next->next->next->next = root->next->next;
    // Display(root);
    LoopRemove(root);
    cout << endl;
    Display(root);
    return 0;
}

// TC: O(N)   SC: O(1)