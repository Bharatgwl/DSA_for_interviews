
#include <bits/stdc++.h>
using namespace std;
int countprimes(int n)
{
    if (n < 2)
    return 0;
    
    vector<bool> prime(n + 1, true);  // n+1 to include 'n'
    prime[0] = prime[1] = false;
    
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }
    
    // Count manually without STL
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        count++;
    }
    
    return count;
}

int main(){

    int n=6;
    cout<<"Number of primes less than or equal to "<<n<<" is: "<<countprimes(n)<<endl;
    
return 0;
}