#include <iostream>
using namespace std;

class trienode
{
public:
    char data;
    trienode *children[26];
    bool isterminal;
    trienode() {}
    trienode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isterminal = false;
    }
};

class Trie
{
public:
    trienode *root;
    Trie()
    {
        root = new trienode('\0');
    }
    void insertutil(trienode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isterminal = true;
            return;
        }
        int index = word[0] - 'a';
        trienode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new trienode(word[0]);
            root->children[index] = child;
        }
        insertutil(child, word.substr(1));
    }

    bool prefixutil(trienode *root, string prefix)
    {
        if (prefix.length() == 0)
        {
            return true;
        }
        trienode *child;
        int index = prefix[0] - 'a';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return prefixutil(child, prefix.substr(1));
    }
    void insert(string word)
    {
        insertutil(root, word);
    }
    bool prefix(string prefix)
    {
        return prefixutil(root, prefix);
    }
};
int main()
{
    Trie *t1 = new Trie();
    t1->insert("bharat");
    cout << t1->prefix("bha");
}