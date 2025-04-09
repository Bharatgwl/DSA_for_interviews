#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    // for (int i = n; i > 0; --i)
    // {
    //     int j = n;
    //     while (j >= i)
    //     {
    //         cout << j;
    //         --j;
    //     }
    //     cout << endl;
    // }
    // int a = 1;
    // int i=1;
    // while(i<=n){
    //     a=i;
    //     int j=0;
    //     while(j<i){
    //         cout << a << " ";
    //         a++;
    //         j++;
    //     }
    //     a--;
    //     cout << endl;
    //     i++;
    // }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j || i + j == n + 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}