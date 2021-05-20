#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef pair<int, int> ipair;
int num = 0;

void DFN(vector<int> adj[], int v, bool *visited, int source, ipair *dfn, vector<ipair> newadj[], vector<ipair> backedge[], int parent, int *pr)
{
    visited[source] = true;
    cout << source << " ";
    dfn[source] = {num, source};
    // dfn.push_back({num,source});
    for (int U : adj[source])
    {
        if (!visited[U])
        {
            pr[U] = source;
            newadj[source].push_back({U, num + 1});
            num++;
            DFN(adj, v, visited, U, dfn, newadj, backedge, source, pr);
        }
        else if (U != parent && U < source)
        {
            backedge[source].push_back({U, dfn[U].first});
        }
    }
}

void ArticulationPoint(vector<int> adj[], int v)
{
    vector<ipair> newadj[v];
    vector<ipair> backedge[v];
    bool articulate[v];

    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        articulate[i] = false;
    }
    ipair dfn[v];
    int pr[v];
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            int parent = -1;
            pr[i] = -1;
            DFN(adj, v, visited, i, dfn, newadj, backedge, parent, pr);
            num++;
        }
    }
    // this is to debug the dfn array (v.imp)
    cout << endl;
    cout << "The dfn array is : ";
    for (int i = 0; i < v; i++)
        cout << dfn[i].first << " " << dfn[i].second << endl;
    cout << endl;
    cout << "parent array is : ";
    for (int i = 0; i < v; i++)
        cout << pr[i] << " ";
    cout << endl;

    // this to debug the new Adj array
    cout << endl;
    cout << "New Adj array : " << endl;
    for (int i = 0; i < v; i++)
    {
        cout << " For i= " << i << " :";
        for (auto u : newadj[i])
        {
            cout << "\t" << u.first << " " << u.second;
        }
        cout << endl;
    }
    // this is to debug the backedge array
    cout << "New backedge array : " << endl;
    for (int i = 0; i < v; i++)
    {
        cout << " For i= " << i << " :";
        for (auto u : backedge[i])
        {
            cout << u.first << " " << u.second;
        }
        cout << endl;
    }

    ipair copydfn[v];
    for (int i = 0; i < v; i++)
        copydfn[i] = dfn[i];

    // sorting the dfn array
    sort(dfn, dfn + v, greater<ipair>());
    int low[v];
    for (int i = 0; i < v; i++)
        low[i] = INT_MAX;
    int index = v - 1;
    for (int i = 0; i < v; i++)
    {
        int dfnum = dfn[i].first;
        int vertex = dfn[i].second;
        int lowChild = INT_MAX;
        int lowBackedge = INT_MAX;
        for (auto child : newadj[vertex])
        {
            lowChild = min(low[child.second], lowChild);
        }
        for (auto backed : backedge[vertex])
        {
            lowBackedge = min(lowBackedge, backed.second);
        }
        low[index] = min(dfnum, min(lowChild, lowBackedge));
        index--;
    }
    cout << endl;
    cout << "The low array is : ";
    for (int i = 0; i < v; i++)
        cout << low[i] << " ";
    cout << endl;
    for (int i = 0; i < v; i++)
    {
        for (auto u : newadj[i])
        {
            if ((pr[i] != -1 && copydfn[i].first <= low[u.second]) || (pr[i] == -1 && newadj[i].size() >= 2))
            {
                articulate[i] = true;
            }
        }
    }
    cout << " Finally the articulation vertex are : ";
    for (int i = 0; i < v; i++)
        if (articulate[i])
            cout << i << " ";
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        int src, dst;
        cin >> src >> dst;
        adj[src].push_back(dst);
        adj[dst].push_back(src);
    }
    // for(int i=0;i<v;i++)
    // {
    //     cout<<"i = "<<i<<endl;
    //     for(int U:adj[i]) cout<<U<<" ";
    //     cout<<endl;
    // }
    ArticulationPoint(adj, v);
    return 0;
}

// low [i]=lowest reachable discovery time

// Sample input the user
// 13 15
// 0 1
// 0 2
// 1 3
// 2 3
// 3 4
// 3 5
// 4 5
// 2 6
// 2 7
// 6 7
// 8 9
// 8 10
// 9 10
// 10 11
// 11 12
// 0 1 3 2 6 7 4 5 8 9 10 11 12
// The dfn array is : 0 0
// 1 1
// 3 2
// 2 3
// 6 4
// 7 5
// 4 6
// 5 7
// 8 8
// 9 9
// 10 10
// 11 11
// 12 12

// parent array is : -1 0 3 1 3 4 2 6 -1 8 9 10 11

// New Adj array :
//  For i= 0 :     1 1
//  For i= 1 :     3 2
//  For i= 2 :     6 4
//  For i= 3 :     2 3     4 6
//  For i= 4 :     5 7
//  For i= 5 :
//  For i= 6 :     7 5
//  For i= 7 :
//  For i= 8 :     9 9
//  For i= 9 :     10 10
//  For i= 10 :    11 11
//  For i= 11 :    12 12
//  For i= 12 :
// New backedge array :
//  For i= 0 :
//  For i= 1 :
//  For i= 2 :0 0
//  For i= 3 :
//  For i= 4 :
//  For i= 5 :3 2
//  For i= 6 :
//  For i= 7 :2 3
//  For i= 8 :
//  For i= 9 :
//  For i= 10 :8 8
//  For i= 11 :
//  For i= 12 :

// The low array is : 0 0 0 0 3 3 2 2 8 8 8 11 12
//  Finally the articulation vertex are : 2 3 10 11