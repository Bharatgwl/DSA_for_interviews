#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;
bool unique(vector<int> &arr, unordered_map<int, int> &mp)
{
    set<int> set;
    for (auto i:mp){
        set.insert(i.second);
    }
    if(mp.size()==set.size()){
        return true;
    }
    return false; 
}
int main()
{
    vector<int> arr = {-3, 0, 7, 1, 1, 1, -3, 10, 0};
    unordered_map<int, int> mp;
    for (auto i : arr)
    {
        mp[i]++;
    }
    int i = 0;
    for (auto i : mp)
    {
        cout << i.first << " " << i.second << endl;
    }
    if (unique(arr, mp))
    {
        cout << "there is a unique occurence";
    }
    else
    {
        cout << "there is not unique occurence";
    }
}