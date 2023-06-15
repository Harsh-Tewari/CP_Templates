// Stores each no. in form of 32 bits
// bits can be changed by changing the no.
// xorMax can give us max xor with a no. form the array inserted in a trie with the target no.
// for each bit of the target check if the opposite bit exists in trie at that index

#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *links[2];
    bool ending = false;
};
class Trie
{
public:
    node *root;
    Trie()
    {
        root = new node();
    }

    void insert(int s)
    {
        node *temp = root;
        int x;
        for (int i = 31; i >= 0; i--)
        {
            x = ((s >> i) & 1);
            if (temp->links[x] != NULL)
            {
                temp = temp->links[x];
            }
            else
            {
                temp->links[x] = new node();
                temp = temp->links[x];
            }
        }
        temp->ending = true;
    }

    int xorMax(int num)
    {
        node *temp = root;
        int x;
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            x = ((num >> i) & 1);
            if (temp->links[1 - x] != NULL)
            {
                temp = temp->links[1 - x];
                ans += (1 << i);
            }
            else
            {
                temp = temp->links[x];
            }
        }
        return ans;
    }
};