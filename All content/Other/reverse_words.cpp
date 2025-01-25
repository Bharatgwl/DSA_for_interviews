#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string reverse_words(string s)
{
    int left = 0;
    int right = 0;
    int i = 0;
    reverse(s.begin(), s.end());
    while (i < s.size())
    {
        while (i < s.size() && s[i] == ' ')
        {
            i++;
        }
        if (i == s.size())
        {
            break;
        }
        while (i < s.size() && s[i] != ' ')
        {
            s[right++] = s[i++];
        }
        reverse(s.begin() + left, s.begin() + right);
        s[right++] = ' ';
        left = right;
        i++;
    }
    s.resize(right - 1);
    return s;
}
int main()
{
    string s = "a good   example";
    cout << reverse_words(s);
}
