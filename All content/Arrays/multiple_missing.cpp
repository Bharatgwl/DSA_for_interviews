#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {3, 7, 2, 9, 11, 13, 6, 1};
    vector<int> ans(13,0);
      for (int i = 0; i < arr.size(); i++)
    {
        ans[arr[i]] = 1;
    }
    for (int i = 1; i <= ans.size(); i++)
    {
        if (ans[i] == 0)
        {
            cout << i << " ";
        }
    }
}