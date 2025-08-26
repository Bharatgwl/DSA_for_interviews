#include <bits/stdc++.h>
using namespace std;
bool solve(vector<double> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return abs(nums[0] - 24) <= 1e-6;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                vector<double> next_nums;
                for (int k = 0; k < n; k++)
                {
                    if (k != i && k != j)
                    {
                        next_nums.push_back(nums[k]);
                    }
                }
                double a = nums[i];
                double b = nums[j];

                vector<double> operations = {a + b, a - b, b - a, a * b};
                if (b != 0)
                    operations.push_back(a / b);
                if (a != 0)
                    operations.push_back(b / a);
                for (double op : operations)
                {
                    next_nums.push_back(op); // a or b ka jo bhi operation hua uska result
                    if (solve(next_nums))
                    {
                        return true; // agar wo result 24 ke barabar hai toh return true hojayega
                    }
                    next_nums.pop_back(); // last operation ka result hata do or dusre operation try karo
                }
            }
        }
    }
    return false; // agar koi bhi combination 24 ke barabar nahi mila toh return false
}
int main()
{
    vector<int> arr = {8, 1, 4, 7};
    vector<double> nums;
    for (int i : arr)
    {
        nums.push_back(1.0 * i);
    }
    return solve(nums);

    return 0;
}