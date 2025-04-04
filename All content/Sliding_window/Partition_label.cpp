#include <bits/stdc++.h>
using namespace std;
vector<int> partitionLabels(string s)
{
    unordered_map<char, int> last_occurrence;
    for (int i = 0; i < s.size(); i++)
    {
        last_occurrence[s[i]] = i;
    }

    cout << "Last occurrence of each character: " << endl;
    for (auto it = last_occurrence.begin(); it != last_occurrence.end(); ++it)
    {
        cout << it->first << ": " << it->second << endl;
    }

    vector<int> result;
    int start = 0, end = 0;

    cout << "Starting loop" << endl;
    for (int i = 0; i < s.size(); i++)
    {
        cout << "At index: " << i << endl;
        end = max(end, last_occurrence[s[i]]);
        cout << "Updating end to: " << end << endl;
        if (i == end)
        {
            cout << "Found end at index: " << i << endl;
            result.push_back(end - start + 1);
            cout << "Adding to result: " << end - start + 1 << endl;
            start = i + 1;
        }
    }

    cout << "Final result: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return result;
}
int main()
{
    string s = "ababcbacadefegdehijhklij";
    vector<int> result = partitionLabels(s);
    cout << "Result: ";
    // for (int i = 0; i < result.size(); i++)
    // {
    //     cout << result[i] << " ";
    // }

    return 0;
}