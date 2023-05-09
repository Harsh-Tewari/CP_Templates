#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[n + 1];
    for (auto &i : edges)
    {
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> distance(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    distance[1] = 0;
    parent[1] = 1;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        for (auto &it : adj[node])
        {
            int v = it.first;
            int edgewt = it.second;
            if (distance[v] > d + edgewt)
            {
                parent[v] = node;
                distance[v] = d + edgewt;
                pq.push({distance[v], v});
            }
        }
    }
    vector<int> ans;
    if (distance[n] == INT_MAX)
        return {-1};
    int i = n;
    while (parent[i] != i)
    {
        ans.push_back(i);
        i = parent[i];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    return ans;
}