#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//  int ele=8;
//   auto it =find(a.begin(),a.end(),ele);
//   if(it!=a.end()){
//     cout<<ele;
//   }
//   else {
//     cout<<"not found";
//   }
int main()
{
    vector<int> a = {1,5,3,9,4};
    int n = a.size();
    for (int i = 0; i < n; i++)
    {

        for (int j = i; j < n; j++)
        {
            int sum = a[i] + a[j];
            auto it = find(a.begin(), a.end(), sum);
            if (it != a.end())
            {
                cout << a[i]<<" "<<a[j]<<endl;
            }
        }
    }

}
