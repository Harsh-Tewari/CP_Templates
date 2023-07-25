#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *links[2];
    int count[2] = {0, 0};
};

class Trie
{
    node *head;

public:
    Trie()
    {
        head = new node();
    }

    void insert(int x)
    {
        node *temp = head;
        for (int i = 31; i >= 0; i--)
        {
            int idx = ((x >> i) & 1);
            temp->count[idx]++;
            if (!temp->links[idx])
            {
                temp->links[idx] = new node();
            }
            temp = temp->links[idx];
        }
    }

    void remove(int x)
    {
        node *temp = head;
        for (int i = 31; i >= 0; i--)
        {
            int idx = ((x >> i) & 1);
            temp->count[idx]--;
            if (temp->count[idx] == 0)
            {
                delete temp->links[idx];
                temp->links[idx] = NULL;
                return;
            }
            temp = temp->links[idx];
        }
    }

    int maxXor(int x)
    {
        node *temp = head;
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int idx = 1 - ((x >> i) & 1);
            if (!temp->links[idx])
            {
                temp = temp->links[1 - idx];
            }
            else
            {
                ans += (1 << i);
                temp = temp->links[idx];
            }
        }
        return ans;
    }

    int minXorWithElementDeletion(int x)
    {
        node *temp = head;
        int ans = 0;
        int rem = 0;
        for (int i = 31; i >= 0; i--)
        {
            int idx = ((x >> i) & 1);
            if (!temp->links[idx])
            {
                ans += (1 << i);
                if (1 - idx)
                    rem += ((1 << i));
                temp = temp->links[1 - idx];
            }
            else
            {
                if (idx)
                    rem += ((1 << i));
                temp = temp->links[idx];
            }
        }
        this->remove(rem);
        return ans;
    }
};