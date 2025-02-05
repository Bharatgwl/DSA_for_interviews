#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/**
 * Time complexity: O(n log n)
 * https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/
 * https://www.naukri.com/code360/problems/median-in-a-stream_975268
 * https://leetcode.com/problems/find-median-from-data-stream/description/
 */
void sorting(vector<int> &vec) {
    sort(vec.begin(), vec.end());
}

void find_median(vector<int> vec, vector<int> &ans) {
    if (vec.empty()) {
        return;
    }
    int size = vec.size();
    if (size % 2 == 0) {
        // Median for even size: average of two middle elements
        int median = (vec[size / 2 - 1] + vec[size / 2]) / 2;
        ans.push_back(median);
    } else {
        // Median for odd size: middle element
        ans.push_back(vec[size / 2]);
    }
}

vector<int> findMedian(vector<int> &arr, int n) {

  if (n == 1) {
    vector<int> ans;
	ans.push_back(arr[0]);
	return ans;
  }
  vector<int> vec;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    vec.push_back(arr[i]);
    sorting(vec);
    find_median(vec, ans);
  }
  return ans;
}

int  main()
{   
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = findMedian(arr, n);
    for (int i = 0; i < ans.size(); i++)    
    {
        cout << ans[i] << " ";
    }
    return 0;
}
// 20 14 13 16 17 16 16 14 16 16
// 10
// 20 8 13 19 17 16 12 0 19 20