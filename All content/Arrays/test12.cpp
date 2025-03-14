#include <bits/stdc++.h>
using namespace std;

// Function to count the number of digits in n that evenly divide n
int evenlyDivides(int n)
{
    // code here
    int m = n;
    int count = 0;
    while (n > 0)
    {
        int digit = n / 10;
        if (m % digit == 0)
        {
            count++;
        }
        n=n/10;
    }
    return count;
}

int main(){
    int n=12;
    cout<< evenlyDivides(n);
}