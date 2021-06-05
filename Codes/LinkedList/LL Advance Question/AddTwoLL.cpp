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
Node *AddTwo(Node *r1, Node *r2)
{
    int s = 0;
    int c = 0;
    Node *R1 = reverse(r1);
    Node *R2 = reverse(r2);
    Node *Newhead = NULL;
    Node *prev = NULL;
    while (R1 != NULL || R2 != NULL)
    {
        s = c + (R1 ? R1->data : 0) + (R2 ? R2->data : 0);
        if (s >= 10)
            c = 1;
        else
            c = 0;
        s = s % 10;
        Node *temp = new Node(s);
        if (Newhead == NULL)
        {
            Newhead = temp;
            prev = Newhead;
        }
        else
        {
            prev->next = temp;
            prev = temp;
        }
        if (R1 != NULL)
            R1 = R1->next;
        if (R2 != NULL)
            R2 = R2->next;
    }
    if (c > 0)
    {
        prev->next = new Node(c);
    }
    Newhead = reverse(Newhead);
    return Newhead;
}

int main()
{
    // boost;
    Node *root = new Node(9);
    root->next = new Node(7);
    root->next->next = new Node(5);
    Node *root2 = new Node(5);
    root2->next = new Node(5);
    Node *newLL = AddTwo(root, root2); // we need to add 975+55 and return the LL that contain  - 1030
    Display(newLL);
    return 0;
}