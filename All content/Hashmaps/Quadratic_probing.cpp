#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Read the size of the hash table from the user
    int k;
    cin >> k;

    // Initialize the collision counter to zero
    int collision = 0;

    // Read k elements from the user and store them in a vector
    vector<int> arr(k);
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }

    // Initialize the hash table with -1's
    vector<int> ans(k, -1);

    // Iterate over the elements of the array and insert them into the hash table using quadratic probing
    for (int i : arr)
    {
        // Calculate the remainder of the element modulo the size of the hash table
        int rem = i % k;

        // Initialize the index to the remainder
        int m = rem;

        // Initialize the square value to 1
        int sq = 1;

        // Keep probing until an empty slot is found
        while (ans[m] != -1)
        {
            // Increment the collision counter
            collision++;

            // Calculate the next index using the quadratic probing formula
            m = (rem + sq * sq) % k;

            // Increment the square value
            sq++;
        }

        // Insert the element into the hash table
        ans[m] = i;
    }

    // Print the contents of the hash table
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    // Print the total number of collisions that occurred during insertion
    cout << "collisions: " << collision << endl;

    return 0;
}
