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

struct Interval
{
    int a;
    int b;
};
struct Node
{
    Interval *i;
    int max;
    Node *left;
    Node *right;
    Node(Interval i1)
    {
        this->i = new Interval(i1);
        max = i1.b;
        left = NULL;
        right = NULL;
    }
};
Node *insert(Node *root, Interval i)
{
    if (root == NULL)
        return new Node(i);
    else if (i.a < root->i->a)
    {
        root->left = insert(root->left, i);
    }
    else
    {
        root->right = insert(root->right, i);
    }

    if (root->max < i.b)
    {
        root->max = i.b;
    }
    return root;
}
Interval *findconflict(Node *root, Interval i)
{
    if (root == NULL)
        return NULL;
    if (root->i->a < i.b && i.a < root->i->b)
    {
        return root->i;
    }
    if (root->left && root->left->max >= i.a)
    {
        return findconflict(root->left, i);
    }
    return findconflict(root->right, i);
}
void printConflicting(Interval arr[], int n)
{
    Node *root = new Node(arr[0]);
    for (int i = 1; i < n; i++)
    {
        Interval *res = findconflict(root, arr[i]);
        if (res != NULL)
            cout << "[" << arr[i].a << "," << arr[i].b
                 << "] Conflicts with [" << res->a << ","
                 << res->b << "]\n";
        root = insert(root, arr[i]);
    }
}

int main()
{
    boost;
    Interval appt[] = {{1, 5}, {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}};
    int n = sizeof(appt) / sizeof(appt[0]);
    cout << "Following are conflicting intervals\n";
    printConflicting(appt, n);

    return 0;
}