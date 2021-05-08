#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

#define edges pair<int, int>
class Graph
{
private:
    int vertices;
    vector<pair<int, edges>> G;
    vector<pair<int, edges>> mst;
    int *parent;

public:
    Graph(int);
    void addEdgeWeight(int, int, int);
    void krukshal();
    void Union(int, int);
    int FindRoot(int);
    void print();
};
Graph::Graph(int vertices)
{
    this->vertices = vertices;
    parent = new int[vertices];
    for (int i = 0; i < vertices; i++)
    {
        parent[i] = i;
    }
}
void Graph::addEdgeWeight(int a, int b, int w) // forming a vector of pair {{weight,{a,b}},{weight1,{a1,b1}},{weight2,{a2,b2}}}
{
    G.push_back(make_pair(w, edges(a, b)));
}
void Graph::Union(int firstRoot, int secondRoot)
{
    parent[firstRoot] = parent[secondRoot];
}
int Graph::FindRoot(int i)
{
    if (i == parent[i])
    {
        return i;
    }
    else
    {
        return FindRoot(parent[i]);
    }
}
void Graph::krukshal()
{
    int firstRoot, secondRoot;
    sort(G.begin(), G.end()); // this will sort the vector in terms of weight
    for (auto i = G.begin(); i != G.end(); i++)
    {
        firstRoot = FindRoot(i->second.first);
        secondRoot = FindRoot(i->second.second);
        if (firstRoot != secondRoot)
        {
            mst.push_back(*i);
            Union(firstRoot, secondRoot);
        }
    }
}
void Graph::print()
{
    for (int i = 0; i < mst.size(); i++)
    {
        cout << mst[i].second.first << " - " << mst[i].second.second << "    => " << mst[i].first;
        cout << endl;
    }
}

int main()
{
    int v;
    cout << "Enter the no. of vertex you have in the graph(Undirected graph ) ";
    cin >> v;
    char ch;
    Graph g(v);
    do
    {
        int a, b, weight;
        cout << "Enter the two vertex btw which you want to have edges , then also enter the weight btw the edges that you enter : ";
        cin >> a >> b >> weight;
        g.addEdgeWeight(a, b, weight);
        cout << "Enter Y or y to enter the pair of edge .... Else enter any key !!! ";
        cin >> ch;

    } while (ch == 'y' or ch == 'Y');

    cout << endl;
    g.krukshal();
    g.print();

    return 0;
}
