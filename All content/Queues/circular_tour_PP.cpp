#include <iostream>
#include <vector>
using namespace std;
/**
 * @brief Checks if a circular tour of petrol pumps is possible or not.
 *
 * @param Pp A vector of integers representing the amount of petrol at each pump.
 * @param Dd A vector of integers representing the distance from each pump to the next one.
 * @param n The number of petrol pumps.
 *
 * @return The index of the pump from which the circular tour can start. If no such
 *         pump exists, it returns -1.
 *
 * @details
 *      This function works by maintaining a balance of petrol which is the total
 *      amount of petrol at each pump minus the total distance from each pump to
 *      the next one. If the balance drops below zero, it means that we have
 *      reached a point where the total amount of petrol is not enough to cover the
 *      total distance from the current pump to the starting pump. In this case, we
 *      start again from the next pump and reset the balance to 0. We keep track of
 *      the total deficit which is the total amount of petrol that we need to
 *      compensate for the distance. If the total deficit plus the current balance
 *      is greater than or equal to 0, we can start a circular tour from the
 *      current pump and return the index of that pump. If the total deficit plus
 *      the current balance is less than 0, we return -1 indicating that no such
 *      pump exists.
 */
int tour(vector<int> Pp, vector<int> Dd, int n)
{
    int balance = 0;
    int deficit = 0;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        balance += Pp[i] - Dd[i];

        // If the balance drops below zero, it means that we have reached a point
        // where the total amount of petrol is not enough to cover the total
        // distance from the current pump to the starting pump. In this case, we
        // start again from the next pump and reset the balance to 0. We also
        // add the current balance to the total deficit.
        if (balance < 0)
        {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }

    // If the total deficit plus the current balance is greater than or equal to 0,
    // we can start a circular tour from the current pump and return the index of
    // that pump. If the total deficit plus the current balance is less than 0, we
    // return -1 indicating that no such pump exists.
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