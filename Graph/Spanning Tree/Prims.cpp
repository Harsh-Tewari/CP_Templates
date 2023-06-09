// finds MST
// TC-> ElogE

#include <bits/stdc++.h>
using namespace std;

#define ppi pair<int, pair<int, int>>
#define ff first
#define ss second
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        priority_queue<ppi, vector<ppi>, greater<ppi>> q;
        vector<int> vis(n, 0);
        vector<pair<int, int>> mst;
        q.push({0, {0, -1}});
        int ans = 0;
        while (!q.empty())
        {
            auto x = q.top();
            q.pop();
            if (vis[x.ss.ff])
                continue;
            vis[x.ss.ff] = 1;
            ans += x.ff;
            mst.push_back(x.ss);
            for (auto i : adj[x.ss.ff])
            {
                if (!vis[i[0]])
                {
                    q.push({i[1], {i[0], x.ss.ff}});
                }
            }
        }
        return ans;
    }
};