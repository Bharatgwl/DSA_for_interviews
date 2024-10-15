#include <iostream>
#include <vector>
using namespace std;
int tour(vector<int> Pp, vector<int> Dd, int n)
{
    int balance = 0;
    int deficit = 0;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        balance += Pp[i] - Dd[i];
        if (balance < 0)
        {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }
    if (deficit + balance >= 0)
        return start;
    else
        return -1;
}
int main()
{
    vector<int> petrolpump = {4, 6, 7, 4};
    vector<int> distance = {6, 5, 3, 5};
    cout << tour(petrolpump, distance, petrolpump.size());
}