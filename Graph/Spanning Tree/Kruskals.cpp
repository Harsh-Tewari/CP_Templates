#include <bits/stdc++.h>
using namespace std;

#define ppi pair<int, pair<int, int>>
#define ff first
#define ss second

class DisjointSet
{
public:
    vector<int> rank, parent, sizearr;

    DisjointSet(int n)
    {
        rank.resize(n + 1);
        parent.resize(n + 1);
        sizearr.resize(n + 1);
        for (int i = 0; i < n + 1; i++)
        {
            sizearr[i] = 1;
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findUParent(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = findUParent(parent[x]);
    }

    void unionByRank(int u, int v)
    {
        int pu, pv;
        pu = findUParent(u);
        pv = findUParent(v);
        if (pu == pv)
        {
            return;
        }
        if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else if (rank[pv] > rank[pu])
        {
            parent[pu] = pv;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    int unionBySize(int u, int v)
    {
        int pu, pv;
        pu = findUParent(u);
        pv = findUParent(v);
        if (pu == pv)
        {
            return 1;
        }
        if (sizearr[pu] > sizearr[pv])
        {
            parent[pv] = pu;
            sizearr[pu] += sizearr[pv];
        }
        else if (sizearr[pv] > sizearr[pu])
        {
            parent[pu] = pv;
            sizearr[pv] += sizearr[pu];
        }
        else
        {
            parent[pv] = pu;
            sizearr[pu] += sizearr[pv];
        }
        return 0;
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        priority_queue<ppi, vector<ppi>, greater<ppi>> q;
        vector<ppi> edges;
        for (int i = 0; i < n; i++)
        {
            for (auto j : adj[i])
            {
                edges.push_back({j[1], {i, j[0]}});
                q.push({j[1], {i, j[0]}});
            }
        }
        DisjointSet dsu = DisjointSet(n);
        vector<int> vis(n, 0);
        int ans = 0;
        while (!q.empty())
        {
            auto x = q.top();
            q.pop();
            if (dsu.unionBySize(x.ss.ff, x.ss.ss))
            {
                continue;
            }
            ans += x.ff;
        }
        return ans;
    }
};