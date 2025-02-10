#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void permute(string s, string temp, vector<string> &ans)
{
    if (s.empty())
    {
        ans.push_back(temp);
        return;
    }

    unordered_set<char> us; 

    for (int i = 0; i < s.size(); i++)
    {
        if (us.find(s[i]) == us.end()) 
        {
            us.insert(s[i]); 
            
            string newtemp = temp + s[i];
            string news = s.substr(0, i) + s.substr(i + 1);
            
            permute(news, newtemp, ans);
        }
    }
}

int main()
{
    string s = "aab";
    vector<string> ans;
    string temp = "";
    
    permute(s, temp, ans);

    for (auto &i : ans)
    {
        cout << i << endl;
    }
}
