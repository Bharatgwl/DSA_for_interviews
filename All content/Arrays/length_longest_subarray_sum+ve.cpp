#include <iostream>
#include <vector>
using namespace std;

int longestsubrraysum(vector<int> &arr, int k)
{
    int sum = 0;
    int max_len = 0;
    int start = 0;
    for (int end = 0; end < arr.size(); end++) 
    {
        sum += arr[end];
        while (sum > k && start <= end)
        {
            sum -= arr[start];
            start++;
        }
        if (sum == k)
        {
            max_len = max(max_len, end - start + 1);
        }
    }
    return max_len;
}

int main()
{
    vector<int> vec = {10, 5, 2, 7, 1,-10};
    int k = 15;
    cout << longestsubrraysum(vec, k);
}
