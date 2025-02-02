#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int count_occurence(string s, unordered_map<char, int> mp,string sample)
{
    int count = mp.size();
    int i = 0, j = 0;
    int ans = 0;
    while (j < s.length())
    {
        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
            {
                count--;
            }
        }
        if (count == 0)
        {
            ans++;
        }
        if (j - i + 1 < sample.length())
        {
            j++;
        }
        else
        {
            if (mp.find(s[i]) != mp.end())
            {
                mp[s[i]]++;
                if (mp[s[i]] == 1)
                {
                    count++;
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    string s = "foaxxorfxaofr";
    string sample = "for";
    unordered_map<char, int> mp;
    for (auto i : sample)
    {
        mp[i]++;
    }
    cout << count_occurence(s, mp,sample) << endl;
    
}