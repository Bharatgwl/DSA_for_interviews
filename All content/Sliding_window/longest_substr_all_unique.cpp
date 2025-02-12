#include <iostream>
#include <map>
using namespace std;
int longestSubstring(string s)
{
    int i = 0, j = 0;
    map<char, int> mp;
    int ans = 0;
    while (j < s.length())
    {
        mp[s[j]]++;
        if (j - i + 1 > mp.size())
        {
            while (j - i + 1 > mp.size())
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0) // if the frequency of the character becomes 0 then remove it from the map
                {
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}
int main()
{
    string s = "pwwkew";
    
    cout << longestSubstring(s);
    return 0;
}