#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
/**
 * @brief A program that prints the next permutation of the array {1,2,3}
 *
 * This program demonstrates the use of the next_permutation algorithm
 * to find the next permutation of an array of integers.
 *
 * @return 0 if the program executes successfully
 */
int main()
{
    int a[3] = {1, 2, 3};
    next_permutation(a, a + 3);
    cout << a[0] << " " << a[1] << " " << a[2];

    return 0;
}