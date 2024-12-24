#include <iostream>
#include <vector>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int countchild;
    TrieNode() {}
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        countchild = 0;
    }
};

class Trie
{
private:
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
            root->countchild++;
            root->children[index] = child;
        }
        insertutil(child, word.substr(1));
    }

public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertWord(string word)
    {
        insertutil(root, word);
    }
    void longest_common_prefix(vector<string> &arr, string word, string &ans)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            this->insertWord(arr[i]);
        }
        for (int i = 0; i < word.length(); i++)
        {
            if (root->countchild == 1)
            {
                ans.push_back(word[i]);
                root = root->children[word[i] - 'a'];
            }
            else
            {
                break;
            }
            if (root->isTerminal)
            {
                break;
            }
        }
    }
};
int main()
{
    Trie *t1 = new Trie();
    vector<string> arr{"hello", "hell", "helium"};

    string ans = "";
    t1->longest_common_prefix(arr, arr[0], ans);
    cout << ans;
}
