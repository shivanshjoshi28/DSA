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
    vector<Node *> neighbour;
};
Node *CreateGraph()
{
    Node *first = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();
    first->data = 1;
    second->data = 2;
    third->data = 3;
    fourth->data = 4;
    vector<Node *> v;
    v.push_back(second);
    v.push_back(fourth);
    first->neighbour = v;
    v.clear();
    v.push_back(first);
    v.push_back(third);
    second->neighbour = v;
    v.clear();
    v.push_back(second);
    v.push_back(fourth);
    third->neighbour = v;
    v.clear();
    v.push_back(first);
    v.push_back(third);
    fourth->neighbour = v;
    return first;
}
void BFSPrint(Node *src)
{
    queue<Node *> q;
    map<Node *, bool> visited;
    visited[src] = true;
    q.push(src);

    while (!q.empty())
    {
        Node *top = q.front();
        cout << top->data << " Ref/Address =" << top << endl;
        q.pop();
        vector<Node *> neigh = top->neighbour;
        for (int i = 0; i < neigh.size(); i++)
        {
            if (!visited[neigh[i]])
            {
                visited[neigh[i]] = true;
                q.push(neigh[i]);
            }
        }
    }
}

Node *CloneGraph(Node *src)
{
    map<Node *, Node *> m;
    queue<Node *> q;
    q.push(src);

    Node *Clone = new Node();
    Clone->data = src->data;
    m[src] = Clone;
    while (!q.empty())
    {

        Node *topnode = q.front();
        q.pop();

        vector<Node *> neghb = topnode->neighbour;
        for (int i = 0; i < neghb.size(); i++)
        {
            if (m[neghb[i]] == NULL)
            {
                Clone = new Node();
                Clone->data = neghb[i]->data;
                m[neghb[i]] = Clone;
                q.push(neghb[i]);
            }
            m[topnode]->neighbour.push_back(m[neghb[i]]);
        }
    }
    return m[src];
}
int main()
{
    boost;
    Node *src = CreateGraph();
    BFSPrint(src);
    cout << endl;
    Node *clonesrc = CloneGraph(src);
    BFSPrint(clonesrc);
    return 0;
}