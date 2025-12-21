#include <bits/stdc++.h>
using namespace std;

int solve(int i, int uniquechar, string &s, int k, bool canchange)
{
    if (i >= s.length())
        return 0;

    int charIdx = s[i] - 'a';                                         // yaha pe character ka index nikal liya
    int updatedUniqueCharcount = 1 << charIdx | uniquechar;           // usme integer me current character ko bhi add kar diya
    int uniqueCharCount = __builtin_popcount(updatedUniqueCharcount); // us integer me kitne bits set hai wo nikal liya usse unique character count mil jayega
    int ans = 0;
    if (uniqueCharCount > k) // agar unique character count k se jada ho gaya to ek partition bana ke aage badh jao
    {
        ans = 1 + solve(i + 1, 1 << charIdx, s, k, canchange); // 1<<charIdx se ek naya integer bana ke usme sirf current character hi add kar diya
    }
    else
    {
        ans = solve(i + 1, updatedUniqueCharcount, s, k, canchange); // nahi to aise hi aage badh jao
    }
    if (canchange)
    {
        for (int ch = 0; ch < 26; ch++)
        {
            if (ch == charIdx) // same character pe change nahi karna hai
            {
                continue;
            }
            int newset = 1 << ch | uniquechar;                   // current character ko change karke naya character add kar diya
            int newUniqueCharCount = __builtin_popcount(newset); // naya unique character count nikal liya
            if (newUniqueCharCount > k)                          // agar wo bhi k se jada ho gaya to ek partition bana ke aage badh jao
            {
                ans = max(ans, 1 + solve(i + 1, 1 << ch, s, k, false)); // ab aage change nahi kar sakte
            }
            else
            {
                ans = max(ans, solve(i + 1, newset, s, k, false)); // nahi to aise hi aage badh jao
            }
        }
        return ans;
    }
}
unordered_map<long long, int> memo;
int solveDP(int i, int uniquechar, string &s, int k, bool canchange) // yaha pe 3 parameters ko combine karke ek long long bana ke memo me store karenge
{
    if (i >= s.length())
        return 0;
    int key = ((long long)i << 32) | ((long long)uniquechar << 1) | (canchange ? 1 : 0); // i ko left shift karke uniquechar ko add kar diya fir usme canchange ko bhi add kar diya
    if (memo.find(key) != memo.end())
    {
        return memo[key];   
    }
    int charIdx = s[i] - 'a';                                         // yaha pe character ka index nikal liya
    int updatedUniqueCharcount = 1 << charIdx | uniquechar;           // usme integer me current character ko bhi add kar diya
    int uniqueCharCount = __builtin_popcountll(updatedUniqueCharcount); // us integer me kitne bits set hai wo nikal liya usse unique character count mil jayega
    int ans = 0;
    if (uniqueCharCount > k) // agar unique character count k se jada ho gaya to ek partition bana ke aage badh jao
    {
        ans = 1 + solve(i + 1, 1 << charIdx, s, k, canchange); // 1<<charIdx se ek naya integer bana ke usme sirf current character hi add kar diya
    }
    else
    {
        ans = solve(i + 1, updatedUniqueCharcount, s, k, canchange); // nahi to aise hi aage badh jao
    }
    if (canchange)
    {
        for (int ch = 0; ch < 26; ch++)
        {
            if (ch == charIdx) // same character pe change nahi karna hai
            {
                continue;
            }
            int newset = 1 << ch | uniquechar;                   // current character ko change karke naya character add kar diya
            int newUniqueCharCount = __builtin_popcountll(newset); // naya unique character count nikal liya
            if (newUniqueCharCount > k)                          // agar wo bhi k se jada ho gaya to ek partition bana ke aage badh jao
            {
                ans = max(ans, 1 + solve(i + 1, 1 << ch, s, k, false)); // ab aage change nahi kar sakte
            }
            else
            {
                ans = max(ans, solve(i + 1, newset, s, k, false)); // nahi to aise hi aage badh jao
            }
        }
        return memo[key] = ans;
    }
}
int maxPartition(string s, int k)
{
    return solve(0, 0, s, k, true) + 1;  // initially koi partition nahi bana hai to 1 add kar denge
}
int main()
{

    string s;
    int k;

    return 0;
}