#include <iostream>
#include <vector>
using namespace std;
/**
 * Determines if it is possible to allocate books such that no student reads more than 'mid' pages.
 *
 * This function takes an array where each element represents the number of pages in a book, the total
 * number of books, the number of students, and the maximum allowable number of pages a student can read.
 * It checks if it is feasible to assign books to students such that no student is assigned more than 'mid' pages.
 *
 * @param arr A vector of integers where each integer represents the number of pages in a book.
 * @param size The total number of books.
 * @param m The total number of students.
 * @param mid The maximum number of pages a student can read.
 * @return Returns true if the books can be allocated such that no student reads more than 'mid' pages, otherwise false.
 */
bool ispossible(vector<int> arr, int size, int m, int mid)
{
    int stdcount = 1;
    int pagesum = 0;
    for (int i = 0; i < size; i++)
    {
        if (pagesum + arr[i] > mid)
        {
            stdcount++;
            pagesum = arr[i];
            if (stdcount > m || arr[i] > mid)
            {
                return false;
            }
        }
        else
        {
            pagesum += arr[i];
        }
    }
    // return stdcount < m ? false : true;
    cout << stdcount << endl;
    if (stdcount <= m)
    {
        return false;
    }
    return true;
}
/**
 * Allocates books to students such that the maximum number of pages assigned to a student is minimized.
 *
 * This function uses a binary search approach to find the optimal solution to allocate books among students.
 * It takes an array where each element represents the number of pages in a book. The function calculates
 * the minimum number of pages that can be allocated to a student such that no student has more pages than this minimum.
 *
 * @param arr A vector of integers where each integer represents the number of pages in a book.
 * @param size The total number of books.
 * @param m The total number of students.
 * @return The minimum number of pages that can be allocated to a student such that no student reads more than this number.
 */
int allocatebooks(vector<int> arr, int size, int m)
{
    int s = 0;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (ispossible(arr, size, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
/**
 * The main function initializes a vector of integers representing the number of pages in different books.
 * It calculates the size of the vector and assigns the number of students.
 * Then, it calls the allocatebooks function to determine the minimum number of pages that can be allocated
 * to each student such that no student has more pages than this minimum.
 * Finally, it prints the result.
 */
int main()
{
    vector<int> nums = {12, 34, 67, 90};

    vector<int> nums = {2, 8, 8, 4, 5};
    vector<int> nums = {25, 46 ,28 ,49 ,24};
    int n = nums.size();
    int m = 4;
    int answers = allocatebooks(nums, n, m);
    cout << answers << endl;
    return 0;
}