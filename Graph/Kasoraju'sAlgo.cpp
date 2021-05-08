#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Graph
{
private:
    int vertices;
    vector<int> *adjarr;

public:
    Graph(int data);
    void DFS(int start, bool[]);
    void SCC();
    void add_edge(int, int);
    Graph transpose();
    void DFS_return_stack(int, stack<int> &, bool[]);
};

// this is the function to print the DFS of the graph
void Graph::DFS(int start, bool v[])
{
    v[start] = true;
    cout << start << " ";
    vector<int>::iterator i;
    for (i = adjarr[start].begin(); i != adjarr[start].end(); i++)
    {
        if (!v[*i])
        {
            DFS(*i, v);
        }
    }
}
Graph Graph::transpose()
{
    Graph g(vertices);
    for (int s = 0; s < vertices; s++)
    {
        vector<int>::iterator i;
        for (i = adjarr[s].begin(); i != adjarr[s].end(); ++i)
        {
            g.adjarr[*i].push_back(s);
        }
    }
    return g;
}

void Graph::DFS_return_stack(int start, stack<int> &s, bool v[])
{
    v[start] = true;
    vector<int>::iterator i;
    for (i = adjarr[start].begin(); i != adjarr[start].end(); i++)
    {
        if (!v[*i])
        {
            DFS_return_stack(*i, s, v);
        }
    }

    s.push(start);
}
void Graph::SCC()
{
    stack<int> s;
    bool *v = new bool[vertices];
    for (size_t i = 0; i < vertices; i++)
    {
        v[i] = false;
    }

    for (int i = 0; i < vertices; i++)
    {
        if (!v[i])
        {
            DFS_return_stack(i, s, v);
        }
    }
    Graph gr = transpose();

    for (size_t i = 0; i < vertices; i++)
    {
        v[i] = false;
    }
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        if (!v[top])
        {
            gr.DFS(top, v);
            cout << endl;
        }
    }
}

Graph::Graph(int data)
{
    vertices = data;
    adjarr = new vector<int>[vertices];
}

void Graph::add_edge(int a, int b)
{
    adjarr[a].push_back(b);
}

int main()
{
    int v;
    cout << "Enter the no. of vertex you have in the graph(directed graph ) ";
    cin >> v;
    char ch;
    Graph g(v);
    do
    {
        int a, b;
        cout << "Enter the two vertex btw which you want to have edges ( like from i to j ) : ";
        cin >> a >> b;
        g.add_edge(a, b);
        cout << "Enter Y or y to enter the pair of edge .... Else enter any key !!! ";
        cin >> ch;

    } while (ch == 'y' or ch == 'Y');

    cout << "The strongly connected components are : \n";
    g.SCC();
    cout << endl;

    return 0;
}