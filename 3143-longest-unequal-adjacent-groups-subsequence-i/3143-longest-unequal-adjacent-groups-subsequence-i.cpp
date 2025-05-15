class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        vector<string> ans;
        if (groups.size() > 1) {
            ans.push_back(words[0]);
            for (int i = 1; i < groups.size(); ++i) {
                if (groups[i] != groups[i - 1]) {
                    ans.push_back(words[i]);
                }
            }
            return ans;
        }
        ans.push_back(words[0]);
        return ans;
    }
};