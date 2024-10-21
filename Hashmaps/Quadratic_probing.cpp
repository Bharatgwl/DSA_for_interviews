#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k;
    int collision = 0;
    cin >> k;
    vector<int> arr(k);
    vector<int> ans(k, -1);

    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }
    for (int i : arr)
    {
        int rem = i % k;
        int m = rem;
        int sq = 1;
        while (ans[m] != -1)
        {
            collision++;
            m = (rem + sq * sq) % k;
            sq++;
        }
        ans[m] = i;
    }

    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "collisions: " << collision << endl;
    return 0;
}
