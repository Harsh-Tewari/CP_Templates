// Used to do range queries e.g. sum in [l,r] in O(sqrt(n))
// We precompute the steps in blocks of size sqrt(n)
// Complexity O(n)--->O(sqrt(n))
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // taking array input
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int block_len = sqrt(n) + 1;
    vector<int> block(block_len, 0);
    // putting sum in blocks
    for (int i = 0; i < n; i++)
    {
        block[i / block_len] += v[i];
    }

    // Answering queries
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int sum = 0;
        for (int i = l; i <= r;)
        {
            if (i % block_len == 0 && i + block_len - 1 <= r)
            {
                sum += block[i / block_len];
                i += block_len;
            }
            else
            {
                sum += v[i];
                i++;
            }
        }
        cout << sum << endl;
    }
}
signed main()
{
    solve();
    return 0;
}