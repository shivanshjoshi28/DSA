// https://www.hackerearth.com/practice/data-structures/linked-list/singly-linked-list/practice-problems/algorithm/remove-friends-5/
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

void print(Node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    print(head->next);
}

Node *insert(Node *top, int data)
{
    Node *sample = new Node(data);
    if (top == NULL)
        return sample;

    top->next = insert(top->next, data);
    return top->next;
}

pair<Node *, Node *> reversepart(Node *head, Node *end)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr != end)
    {
        Node *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    // cout << "Before returning we got " << prev->data << " to " << head->data << endl;
    return MP(prev, head);
}
Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        if (curr->data % 2 == 0)
        {
            Node *toconnectrevese = curr;
            while (curr != NULL && curr->data % 2 == 0)
            {
                curr = curr->next;
            }
            // if (curr != NULL)
            // cout << "Got even from " << toconnectrevese->data << " to " << curr->data << endl;
            pair<Node *, Node *> got = reversepart(toconnectrevese, curr); // curr is at odd or end, prev is at NULL or at odd;
            if (prev == NULL)
            {
                head = got.first;
                // cout << "head = " << head->data << endl;
                got.second->next = curr;
            }
            else
            {
                prev->next = got.first;
                got.second->next = curr;
            }
        }
        if (curr == NULL)
            break;
        prev = curr;
        curr = curr->next;
    }
    return head;
}
int main()
{
    // boost;
    Node *head = NULL;
    Node *top = NULL;
    int n;
    cin >> n;

    rep(i, n)
    {
        int temp;
        cin >> temp;
        if (i == 0)
        {
            head = insert(top, temp);
            top = head;
        }
        else
        {
            top = insert(top, temp);
        }
    }

    head = reverse(head);
    print(head);
    return 0;
}

// we can also do this question using stack. where inserting the item to the LL. THe even element are stored in stack and
// retrieved only once we got odd or reach the last