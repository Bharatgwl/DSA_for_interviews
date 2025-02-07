#include <iostream>
#include <vector>
using namespace std;
bool ispossible(vector<int> arr, int mid, int m)
{
    int dishes = 0;
    for (int rank : arr)
    {
        int time = 0;
        int i = 0;
        while (time + (i + 1) * rank <= mid)
        {
            i++;
            time += i * rank;
        }
        dishes += i;
        if (dishes >= m)
        {
            return true;
        }
    }
    return false;
}
int cooking_ninjas(vector<int> rank, int m)
{
    int s = 1;
    int e = rank[rank.size() - 1] * (m * (m + 1) / 2);
    int ans = 0;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (ispossible(rank, mid, m))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int m = 11;
    // cout<< 4*(m*(m+1)/2) <<endl;
    vector<int> rank = {1, 2, 3, 4};
    cout << cooking_ninjas(rank, m);
}
