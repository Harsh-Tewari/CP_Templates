//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void toposort(int node, vector<pair<int, int>> adj[], stack<int> &st, vector<int> &vis)
    {
        vis[node] = 1;
        for (auto &i : adj[node])
        {
            if (!vis[i.first])
            {
                toposort(i.first, adj, st, vis);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[n];
        for (auto &i : edges)
        {
            adj[i[0]].push_back({i[1], i[2]});
        }

        vector<int> dist(n, 1e9), vis(n, 0);
        dist[0] = 0; // because source is 0
        stack<int> st;

        // finding toposort
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                toposort(i, adj, st, vis);
            }
        }

        // updating distances
        while (!st.empty())
        {
            int node = st.top();
            for (auto &i : adj[node])
            {
                int v = i.first;
                int w = i.second;
                if (dist[v] > dist[node] + w)
                {
                    dist[v] = dist[node] + w;
                }
            }
            if (dist[node] == 1e9)
                dist[node] = -1;
            st.pop();
        }
        return dist;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends