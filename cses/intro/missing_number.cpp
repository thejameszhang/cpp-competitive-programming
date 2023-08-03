#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, input, sum = 0;
    cin >> x;
    // Get the total sum.
    for (int i = 0; i < x - 1; i++) {
        cin >> input;
        sum += input;
    }
    // Return the difference aka the missing number.
    cout << (x * (x + 1) / 2) - sum;
    return 0;
}
