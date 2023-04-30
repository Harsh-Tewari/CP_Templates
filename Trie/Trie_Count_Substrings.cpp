#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *links[26];
    int count = 0;
};
class Trie
{
public:
    node *root;
    Trie()
    {
        root = new node();
    }

    void insert(string s)
    {
        node *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (temp->links[s[i] - 'a'] != NULL)
            {
                temp = temp->links[s[i] - 'a'];
            }
            else
            {
                temp->links[s[i] - 'a'] = new node();
                temp = temp->links[s[i] - 'a'];
            }
            temp->count++;
        }
    }

    int search(string s)
    {
        node *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (temp->links[s[i] - 'a'] != NULL)
            {
                temp = temp->links[s[i] - 'a'];
            }
            else
            {
                return false;
            }
        }
        return temp->count;
    }
};
void solve()
{
    Trie *t = new Trie();
    t->insert("harsh");
    t->insert("harish");
    t->insert("jay");
    t->insert("jari");
    t->insert("jarna");
    int k;
    cin >> k;
    while (k--)
    {
        string s;
        cin >> s;
        cout << t->search(s) << endl;
    }
}

int main()
{
    solve();
}