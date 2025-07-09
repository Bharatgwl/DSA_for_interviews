#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> a = {3, 4, 5, 1, 2};
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > a[(i + 1) % a.size()])
        {
            count++;
        }
    }
    if (count == 1 )
    {
        cout << "array is sorted and rotated";
    }
    else
    {
        cout << "array is not sorted and rotated";
    }
}
