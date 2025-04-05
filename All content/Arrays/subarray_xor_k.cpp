#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {4,3,2,1,4,2};
    int k = 3;
    int n = arr.size();
    int ans = 0;
    unordered_map<int,int> mp;
    int xr = 0;
    mp[xr]++;
    for(int i=0; i<n ; i+=1){
        xr = xr^arr[i];
        int x = xr^k;
        ans +=mp[x];
        mp[xr]++;
    }
    cout<<ans<<endl;
    // Output: 4

return 0;
}