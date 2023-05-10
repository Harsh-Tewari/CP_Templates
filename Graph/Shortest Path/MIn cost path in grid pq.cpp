#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ff first
#define ss second
class Solution
{
public:
    // path mein jo bhi max element hoga uska jitna hi time lagega uska max ka min
    // yeh formula me change karke dist ke hisaab se bhi
    // algorithm bana sakte hain yeh waali grid pe lagane ke liye
    int swimInWater(vector<vector<int>> &v)
    {
        pii src = {0, 0};
        int n = v.size(), m = v[0].size();
        if (v[0][0] == 1)
            return -1;
        pii dest = {n - 1, n - 1};
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[src.ff][src.ss] = v[0][0];
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
        pq.push({v[0][0], src});
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        while (!pq.empty())
        {
            auto cell = pq.top().ss;
            auto d = max(pq.top().ff, v[cell.ff][cell.ss]);
            pq.pop();
            for (int i = 0; i < 4; i++)
            {
                int r = cell.ff + dr[i];
                int c = cell.ss + dc[i];
                if (r >= n || r < 0 || c >= m || c < 0)
                    continue;
                pii t = {r, c};
                if (dist[r][c] > max(d, v[r][c]))
                {
                    dist[r][c] = max(d, v[r][c]);
                    pq.push({max(d, v[r][c]), t});
                }
            }
        }
        if (dist[dest.ff][dest.ss] == INT_MAX)
            return -1;
        return dist[dest.ff][dest.ss];
    }
};