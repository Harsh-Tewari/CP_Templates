// Articulation Points=>Nodes on whose removal graph becomes disconnected

#include <bits/stdc++.h>
using namespace std;

class Articulation
{
public:
    vector<int> reach, low;
    int time, n;

    Articulation(int n)
    {
        this->n = n;
        time = 0;
        reach.resize(n);
        low.resize(n);
    }

    void dfs(int idx, vector<int> adj[], set<int> &s, vector<int> &vis, int parent)
    {
        vis[idx] = 1;
        time++;
        reach[idx] = time;
        low[idx] = time;
        int child = 0;
        for (int node : adj[idx])
        {
            if (!vis[node])
            {
                dfs(node, adj, s, vis, idx);
                if (reach[idx] <= low[node] && parent != -1)
                {
                    s.insert(idx);
                }
                low[idx] = min(low[idx], low[node]);
                child++;
            }
            else if (node != parent)
            {
                low[idx] = min(low[idx], reach[node]);
            }
        }
        if (parent == -1 && child > 1)
        {
            s.insert(idx);
        }
    }
    vector<int> articulationPoints(vector<int> adj[])
    {
        time = 0;
        reach.resize(n);
        low.resize(n);
        set<int> s;
        vector<int> vis(n, 0);
        dfs(0, adj, s, vis, -1);
        vector<int> ans;
        if (s.empty())
            ans.push_back(-1);
        for (int i : s)
        {
            ans.push_back(i);
        }
        return ans;
    }
};
