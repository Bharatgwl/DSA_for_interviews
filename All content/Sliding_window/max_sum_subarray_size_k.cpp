#include <iostream>
#include <vector>
using namespace std;
int max_sum_subarray(vector<int> v, int k)
{
    int sum = 0;
    int max_sum = 0;
    int i = 0;
    int j = 0;
    while (j < v.size())
    {
        sum += v[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            max_sum = max(max_sum, sum);
            sum -= v[i];
            i++;
            j++;
        }
    }
    return max_sum;
}
int main()
{
    vector<int> v = {2, 5, 1, 8, 2, 9, 1};
    int k = 3;
    cout << max_sum_subarray(v, k);
}
