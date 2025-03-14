#include <iostream>
#include <unordered_map>
#include <Queue>
using namespace std;
//  unordered_map<char, int> mp;
string first_non_repeating_char(string S)
{
    unordered_map<char, int> count;
    queue<int> q1;
    string ans = "";
    for (int i = 0; i < S.length(); i++)
    {
        char ch = S[i];
        q1.push(ch);
        count[ch]++;
        while (!q1.empty())
        
        {
            if (count[q1.front()] > 1)
            {
                q1.pop();
            }
            else
            {
                ans.push_back(q1.front());
                break;
            }
        }
        if (q1.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}
int main()
{
    string S = "aabc";
    string ans = first_non_repeating_char(S);
    cout << ans << endl;
}