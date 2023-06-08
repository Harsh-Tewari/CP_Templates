// Shortest path in directed graph
// Helps to find -ve cycle
// take edges in any order
// relax all edges n-1 times
// complexity -> EV

#include <bits/stdc++.h>
using namespace std;

/*  Function to implement Bellman Ford
 *   edges: vector of vectors which represents the graph
 *   src: source vertex to start traversing graph with
 *   n: number of vertices
 */
vector<int> bellman_ford(int n, vector<vector<int>> &edges, int src)
{
    vector<int> d(n, 1e8);
    int u, v, wt;
    d[src] = 0;
    int times = n - 1;
    while (times--)
    {
        for (auto &e : edges)
        {
            u = e[0];
            v = e[1];
            wt = e[2];
            if (d[u] + wt < d[v])
            {
                d[v] = d[u] + wt;
            }
        }
    }
    // We Get our Shortest distance array
    for (auto &e : edges)
    {
        u = e[0];
        v = e[1];
        wt = e[2];
        if (d[u] + wt < d[v])
        {
            d = {-1}; // Negative Cycle Detected
            break;
        }
    }
    return d;
}