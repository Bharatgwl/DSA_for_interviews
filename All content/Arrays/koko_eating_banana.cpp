#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int max_element(vector<int> arr)
{
    int maxi = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }
    return maxi;
}
/**
 * @brief Calculates the total time it takes for Koko the monkey to eat all the
 *        bananas in the given pile if she eats at a rate of 'mid' bananas per
 *        hour.
 *
 * @param arr The vector of integers representing the number of bananas in each
 *            pile.
 * @param mid The number of bananas Koko eats per hour.
 * @return The total time it takes for Koko to eat all the bananas.
 */
int calc(vector<int> arr, int mid)
{
    int time = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        time += ceil(arr[i] / double(mid));
    }
    return time;
}
/**
 * @brief This function uses a binary search approach to find the optimal number of bananas
 *        per hour that Koko can eat such that she finishes eating all the bananas in the given
 *        time 'h' hours.
 *
 * @param arr The vector of integers representing the number of bananas in each pile.
 * @param h The total time in which Koko should finish eating all the bananas.
 * @return The minimum number of bananas per hour that Koko can eat to finish all the bananas in the given time.
 */
int koko_eating_banana(vector<int> arr, int h)
{
    // The start index of the binary search range is 0
    int s = 1;
    // The end index of the binary search range is the maximum number of bananas in any pile
    int e = max_element(arr);
    // Continue the binary search until the start index is greater than the end index
    while (s <= e)
    {
        // Calculate the mid index of the binary search range mid is the number of bananas Koko eats per hour
        int mid = s + (e - s) / 2;
        // Calculate the total time it takes for Koko to eat all the bananas at the current rate
        int totaltime = calc(arr, mid);
        // If the total time is less than or equal to the given time, then we can eat faster
        if (totaltime <= h)
        {
            // If Koko can finish eating all the bananas in less than or equal to 'h' hours,
            // it means she can afford to eat slower. Hence, we try to find a smaller rate
            // by reducing the end of the range to mid-1.
            e = mid - 1;
        }
        else
        {
            // If Koko needs more than 'h' hours to finish all the bananas at the current rate,
            // it means she needs to eat faster. Therefore, we increase the start of the range to mid+1.
            s = mid + 1;
        }
    }
    // Finally, we return the start index of the range which is the minimum number of bananas per hour
    // that Koko can eat to finish all the bananas in the given time
    return s;
}
int main()
{
    vector<int> arr = {312884470};
    int h = 968709470;
    cout << koko_eating_banana(arr, h);
}
