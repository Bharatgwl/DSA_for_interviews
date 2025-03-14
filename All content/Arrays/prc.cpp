#include <iostream>
#include <vector>
#include <algorithm>
#include<limits.h>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        int sum = 0;
        int negative_count = 0;
        int min_abs_val = INT_MAX;

        for (int i = 0; i < N; i++) {
            cin >> A[i];
            sum += abs(A[i]);
            if (A[i] < 0) {
                negative_count++;
            }
            min_abs_val = min(min_abs_val, abs(A[i]));
        }

        if (negative_count % 2 == 1) {
            sum -= 2 * min_abs_val;
        }

        cout << sum << endl;
    }

    return 0;
}