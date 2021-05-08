#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

class Graph
{
private:
    int vertices;
    vector<int> *adjarr;
    int *visited;
    int * smallest;
    int * distance;
    int * parent;

public:
    Graph(int data);
    void add_edge(int, int);
    void DFS(int start);
};

int counter=0;
int bridge=0;
Graph::Graph(int data)
{
    vertices = data;
    adjarr = new vector<int>[vertices];
    visited = new int[vertices];
    smallest = new int[vertices];
    distance = new int[vertices];
    parent = new int[vertices];
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
        smallest[i]=-1;
        distance[i]=0;
        parent[i]=-1;
    }
}

void Graph::add_edge(int a, int b)
{
    adjarr[a].push_back(b);
    adjarr[b].push_back(a);
}

// this is the function to print the DFS of the graph
void Graph::DFS(int start)
{
    visited[start] = 1;
    distance[start]=++counter;
    cout << start << " ";
    vector<int>::iterator i;
    int flag=0;
    for (i = adjarr[start].begin(); i != adjarr[start].end(); i++)
    {
        if (!visited[*i])
        {
            parent[*i]=start;
            flag++;
            DFS(*i);
            // cout<<"\nAfter backtracking from node "<<*i<<" we have got the smallest from there as "<<smallest[*i]<<" and it is compared with node " <<start<<" and distance of start is "<<distance[start];
            if(smallest[*i]>distance[start])
            {
                if(smallest[*i]==INT_MAX) smallest[*i]=-1;
                // smallest[*i]=-1;
                bridge++;
                cout<<"We have got a bridge from "<<start <<" to "<< *i<<endl;
            }
        }
    }
    // if()
    // {
        int min1=INT_MAX;
        // cout<<"start = "<<start<<endl;
        for (i = adjarr[start].begin(); i != adjarr[start].end(); i++)
        {
            // cout<<"\n For "<<*i << " it has smallest["<<*i<<"] as "<<smallest[*i]<<" and parent["<<start<<"] as "<<parent[start]<<endl;
            if(smallest[*i]==-1 and parent[start]!=*i)
            {
                if(distance[*i]<min1)
                {
                    // cout<<"if distance[*i] i.e "<<distance[*i]<<" < min1 i.e "<< min1<<endl;
                    min1=distance[*i];
                }
            }
            else if( smallest[*i]>=0 and parent[start]!=*i)
            {
                // cout<<"else if smallest[*i] i.e "<<smallest[*i]<<" >0 "<<endl;

                int m=min(smallest[*i],distance[*i]);
                if(m<min1) min1=m;
            }

        }
        // cout<<"Hello";
        smallest[start]=min1;
    // }

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
        int a, b;
        cout << "Enter the two vertex btw which you want to have edges ( like from i to j it will automatically take it as j to i) : ";
        cin >> a >> b;
        g.add_edge(a, b);
        cout << "Enter Y or y to enter the pair of edge .... Else enter any key !!! ";
        cin >> ch;

    } while (ch == 'y' or ch == 'Y');

    cout << "The DFS transerval of the graph is : ";
    g.DFS(0);
    cout<<" Total no. of bridge are : "<<bridge<<endl;
    cout << endl;

    return 0;
}