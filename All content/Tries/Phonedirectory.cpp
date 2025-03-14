#include <iostream>
#include <vector>
using namespace std;
class Trienode
{
public:
    char data;
    Trienode *children[26];
    bool isTerminal;
    Trienode() {}
    Trienode(char ch)
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
public:
    Trienode *root;
    Trie()
    {
        root = new Trienode('\0');
    }
    void insertutil(Trienode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        Trienode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new Trienode(word[0]);
            root->children[index] = child;
        }
        insertutil(child, word.substr(1));
    }
    bool searchUtility(Trienode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        Trienode *child;
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
    bool searchword(string word)
    {
        return searchUtility(root, word);
    }
    void insertWord(string word)
    {
        insertutil(root, word);
    }
    void printsuggestion(Trienode *root, vector<string> &v, string prefix)
    {
        if (root->isTerminal)
        {
            v.push_back(prefix);
        }
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                prefix.push_back(i + 'a');
                printsuggestion(root->children[i], v, prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getsuggestions(string str)
    {
        Trienode *prev = root;

        vector<vector<string>> ans;

        string prefix = "";

        for (int i = 0; i < str.length(); i++)
        {

            char ch = str[i];

            prefix.push_back(ch);

            int index = ch - 'a';

            Trienode *curr = prev->children[index];

            if (curr == NULL)
            {
                break;
            }
            vector<string> temp;
            cout<<"called for "<<prefix<<" : ";
            printsuggestion(curr, temp, prefix);
            ans.push_back(temp);
            for(auto i:temp)
            {
                cout<<i<<" ";
            }
            temp.clear();
            prev = curr;
            cout<<endl;
        }
        return ans;
    }
    vector<vector<string>> phoneDirectory(vector<string> &phoneDirectory, string query)
    {

        return getsuggestions(query);
    }
};
int main()
{

    Trie *T1 = new Trie();
    vector<string> arr = {"apple", "ape", "app"};

    string query = "apple";

    for (int i = 0; i < arr.size(); i++)
    {
        T1->insertWord(arr[i]);
    }
    vector<vector<string>> ans = T1->phoneDirectory(arr, query);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}