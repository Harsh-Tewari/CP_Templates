#include <bits/stdc++.h>
using namespace std;

// Sum Update

class fenwick_tree
{
private:
    vector<int> fen;
    int n;

public:
    fenwick_tree(int n)
    {
        fen.resize(n + 1, 0);
        this->n = n;
    }

    void update(int i, int add)
    {
        while (i < n)
        {
            fen[i] += add;
            i = i + (i & (-i));
        }
    }

    int sum(int i)
    {
        int ans = 0;
        while (i > 0)
        {
            ans += fen[i];
            i -= (i & (-i));
        }
        return ans;
    }

    int range_sum(int l, int r)
    {
        return sum(r) - sum(l);
    }
};