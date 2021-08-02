// // C++ implementation of the approach
// #include <bits/stdc++.h>
// using namespace std;

// const int MAX = 100;

// // Stores the vertices
// int store[MAX], n;

// // Graph
// int graph[MAX][MAX];

// // Degree of the vertices
// int d[MAX];

// // Function to check if the given set of vertices
// // in store array is a clique or not
// bool is_clique(int b)
// {
//     // Run a loop for all the set of edges
//     // for the select vertex
//     for (int i = 1; i < b; i++)
//     {
//         for (int j = i + 1; j < b; j++)

//             // If any edge is missing
//             if (graph[store[i]][store[j]] == 0)
//                 return false;
//     }
//     return true;
// }

// // Function to print the clique
// void print(int n)
// {

//     cout << "printing store from 1 to " << n - 1 << endl;
//     for (int i = 1; i < n; i++)
//         cout << store[i] << " ";
//     cout << ", ";
// }

// // Function to find all the cliques of size s
// void findCliques(int i, int l, int s)
// {
//     // Check if any vertices from i+1 can be inserted
//     for (int j = i + 1; j <= n - (s - l); j++)

//         // If the degree of the graph is sufficient
//         if (d[j] >= s - 1)
//         {
//             cout << "Processing " << j << endl;

//             // Add the vertex to store
//             store[l] = j;
//             cout << "store[" << l << "] = " << j << endl;

//             // If the graph is not a clique of size k
//             // then it cannot be a clique
//             // by adding another edge
//             if (is_clique(l + 1))
//             {
//                 cout << "checking l+1= " << l + 1 << " is clique" << endl;
//                 // If the length of the clique is
//                 // still less than the desired size
//                 if (l < s)
//                 {
//                     cout << "Called find clique with new i= " << j << " and new l= " << l + 1 << "and s= " << s << endl;
//                     // Recursion to add vertices
//                     findCliques(j, l + 1, s);
//                 }

//                 // Size is met
//                 else
//                     print(l + 1);
//             }
//         }
// }

// // Driver code
// int main()
// {
//     int edges[][2] = {{1, 2},
//                       {2, 3},
//                       {3, 1},
//                       {4, 3},
//                       {4, 5},
//                       {5, 3}},
//         k = 3;
//     int size = sizeof(edges) / sizeof(edges[0]);
//     n = 5;

//     for (int i = 0; i < size; i++)
//     {
//         graph[edges[i][0]][edges[i][1]] = 1;
//         graph[edges[i][1]][edges[i][0]] = 1;
//         d[edges[i][0]]++;
//         d[edges[i][1]]++;
//     }

//     findCliques(0, 1, k);

//     return 0;
// }

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

#define MAX 100
int graph[MAX][MAX] = {0};
bool is_clique(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (graph[arr[i]][arr[j]] == 0)
                return false;
        }
    }
    return true;
}
void solve(vector<int> adj[], int v, int e, int k, int start, vector<int> arr, int d[])
{
    if (arr.size() == k)
    {
        // main processing
        if (is_clique(arr))
        {
            for (auto it : arr)
                cout << it << " ";
            cout << endl;
        }
        return;
    }
    for (int i = start; i <= v - (k - arr.size()); i++)
    {
        if (d[i] >= k - 1)
        {
            arr.push_back(i);
            solve(adj, v, e, k, i + 1, arr, d);
            arr.pop_back();
        }
    }
}
int main()
{
    // boost;
    int v = 6;
    int e = 9;
    int d[v] = {0};
    vector<int> arr;
    vector<int> adj[v];
    rep(i, e)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        graph[a][b] = 1;
        graph[b][a] = 1;
        d[a] = d[a] + 1;
        d[b] = d[b] + 1;
    }
    int k = 3;
    solve(adj, v, e, k, 0, arr, d);

    return 0;
}