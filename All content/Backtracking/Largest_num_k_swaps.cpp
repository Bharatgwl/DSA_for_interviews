#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// This function attempts to find the largest lexicographical string possible
// by performing at most 'k' swaps on the input string 's'.
// 'ans' holds the current largest string found.
// 'start' indicates the current position in the string where swaps are considered.
void solve(string &s, int k, string &ans, int start)
{
    // Base condition: If no swaps are left or we are at the end of the string, return.
    if (k == 0 || start == s.size() - 1)
    {
        return;
    }

    // Find the maximum character from the current position to the end of the string.
    char max = s[start];
    int index = start;
    for (int i = start + 1; i < s.size(); i++)
    {
        if (s[i] > max)
        {
            max = s[i];
            index = i;
        }
    }

    // If the maximum character is different from the current character,
    // then perform a swap to bring the maximum character to the current position.
    if (max != s[start])
    {
        swap(s[start], s[index]); // Perform the swap.

        // Update 'ans' if the current string 's' is larger than 'ans'.
        if (s.compare(ans) > 0)
        {
            ans = s;
        }

        // Recursively solve for the next position with one less swap available.
        solve(s, k - 1, ans, start + 1);

        // Backtrack: Undo the swap to try other possibilities.
        swap(s[start], s[index]);
    }

    // Even if no swap was made, move to the next position to explore other possibilities.
    solve(s, k, ans, start + 1);
}
int main()
{
    string s = "122345";
    // string s = "4577";
    string ans = s;
    int k = 2;
    solve(s, k, ans, 0);
    cout << ans << endl;
}
