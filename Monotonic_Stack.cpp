#include <bits/stdc++.h>
using namespace std;

// Standard technique to find next greater element for every index
vector<int> nextGreaterElements(vector<int> &v)
{
    int n = v.size();
    vector<int> ans(n, -1);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && v[s.top()] < v[i])
        {
            ans[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }
    return ans;
}