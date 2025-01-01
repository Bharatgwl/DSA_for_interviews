#include <iostream>
#include <math.h>
using namespace std;

int Kth_grammer(int n, int k)
{
    if (n == 1 || k == 1)
    {
        return 0;
    }
    int mid = pow(2, n - 1) / 2;

    if (k <= mid)
    {
        return Kth_grammer(n - 1, k);
    }
    else
    {
        return !(Kth_grammer(n - 1, k - mid));
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << Kth_grammer(n, k);
}