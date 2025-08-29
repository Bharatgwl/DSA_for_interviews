#include <bits/stdc++.h>
using namespace std;
int pow(int x, int n)
{
    if (n == 0)
        return 1;

    if (n % 2)
    {
        return x * pow(x, n - 1);
    }
    else
    {
        int half = pow(x, n / 2);
        return half * half;
    }
}

int iter(int x, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = res * x;
            n--;
        }
        else
        {
            x = x * x;
            n = n / 2;
        }
    }
    return res;
}
int main()
{
    int x = 2, n = 11;
    cout << pow(x, n) << endl;
    cout << iter(x, n) << endl;

    return 0;
}