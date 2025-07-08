#include <bits/stdc++.h>
using namespace std;
int minCostTickets(vector<int> &days, vector<int> &costs, int index)
{
    if (index >= days.size())
        return 0;
    int one = minCostTickets(days, costs, index + 1) + costs[0];
    int i = index;
    while (i < days.size() && days[i] < days[index] + 7)
        i++;
    int seven = minCostTickets(days, costs, i) + costs[1];
    while (i < days.size() && days[i] < days[index] + 30)
        i++;
    int thirty = minCostTickets(days, costs, i) + costs[2];
    return min(one, min(seven, thirty));
}
int minCostTicketsdp(vector<int> &days, vector<int> &costs, int index, vector<int> &dp)
{
    if (index >= days.size())
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int one = minCostTicketsdp(days, costs, index + 1, dp) + costs[0];
    int i = index;
    while (i < days.size() && days[i] < days[index] + 7)
        i++;
    int seven = minCostTicketsdp(days, costs, i, dp) + costs[1];
    while (i < days.size() && days[i] < days[index] + 30)
        i++;
    int thirty = minCostTicketsdp(days, costs, i, dp) + costs[2];
    return dp[index] = min(one, min(seven, thirty));
}
int minCostTicketsTAB(vector<int> &days, vector<int> &costs)
{

    int n = days.size();
    vector<int> dp(n + 1, -1);
    dp[n] = 0;
    for (int index = n - 1; index >= 0; index--)
    {
        int one = dp[index + 1] + costs[0];
        int i = index;
        while (i < days.size() && days[i] < days[index] + 7)
            i++;
        int seven = dp[i] + costs[1];
        while (i < days.size() && days[i] < days[index] + 30)
            i++;
        int thirty = dp[i] + costs[2];
        dp[index] = min(one, min(seven, thirty));
    }
    return dp[0];
}
int main()
{
    vector<int> days = {2, 5};
    vector<int> costs = {1, 4, 25};
    cout << minCostTickets(days, costs, 0) << endl;
    vector<int> dp(days.size() + 1, -1);
    cout << minCostTicketsdp(days, costs, 0, dp) << endl;
    cout << minCostTicketsTAB(days, costs) << endl;
    return 0;
}