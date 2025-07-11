#include <bits/stdc++.h>
#define ll long long
#define pli pair<long long, int>

using namespace std;

int mostbooked(int n, vector<vector<int>> meetings)
{
    sort(meetings.begin(), meetings.end());
    priority_queue<pli, vector<pli>, greater<pli>> freerooms, occupiedrooms;
    vector<int> freq(n, 0);

    for (int i = 0; i < n; ++i)
    {
        freerooms.push({0, i});
    }
    for (int i = 0; i < meetings.size(); ++i)
    {
        // add rooms that are getting free now
        while (!occupiedrooms.empty() && occupiedrooms.top().first <= meetings[i][0])
        {
            pli room = occupiedrooms.top();
            occupiedrooms.pop();
            room.first = 0;
            freerooms.push(room);
        }
        // assign a room to current meeting
        if (!freerooms.empty())
        {
            pli curr = freerooms.top();
            freerooms.pop();
            freq[curr.second]++;
            curr.first = meetings[i][1];
            occupiedrooms.push(curr);
        }
        //
        else
        {
            pli curr = occupiedrooms.top();
            occupiedrooms.pop();
            freq[curr.second]++;
            curr.first += 1LL * (meetings[i][1] - meetings[i][0]);
            occupiedrooms.push(curr);
        }
    }

    int max_meeting_room;
    int max_meeting = 0;
    for (int i = 0; i < freq.size(); i++)
    {
        if (freq[i] > max_meeting)
        {
            max_meeting = freq[i];
            max_meeting_room = i;
        }
    }
    return max_meeting_room;
}
int main()
{
    int n = 2;

    vector<vector<int>> meetings = {{0, 10}, {1, 5}, {2, 7}, {3, 4}};
    cout << mostbooked(n, meetings);

    return 0;
}