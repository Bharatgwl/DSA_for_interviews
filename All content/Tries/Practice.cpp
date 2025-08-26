#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isterminal;
    TrieNode() {};
    TrieNode(char ch)
    {
        ch = data;
        for (int i = 0; i <= 26; i++)
        {
            children[i] = NULL;
            isterminal = false;
        }
    }
};
class Trie
{
private:
    TrieNode *root;
    void insertutil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isterminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index])
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertutil(child, word.substr(1));
    }
    bool searchutil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isterminal;
        }
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index])
        {
            child = root->children[index];
        }
        else
        {
            return false; // iska matlb ye wala current word nahi mila or yaha pe word aadha hi h
        }
        return searchutil(child, word.substr(1));
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insert(string word)
    {
        insertutil(root, word);
    }
    bool search(string word)
    {
        return searchutil(root, word);
    }
};

int main()
{

    Trie *t1 = new Trie();
    t1->insert("bharat");
    if (t1->search("bharat"))
    {
        cout << "found";
    }
    else
    {
        cout << "not found";
    }

    return 0;
}