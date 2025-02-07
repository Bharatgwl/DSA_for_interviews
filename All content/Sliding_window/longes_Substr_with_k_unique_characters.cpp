#include <iostream>
#include <map>
using namespace std;
int longestSubstring(string s, int k)
{
    int i = 0, j = 0;
    map<char, int> mp;
    int ans = 0;
    while (j < s.length())
    {
        mp[s[j]]++;
        if (mp.size() > k)
        {
            while (mp.size() > k)
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
    string s = "aabacbebebe";
    int k = 3;
    cout << longestSubstring(s, k);
    return 0;
}