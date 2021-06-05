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

bool CheckPalindrome(Node *root)
{
    Node *slow = root;
    Node *fast = root;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *prev = NULL;
    Node *curr = slow;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    while (prev != NULL)
    {
        if (prev->data != root->data)
        {
            return false;
        }
        prev = prev->next;
        root = root->next;
    }
    return true;
}
int main()
{
    // boost;
    Node *root = new Node(1);
    root->next = new Node(3);
    root->next->next = new Node(3);
    root->next->next->next = new Node(1);
    if (CheckPalindrome(root))
        cout << " Palindrome " << endl;
    else
        cout << " Not a palindrome" << endl;
    return 0;
}
