#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Linear probing example
 *
 * This program reads an integer from standard input, reads that many more integers, and
 * then attempts to insert them into a hash table using linear probing. If a collision
 * occurs, the program increments the collision counter and continues to the next
 * available slot.
 *
 * After all the elements have been inserted into the hash table, the program prints
 * out the contents of the hash table, followed by the number of collisions that
 * occurred during insertion.
 */
int main()
{
    int collision = 0; // Counts the number of collisions that occurred during insertion
    int k;
    cin >> k;
    if (k <= 0)
    {
        cout << "Invalid input" << endl; // User entered an invalid size for the hash table
        return 1;
    }

    vector<int> arr(k); // Read in k elements from the user
    vector<int> ans(k, -1); // Initialize the hash table with -1's
    for (int i = 0; i < k; i++)
    {
        int d;
        cin >> d;
        if (d < 0)
        {
            cout << "Invalid input" << endl; // User entered a negative number
            return 1;
        }
        arr[i] = d;
    }

    // Insert elements from the array into the hash table using linear probing
    for (auto i : arr)
    {
        int rem = i % k; // Calculate the remainder of the element modulo the size of the hash table
        int m = rem;
        while (ans[m] != -1)
        {
            m = (m + 1) % k; // Move to the next available slot in the hash table
            collision++; // Increment the collision counter
        }
        ans[m] = i;
    }

    // Print out the contents of the hash table
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    // Print out the number of collisions that occurred during insertion
    cout << "collisions: " << collision << endl;
    return 0;
}
//12
// 44 23 6 91 45 48 42 79 71 13 26 28 