#include<bits/stdc++.h>
#include <iostream>
using namespace std;
class Node ;
class Edge;
vector<Node * > nodes;
vector<Edge * > edges;

class Node 
{
    public:
        char id;
        int indegree;
    public:
        Node(char ch)
        {
            id=ch;
            indegree=0;
            nodes.push_back(this);
        }
};
class Edge
{
    public:
        Node * node1;
        Node * node2;
        // int weight;
    public:
        Edge(Node * node3 , Node * node4):node1(node3), node2(node4) 
        {
            edges.push_back(this);
        }
};
void setindegree(vector<Node * > & nodes)
{
    for(int i=0;i<nodes.size();i++)
    {
        Node * currentnode= nodes[i];
        // cout<<" it is node << "<< currentnode->id<<endl;
    for(int i=0;i<edges.size();i++)
    {
        Edge * currentedge = edges[i];
        if(currentedge->node2->id==currentnode->id)
        {
            currentnode->indegree=currentnode->indegree+1;
            // cout<<" changing indegree of connected to "<<currentedge->node1->id<<" to "<<currentnode->indegree<<endl;
        }
    }
    }
}
void findsmallest(vector<Node *> & nodes, int min, Node * minnode, vector<Edge * > & edges)
{
    int pos=0;
    for(int i=1;i<nodes.size();i++)
    {
        Node * currentnode= nodes[i];
        if(currentnode->indegree<min)
        {
            min=currentnode->indegree;
            minnode= currentnode;
            pos=i;
        }
    }
    if(min==0)
    {
        cout<<minnode->id<<" "<<endl;
        nodes.erase(nodes.begin()+pos);
        // cout<<"Removed node  at pos = "<<pos<<endl;
        for(int i=0;i<edges.size();i++)
        {
            // cout<<"i= "<<i<<endl;
            Edge * currentedge= edges[i]; // removing the node 
            // cout<<"i ="<<i << " have edges from "<<currentedge->node1->id<<" to "<<currentedge->node2->id<<endl;
            if(currentedge->node1==minnode or currentedge->node2 == minnode)
            {
                // cout<<" Edge "<<currentedge->node1->id<<" to "<<currentedge->node2->id<<" is removed "<<endl;
                edges.erase(edges.begin()+i);  // removing the  combination of edge moving from minnode. 
                i--;
            }
        }
    }
    else
    {
            // cout<<" min = "<<min<<endl;
            cout<<"Sorry the topological sorting is not possible .. Pls try again with any other combination of edges and vertices !!! ";
            exit(0);
    }
    
}
void TopologicalSort()
{
    setindegree(nodes);
        // for(int i=0;i<nodes.size();i++)
        // {
        //     cout<<"when i= "<<i << " we have node = "<<nodes[i]->id<<" with indegree = "<<nodes[i]->indegree<<endl;
        // }
    int count=1;
    while(!nodes.empty())
    {
        // cout<<"count = "<<count<<" edges size = "<<edges.size()<<" nodes size = "<<nodes.size()<<endl;
        int smallestindegree=nodes[0]->indegree;
        Node * smallestindegreenode= nodes[0];
        findsmallest(nodes, smallestindegree, smallestindegreenode,edges);
        // for(int i=0;i<nodes.size();i++)
        // {
        //     cout<<"when i= "<<i << " we have node = "<<nodes[i]->id<<" with indegree = "<<nodes[i]->indegree<<endl;
        // }
        for(int i=0;i<nodes.size();i++)
        {
            nodes[i]->indegree=0;
        }
        setindegree(nodes);
        // cout<<"after applying set indegree function "<<endl;
        // for(int i=0;i<nodes.size();i++)
        // {
        //     cout<<"when i= "<<i << " we have node = "<<nodes[i]->id<<" with indegree = "<<nodes[i]->indegree<<endl;
        // }
        count++;
        // if(count>10) exit(0);
    }
}
void TopologicalSortTest()
{
    Node* a = new Node('a');
    Node* b = new Node('b');
    Node* c = new Node('c');
    Node* d = new Node('d');
    Node* e = new Node('e');

    Edge* e1 = new Edge(a, b);
    Edge* e2 = new Edge(a, d);
    Edge* e3 = new Edge(b, c);
    Edge* e4 = new Edge(d, c);
    Edge* e5 = new Edge(b, d);
    Edge* e6 = new Edge(d, e);

    TopologicalSort();
}

int main()
{
    TopologicalSortTest();
    
    return 0;
}