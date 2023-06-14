// Tarjan's Algorithm
// Maintain a reaching time[] and low[] array
// Upon ending the recursion call from a node, update its low to lowest of all neighbours except the parent
// if parent has a reaching time less than low of child, the edge is a bridge
// defined for a undirected connected graph or for dir conn graph with all duplex edges
// sc=>v+2e+3n
// tc=>v+2e

#include <bits/stdc++.h>
using namespace std;

class Bridges
{
public:
    vector<int> reach, low;
    int time, n;

    Bridges(int n)
    {
        this->n = n;
        time = 0;
        reach.resize(n);
        low.resize(n);
    }
    void dfs(int idx, vector<int> adj[], vector<vector<int>> &ans, vector<int> &vis, int parent)
    {
        vis[idx] = 1;
        time++;
        reach[idx] = time;
        low[idx] = time;
        for (int node : adj[idx])
        {
            if (!vis[node])
            {
                dfs(node, adj, ans, vis, idx);
                if (reach[idx] < low[node])
                {
                    ans.push_back({idx, node});
                }
                low[idx] = min(low[idx], low[node]);
            }
            else if (node != parent)
            {
                low[idx] = min(low[idx], low[node]);
            }
        }
    }
    vector<vector<int>> criticalConnections(vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        for (auto &i : connections)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<vector<int>> ans;
        vector<int> vis(n, 0);
        dfs(0, adj, ans, vis, -1);
        return ans;
    }
};