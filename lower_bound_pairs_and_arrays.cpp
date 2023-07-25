#include <bits/stdc++.h>
using namespace std;
int low_bnd(vector<vector<int>> &v, int &n, int val)
{
    int lo = 0, hi = n, ans = 0;
    if (val > v[n - 1][0])
        return n;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (v[mid][0] < val)
        {
            lo = mid + 1;
        }
        else
        {
            ans = mid;
            hi = mid - 1;
        }
    }
    return ans;
}