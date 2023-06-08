// complexity -> Elog(V)

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
vector<int> dijkstra(int n, vector<pair<int, int>> adj[], int src)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> distance(n, INT_MAX);
    distance[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int nodeVal = pq.top().first;
        pq.pop();
        for (auto &it : adj[node])
        {
            int edgeWt = it.second;
            int v = it.first;
            if (distance[v] > nodeVal + edgeWt)
            {
                distance[v] = nodeVal + edgeWt;
                pq.push({distance[v], v});
            }
        }
    }
    return distance;
}