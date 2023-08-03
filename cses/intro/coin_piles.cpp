#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &x, &y);
        // Base cases.
        if (!x && y || y && !x || x > 2 * y || y > 2 * x) {
            cout << "NO" << endl;
            continue;
        }
        x = x % 3;
        y = y % 3;
        // Boil it down to simpler cases by taking mod 3.
        if (x == y) {
            if (x == 0) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        } else {
            if (!x || !y) {
                cout << "NO" << endl;
            }
            else {
                cout << "YES" << endl;    
            }
        }
    }
    return 0;
}