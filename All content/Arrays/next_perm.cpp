#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
int main()
{
    int a[3] = {1, 2, 3};
    next_permutation(a, a + 3);
    cout << a[0] << " " << a[1] << " " << a[2];

    return 0;
}