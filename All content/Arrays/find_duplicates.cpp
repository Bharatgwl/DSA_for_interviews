#include<iostream>
#include<vector>
using namespace std;
// vector<int> findDuplicates(vector<int>& nums) {
//     vector<int> ans(nums.size(),0);
//     for(int i=0;i<nums.size();i++){
//        ans = ans^nums;
//     }
//     return ans;
// }
int main(){
    vector<int> nums = {4,3,2,7,8,2,3,1};
    // vector<int> ans = findDuplicates(nums);
    vector<int> ans(nums.size(),0);
    // ans^=nums;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}