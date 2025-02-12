#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class item
{
public:
    float weight, profit, ratio;
};
bool compare(item a, item b)
{
    return a.ratio > b.ratio;
}
int main()
{
    int n;
    double capacity, total_value = 0;
    cout << "enter the number of items: ";
    cin >> n;
    vector<item> items(n);
    for (int i = 0; i < n; i++)
    {
        cout << "enter weight snd profit for the item [" << i << "]: ";
        cin >> items[i].weight >> items[i].profit;
        items[i].ratio = items[i].profit / items[i].weight;
    }
    cout << "enter the capacity of the knapsack: ";
    cin >> capacity;
    sort(items.begin(), items.end(), compare);
    for (int i = 0; i < n && capacity > 0; i++)
    {
        if (items[i].weight <= capacity)
        {
            total_value += items[i].profit;

            capacity -= items[i].weight;
        }
        else
        {
            total_value += items[i].ratio * capacity;
            break;
        }
    }
    cout << "\n the maximum value:" << total_value << endl;
}