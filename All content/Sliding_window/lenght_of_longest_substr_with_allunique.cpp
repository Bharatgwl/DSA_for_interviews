#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubstringWithoutRepeating(string s) {
    unordered_map<char, int> map;
    int maxLength = 0, left = 0;

    for (int right = 0; right < s.length(); right++) {
        map[s[right]]++; 
        
        while (map[s[right]] > 1) { 
            map[s[left]]--;
            left++; 
        }

        maxLength = max(maxLength, right - left + 1); 
    }

    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << "Length of Longest Substring: " << longestSubstringWithoutRepeating(s) << endl;
    return 0;
}
