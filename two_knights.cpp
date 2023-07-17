#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, x, seq = 0, diff = 0;
    cin >> n;
    cout << 0 << endl;
    for (int i = 2; i <= n; i++) {
        x = i * i;
        cout << x * (x - 1) / 2 - 8 * seq << endl;
        diff++;
        seq += diff;
    }
    return 0;
}
