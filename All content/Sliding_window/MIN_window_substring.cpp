// Leetcode 76. Minimum Window Substring
// Hard
// Companies
// Hint
// Facebook
// Amazon
// LinkedIn
// Lyft
// Microsoft
// Given two strings s and t of lengths m and n respectively, return the minimum window
// substring
//  of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.

#include <bits/stdc++.h>
using namespace std;

string minWindow(std::string s, std::string t)
{
    if (s.empty() || t.empty() || s.length() < t.length())
    {
        return "";
    }

    std::vector<int> map(128, 0);
    int count = t.length();
    int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;
    for (char c : t)
    {
        map[c]++;
    }

    while (end < s.length())
    {
        if (map[s[end++]]-- > 0)
        {
            count--;
        }

        while (count == 0)
        {
            if (end - start < minLen)
            {
                startIndex = start;
                minLen = end - start;
            }

            if (map[s[start++]]++ == 0)
            {
                count++;
            }
        }
    }

    return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
}
int main()
{

    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindow(s, t) << endl;

    return 0;
}