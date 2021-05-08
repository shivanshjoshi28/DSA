#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define V 5
int G[V][V] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}};

int main()
{
    int selected[V];
    memset(selected, 0, sizeof(selected));
    selected[0] = 1;
    int edge = 0;

    while (edge != V - 1)
    {
        int MIN = INT_MAX;
        int x = 0, y = 0;
        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] and G[i][j])
                    {
                        if (G[i][j] < MIN)
                        {
                            MIN = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        selected[y] = 1;
        cout << x << " - " << y;
        cout << endl;
        edge++;
    }
    return 0;
}