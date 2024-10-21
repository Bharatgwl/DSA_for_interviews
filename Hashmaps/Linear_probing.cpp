#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int collision=0;
    int k;
    cin >> k;
    vector<int> arr(k);
    vector<int> ans(k, -1);
    for (int i = 0; i < k; i++)
    {
        int d;
        cin >> d;
        arr[i] = d;
    }
    for (auto i : arr)
    {
        int rem = i % k;
        int m = rem;
        while (ans[m] != -1)
        {
            m++;
        }
        ans[m] = i;
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "collisions: " << collision << endl;
    
}