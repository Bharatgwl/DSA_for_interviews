
#include <bits/stdc++.h>
using namespace std;
int numOfSubarrays(vector<int> &arr)
{
    long long oddCount = 0, prefixSum = 0;
    for (int a : arr)
    {
        prefixSum += a;
        oddCount += prefixSum % 2;
    }
    cout<<oddCount<<endl;
    oddCount += (arr.size() - oddCount) * oddCount;
    return oddCount;
    return oddCount % 1'000'000'007;
}
int main()
{
    vector<int> arr = {1, 3, 5};
    cout << numOfSubarrays(arr) << endl;

    return 0;
}