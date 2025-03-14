#include <iostream>
#include <vector>
using namespace std;
/**
 * Sets all elements in the k-th row and l-th column of the 2D vector 'arr' to zero.
 *
 * @param arr A reference to a 2D vector of integers.
 * @param k The index of the row to be set to zero.
 * @param l The index of the column to be set to zero.
 * @param row The total number of rows in the 2D vector.
 * @param col The total number of columns in the 2D vector.
 */
void make(vector<vector<int>> &arr, int k, int l, int row, int col)
{
    int j = l;
    int m = k;
    for (j = 0; j < col; j++)
    {
        arr[k][j] = 0;
    }
    for (m = 0; m < row; m++)
    {
        arr[m][l] = 0;
    }
}
/**
 * Applies the `make` function to the 2D vector `arr` if `count` is non-zero.
 *
 * @param count A flag that determines whether to set the specified row and column to zero.
 * @param arr A reference to a 2D vector of integers.
 * @param newindexi The index of the row to be set to zero.
 * @param newindexj The index of the column to be set to zero.
 */
void use(int count, vector<vector<int>> &arr, int newindexi, int newindexj)
{
    if (count)
    {
        int row = arr.size();
        int cols = arr[0].size();
        make(arr, newindexi, newindexj, row, cols);
    }
}
int main()
{
    vector<vector<int>> arr(3, vector<int>(4));
    int value;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> value;
            arr[i][j] = value;
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int count = 0;
    int newindexi, newindexj;
    vector<vector<int>> demo(3, vector<int>(4));
    demo = arr;
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (demo[i][j] == 0)
            {
                demo[i][j] = 1;
                count = 1;
                newindexi = i;
                newindexj = j;
                use(count, arr, newindexi, newindexj);
                count = 0;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
