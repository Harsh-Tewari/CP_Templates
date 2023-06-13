// Sort all the edges according to the finishing time
// Reverse all the edges to stop inter-scc traversal
// Do a DFS

// tc and sc = O(E+V)
#include <bits/stdc++.h>
using namespace std;
class KosarajuAlgorithm
{
public:
    void finishTimeSort(int idx, stack<int> &s, vector<vector<int>> &v, vector<int> &vis)
    {
        if (vis[idx])
            return;
        vis[idx] = 1;
        for (auto &i : v[idx])
        {
            finishTimeSort(i, s, v, vis);
        }
        s.push(idx);
    }

    void dfs(int idx, vector<int> &a, vector<int> adj[], vector<int> &vis)
    {
        if (vis[idx])
            return;
        vis[idx] = 1;
        a.push_back(idx);
        for (auto &i : adj[idx])
        {
            dfs(i, a, adj, vis);
        }
    }

    // Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<vector<int>> &v)
    {
        vector<int> adj[n];

        // sorting by finish time
        stack<int> s;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                finishTimeSort(i, s, v, vis);
            }
        }

        // reversing the edges
        for (int i = 0; i < n; i++)
        {
            vis[i] = 0;
            for (auto &it : v[i])
            {
                adj[it].push_back(i);
            }
        }

        vector<vector<int>> ans;
        // dfs
        while (!s.empty())
        {
            if (!vis[s.top()])
            {
                vector<int> a;
                dfs(s.top(), a, adj, vis);
                ans.push_back(a);
            }
            s.pop();
        }

        return ans.size();
    }
};