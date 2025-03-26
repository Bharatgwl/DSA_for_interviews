#include <bits/stdc++.h>
using namespace std;
int climbStairs(int n, int i)
{
    if (i == n)
    {
        return 1;
    }
    if (i > n)
    {
        return 0;
    }
    return (climbStairs(n, i + 1) + climbStairs(n, i + 2));
}
int main()
{
    int stairs = 5;
    cout << climbStairs(stairs, 0);

    return 0;
}