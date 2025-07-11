// #include <bits/stdc++.h>
// using namespace std;

// string remove_specical(string &s) {
//     string ans;
//     long long i = 0;
//     while (i < s.length()) {

//         if (s[i] == '$' || s[i] == '#' || s[i] == '*') {
//             int count = 0;
//             while (i < s.length() && (s[i] == '$' || s[i] == '#' || s[i] == '*')) {
//                 count++;
//                 i++;
//             }

//             i += count;
//         } else {
//             ans += s[i];
//             i++;
//         }
//     }
//     return ans;
// }

// int main() {
//     string s = "abc#d$*afgh";
//     cout << remove_specical(s) << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

string remove_special(string &s) {
    queue<char> q;
    for (char ch : s) {
        q.push(ch);
    }

    string ans;
    while (!q.empty()) {
        char ch = q.front();

        if (ch == '#' || ch == '$' || ch == '*') {
            int count = 0;

            while (!q.empty() && (q.front() == '#' || q.front() == '$' || q.front() == '*')) {
                q.pop();
                count++;
            }

            while (!q.empty() && count--) {
                q.pop();
            }
        } else {

            ans += ch;
            q.pop();
        }
    }

    return ans;
}

int main() {
    string s = "thw $gh##bj hdwd";
    cout << remove_special(s) << endl;  // Output: abcgh
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <algorithm>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     vector<int> chips(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> chips[i];
//     }

//     // prefix imbalance sum
//     int imbalance = 0;
//     int total_moves = 0;

//     for (int i = 0; i < n; ++i) {
//         imbalance += chips[i];
//         total_moves = max(total_moves, abs(imbalance));
//     }

//     cout << total_moves << endl;
//     return 0;
// }
