#include <bits/stdc++.h>
using namespace std;

string S;
int K;
int solve(int i, long long uniquechars, bool canchange)
{
    if (i >= S.length())
        return 0;    int ans = 0;
    int charindex = S[i] - 'a';
    int    if (uniquecharcount > K)
    {
        ans = 1 + solve(i + 1, (1 << charindex), canchange);    else
    {
        ans = solve(i + 1, newuniquechars, canchange);
    }
    if (canchange)
    {
        {
            int newcharset = (uniquechars | (1 << newchar)); // change current char to newchar
            if (newuniquecharcount > K)
            {            }
            else
            {
                ans = max(ans, solve(i + 1, newcharset, false));
            }
        }
    }
    return ans;
}
int maxpartition(string s, int k, int mask)
{
    S = s;
    K = k;
    return solve(0, 0, true);
}
int main()
{    return 0;
}