#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// This program checks for pairs of elements in the vector 'a' whose sum is also present in the same vector.

int main()
{
    // Initialize the vector 'a' with the given elements.
    vector<int> a = {1, 5, 3, 9, 4};
    
    // Get the size of the vector 'a'.
    int n = a.size();

    // Iterate over each element in the vector 'a' using the outer loop.
    for (int i = 0; i < n; i++)
    {
        // For each element 'a[i]', iterate over the subsequent elements using the inner loop.
        for (int j = i; j < n; j++)
        {
            // Calculate the sum of the current pair of elements 'a[i]' and 'a[j]'.
            int sum = a[i] + a[j];

            // Check if the calculated sum is present in the vector 'a'.
            auto it = find(a.begin(), a.end(), sum);

            // If the sum is found in the vector 'a', output the pair of elements.
            if (it != a.end())
            {
                cout << a[i] << " " << a[j] << endl;
            }
            // Note: There is no else condition here, so if the sum is not found, nothing is printed.
        }
    }
}
