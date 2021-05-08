// this algorithm doesn't work in case of negative weight of the edges. 
#include<bits/stdc++.h>
#include<vector>
#include <iostream>
using namespace std;
class Node;
class Edge;
vector<Node * >nodes;  // vector to store all the pointer of class type Node 
vector<Edge * >edges; // vector to store all the pointer of class type Edge

// Defination of class Node
class Node 
{
    public  :
        char ch;
        int distancefromstart;
        Node * previous;
    public:
        Node(char ch):ch(ch),previous(NULL),distancefromstart(INT_MAX)
        {
            nodes.push_back(this);
        }

};
//Defination of class Edge
class Edge 
{
    public:
        Node * node1;
        Node * node2;
        int distance;
    public:
        Edge(Node * node1, Node * node2, int distance):node1(node1),node2(node2),distance(distance)
        {
            edges.push_back(this);
        }
        bool connect(Node * node3, Node * node4)
        {
            if((node1==node3 && node2==node4) or (node1==node4 && node2==node3))
            {
                return true;
            }
            return false;
        }
};
Node * FindSmall(vector<Node * > & nodes)
{
    int size=nodes.size();
    if(size==0) return NULL;
    int minnodepos=0;
    Node * minnode=nodes[0];

    for(int i=0;i<size;i++)
    {
        Node * currentnode= nodes[i];
        if((currentnode->distancefromstart) < (minnode->distancefromstart))
        {
            minnode=currentnode;
            minnodepos=i;
        }
    }
    nodes.erase(nodes.begin()+minnodepos);
    // cout<<minnode->ch<<endl;
    return minnode;
}
bool present(vector<Node * > & nodes, Node * tocheck)
{
    for(int i=0;i<nodes.size();i++)
    {
        Node * current=nodes.at(i);
        if(current==tocheck)
            return true;
    }
    return false;
}
vector<Node *>* adj(Node * smallnode)
{
    vector<Node *> * adjacent= new vector<Node * > ();    // Pls note this. if we don't use new to allocate memory it will behave differently. 
    for(int i=0;i<edges.size();i++)
    {
        Node * tocheck=NULL;
        Edge * current= edges[i];
        if(current->node1==smallnode)
        {
            // cout<<current->node2->ch<<endl;
            tocheck= current->node2;
        }
        else if( current->node2== smallnode)
        {
            // cout<<current->node1->ch<<endl;
            tocheck= current->node1;
        }
        // cout<<"i is : "<<i<<endl;
        if(tocheck && present(nodes,tocheck))
        {
            // cout<<tocheck->ch<<endl;
            adjacent->push_back(tocheck);
        }
    }
    return adjacent;
}
int dis(Node * node1 , Node * node2)
{
    for(int i=0;i<edges.size();i++)
    {
        Edge * current = edges[i];
        if(current->connect(node1,node2))
        {
            return current->distance;
        }
    }
    return -1;
}
void  DijkstrasStart()
{
    while(!nodes.empty())
    {
        // cout<<nodes.size()<<endl;
    
    Node * smallnode= FindSmall(nodes);
    vector<Node * > * adjacentNodesTosmallest= adj(smallnode);
    for( int i=0;i<adjacentNodesTosmallest->size();i++)
    {
        Node * current= adjacentNodesTosmallest->at(i);
        // cout<<current->ch<<endl;
        int temp=dis(smallnode,current)+ smallnode->distancefromstart;
        if(temp<current->distancefromstart)
        {
            current->distancefromstart=temp;
            current->previous=smallnode;
        }
    }
    delete adjacentNodesTosmallest;
    }
}
void PrintShortestRouteTo(Node * final)
{
    cout<<"Distance of "<<final->ch<<" from a is :"<<final->distancefromstart<<endl;
    Node * previous= final;
    cout<<"The shortest path is : ";

    while (previous)
    {
        cout<<previous->ch<<" ";
        previous=previous->previous;
    }
    cout<<endl;
}

void Dijkstraj()
{
  Node* a = new Node('a');
  Node* b = new Node('b');
  Node* c = new Node('c');
  Node* d = new Node('d');
  Node* e = new Node('e');
  Node* f = new Node('f');
  Node* g = new Node('g');

  Edge* e1 = new Edge(a, c, 1);
  Edge* e2 = new Edge(a, d, 2);
  Edge* e3 = new Edge(b, c, 2);
  Edge* e4 = new Edge(c, d, 1);
  Edge* e5 = new Edge(b, f, 3);
  Edge* e6 = new Edge(c, e, 3);
  Edge* e7 = new Edge(e, f, 2);
  Edge* e8 = new Edge(d, g, 1);
  Edge* e9 = new Edge(g, f, 1);
  a->distancefromstart=0;
  DijkstrasStart();
  PrintShortestRouteTo(f);
}

int main()
{
    Dijkstraj();
    return 0;
}