#include <bits/stdc++.h>
using namespace std;

void sieve(vector<bool> &prime)
{
    int n = prime.size();
    prime[0] = prime[1] = false; // 0 and 1 are not prime

    for (int p = 2; p * p < n; p++) // Fixed condition
    {
        if (prime[p])
        {
            for (int i = p * p; i < n; i += p) // Fixed range
            {
                prime[i] = false;
            }
        }
    }
}

int main()
{
    int left = 4, right = 6;
    vector<bool> sieveArray(right + 1, true);
    sieve(sieveArray);

    vector<int> primes;
    for (int i = left; i <= right; i++)
    {
        if (sieveArray[i])
        {
            primes.push_back(i);
        }
    }

    for (int p : primes)
    {
        cout << p << " ";
    }
    cout << endl;

    if (primes.size() < 2)
    {
        cout << "No prime pair found";
        return 0;
    }
    pair<int, int> ans;
    if (primes[0] && primes[1])
        ans = {primes[0], primes[1]};
    else
    {
        ans = {-1, -1};
    }
    int minDiff = ans.second - ans.first;

    for (int i = 1; i < primes.size(); i++)
    {
        if (primes[i] - primes[i - 1] < minDiff)
        {
            ans = {primes[i - 1], primes[i]};
            minDiff = ans.second - ans.first;
        }
    }

    cout << ans.first << " " << ans.second;
    return 0;
}
