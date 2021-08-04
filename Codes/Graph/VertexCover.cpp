// // Program to print Vertex Cover of a given undirected graph
// #include <iostream>
// #include <list>
// using namespace std;

// // This class represents a undirected graph using adjacency list
// class Graph
// {
//     int V;          // No. of vertices
//     list<int> *adj; // Pointer to an array containing adjacency lists
// public:
//     Graph(int V);               // Constructor
//     void addEdge(int v, int w); // function to add an edge to graph
//     void printVertexCover();    // prints vertex cover
// };

// Graph::Graph(int V)
// {
//     this->V = V;
//     adj = new list<int>[V];
// }

// void Graph::addEdge(int v, int w)
// {
//     adj[v].push_back(w); // Add w to v’s list.
//     adj[w].push_back(v); // Since the graph is undirected
// }

// // The function to print vertex cover
// void Graph::printVertexCover()
// {
//     // Initialize all vertices as not visited.
//     bool visited[V];
//     for (int i = 0; i < V; i++)
//         visited[i] = false;

//     list<int>::iterator i;

//     // Consider all edges one by one
//     for (int u = 0; u < V; u++)
//     {
//         // An edge is only picked when both visited[u] and visited[v]
//         // are false
//         if (visited[u] == false)
//         {
//             // Go through all adjacents of u and pick the first not
//             // yet visited vertex (We are basically picking an edge
//             // (u, v) from remaining edges.
//             for (i = adj[u].begin(); i != adj[u].end(); ++i)
//             {
//                 int v = *i;
//                 if (visited[v] == false)
//                 {
//                     // Add the vertices (u, v) to the result set.
//                     // We make the vertex u and v visited so that
//                     // all edges from/to them would be ignored
//                     cout << "getting " << u << "and " << v << endl;
//                     visited[v] = true;
//                     visited[u] = true;
//                     break;
//                 }
//             }
//         }
//     }

//     // Print the vertex cover
//     for (int i = 0; i < V; i++)
//         if (visited[i])
//             cout << i << " ";
// }

// // Driver program to test methods of graph class
// int main()
// {
//     // Create a graph given in the above diagram
//     Graph g(6);
//     g.addEdge(0, 1);
//     g.addEdge(1, 2);
//     g.addEdge(1, 3);
//     g.addEdge(3, 4);
//     g.addEdge(4, 2);
//     g.addEdge(2, 5);

//     g.printVertexCover();

//     return 0;
// }
//taken from gfg
// C++ program to find out whether a given graph can be
// converted to two Cliques or not.
#include <bits/stdc++.h>
using namespace std;

const int V = 5;

// This function returns true if subgraph reachable from
// src is Bipartite or not.
bool isBipartiteUtil(int G[][V], int src, int colorArr[])
{
    colorArr[src] = 1;

    // Create a queue (FIFO) of vertex numbers and enqueue
    // source vertex for BFS traversal
    queue<int> q;
    q.push(src);

    // Run while there are vertices in queue (Similar to BFS)
    while (!q.empty())
    {
        // Dequeue a vertex from queue
        int u = q.front();
        q.pop();

        // Find all non-colored adjacent vertices
        for (int v = 0; v < V; ++v)
        {
            // An edge from u to v exists and destination
            // v is not colored
            if (G[u][v] && colorArr[v] == -1)
            {
                // Assign alternate color to this adjacent
                // v of u
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }

            // An edge from u to v exists and destination
            // v is colored with same color as u
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }

    // If we reach here, then all adjacent vertices can
    // be colored with alternate color
    return true;
}

// Returns true if a Graph G[][] is Bipartite or not. Note
// that G may not be connected.
bool isBipartite(int G[][V])
{
    // Create a color array to store colors assigned
    // to all veritces. Vertex number is used as index in
    // this array. The value '-1' of colorArr[i]
    // is used to indicate that no color is assigned to
    // vertex 'i'. The value 1 is used to indicate first
    // color is assigned and value 0 indicates
    // second color is assigned.
    int colorArr[V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;

    // One by one check all not yet colored vertices.
    for (int i = 0; i < V; i++)
        if (colorArr[i] == -1)
            if (isBipartiteUtil(G, i, colorArr) == false)
                return false;

    return true;
}

// Returns true if G can be divided into
// two Cliques, else false.
bool canBeDividedinTwoCliques(int G[][V])
{
    // Find complement of G[][]
    // All values are complemented except
    // diagonal ones
    int GC[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            GC[i][j] = (i != j) ? !G[i][j] : 0;

    // Return true if complement is Bipartite
    // else false.
    return isBipartite(GC);
}

// Driver program to test above function
int main()
{
    int G[][V] = {{0, 1, 1, 1, 0},
                  {1, 0, 1, 0, 0},
                  {1, 1, 0, 0, 0},
                  {0, 1, 0, 0, 1},
                  {0, 0, 1, 1, 0}};

    canBeDividedinTwoCliques(G) ? cout << "Yes" : cout << "No";
    return 0;
}
