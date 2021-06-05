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
void run()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
Node *reverse(Node *root)
{
    Node *prev = NULL;
    Node *curr = root;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node *AddOne(Node *root)
{
    Node *rev1 = reverse(root);
    int c = 0;
    Node *headrev = rev1;
    int i = 0;
    while (rev1 != NULL)
    {
        if (rev1->data == 9 && rev1->next == NULL)
        {
            rev1->data = 1;
            Node *temp = new Node(0);
            temp->next = headrev;
            headrev = temp;
            rev1 = rev1->next;
        }
        else if (rev1->data == 9)
        {
            rev1->data = 0;
            rev1 = rev1->next;
        }
        else
        {
            rev1->data = rev1->data + 1;
            break;
        }
        i++;
    }
    headrev = reverse(headrev);
    return headrev;
}
int main()
{
    boost;
    Node *root = new Node(9);
    root->next = new Node(9);
    Node *newhead = AddOne(root);
    Display(newhead);
    return 0;
}