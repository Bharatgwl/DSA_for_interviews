#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{

    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            swap(v[i][j], v[j][i]);
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size / 2; j++)
        {
            swap(v[i][j], v[i][size - j - 1]);
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << v[i][j] << " ";
        }
    }
}