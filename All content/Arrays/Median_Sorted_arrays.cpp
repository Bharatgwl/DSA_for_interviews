#include <bits/stdc++.h>
using namespace std;

int median_of_sorted_Arrays(vector<int> &a, vector<int> &b) {
    int n1 = a.size();
    int n2 = b.size();
    if (n1 > n2) {
        return median_of_sorted_Arrays(b, a);
    }

    int l = 0;
    int r = n1;
    int half = (n1 + n2 + 1) / 2;
    
    while (l <= r) {
        int i = (l + r) / 2;
        int j = half - i;

        int aleft = (i > 0) ? a[i - 1] : INT_MIN;
        int aright = (i < n1) ? a[i] : INT_MAX;
        int bleft = (j > 0) ? b[j - 1] : INT_MIN;
        int bright = (j < n2) ? b[j] : INT_MAX;

        if (aleft <= bright && bleft <= aright) {
            if ((n1 + n2) % 2 == 1) {
                return max(aleft, bleft);
            } else {
                return (max(aleft, bleft) + min(aright, bright)) / 2;
            }
        } else if (aleft > bright) {
            r = i - 1;
        } else {
            l = i + 1;
        }
    }
    return -1; 
}

int main() {
    vector<int> a = {1, 2, 3};
    vector<int> b = {4, 5};
    cout << median_of_sorted_Arrays(a, b);

    return 0;
}
