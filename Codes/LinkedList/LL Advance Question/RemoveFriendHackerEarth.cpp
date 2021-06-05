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
Node *deletion(Node *head, int k)
{
    Node *curr = head->next;
    Node *prev = head;
    while (curr->next != NULL && k > 0)
    {
        if (curr->data < curr->next->data)
        {
            Node *temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            k--;
            free(temp);
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    while (k > 0)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        k--;
    }
    return head;
}

int main()
{
    boost;
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

    int k;
    cin >> k;
    head = deletion(head, k);
    print(head);
    return 0;
}