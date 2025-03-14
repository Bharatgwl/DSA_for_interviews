#include <iostream>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode() {}
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
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
            root->isTerminal = true;
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


    bool searchUtility(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index])
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return searchUtility(child, word.substr(1));
    }
    void removeutil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index])
        {
            child = root->children[index];
            removeutil(child, word.substr(1));
        }
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertWord(string word)
    {
        insertutil(root, word);
    }
    bool searchword(string word)
    {
        return searchUtility(root, word);
    }
    void remove(string word)
    {
        removeutil(root, word);
    }
};

int main()
{
    Trie *T1 = new Trie();
    T1->insertWord("bharat");
    cout << T1->searchword("bharat");
    T1->remove("bharat");
    cout << T1->searchword("bharat");

    // T1->insertWord("harsh");
    // cout << T1->searchword("harsh");
    // T1->remove("harsh");
    // cout << T1->searchword("harsh");
}
