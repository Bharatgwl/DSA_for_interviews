#include <bits/stdc++.h>
using namespace std;
void div(int quo, vector<int> &rem)
{
    if (quo == 0)
    {
        return;
    }
    rem.push_back(quo % 3);
    quo = quo / 3;
    div(quo, rem);
}
bool checkPowersOfThree(int n)
{
    vector<int> rem;
    div(n, rem);
    long long ans = 0;
    int i = 0;
    for (int num : rem)
    {
        if (num == 0 || num == 1)
        {
            ans = ans + (pow(3, i) * num);
            i++;
        }
    }
    if (ans == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool checkpowersOfThree(int n)
{
    while (n > 0)
    {
        if (n % 3 == 2)
        {
            return false;
        }
        n /= 3;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    checkpowersOfThree(n) ? cout << "true" : cout << "false";
    checkPowersOfThree(n) ? cout << "true" : cout << "false";

    return 0;
}