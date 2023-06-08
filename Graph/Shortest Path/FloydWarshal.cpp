// multisource multipoint shortest path
// similar to routing tables
// directed Graphs
// detects -ve cycle
// use adj matrix
// complexity -> V*V*V

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &v)
    {
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][j] == -1)
                    v[i][j] = 1e9;
            }
        }
        for (int k = 0; k < n; k++) // through each node
        {
            for (int i = 0; i < n; i++) // from each edge i
            {
                for (int j = 0; j < n; j++) // to each edge j
                {
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][j] == 1e9)
                    v[i][j] = -1;
            }
        }
    }
};