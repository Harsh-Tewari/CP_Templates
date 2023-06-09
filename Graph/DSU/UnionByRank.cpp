#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
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
        while (x != parent[x])
        {
            x = parent[x];
        }
        return x;
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

    void unionBySize(int u, int v)
    {
        int pu, pv;
        pu = findUParent(u);
        pv = findUParent(v);
        if (pu == pv)
        {
            return;
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
    }
};
