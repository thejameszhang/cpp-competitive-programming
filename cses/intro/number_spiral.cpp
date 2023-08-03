#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t, x, y;
    cin >> t;
    for (int i = 0; i < t; i++) {
        scanf("%lld %lld", &y, &x);
        if (y >= x) {
            if (y % 2 ==0) {
                cout << y * y - x + 1 << endl;
            } else {
                cout << (y - 1) * (y - 1) + x << endl;
            }
        } else {
            if (x % 2 == 1) {
                cout << x * x - y + 1 << endl;
            } else {
                cout << (x - 1) * (x - 1) + y << endl;
            }
        }
    }
    return 0;
}
