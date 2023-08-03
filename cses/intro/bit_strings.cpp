#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
    long long n, res = 1, c = pow(10, 9) + 7;
    cin >> n;
    for (int i = 0; i < n; i++) {
        res = (res % c) * (2 % c) % c;
    }
    cout << res << endl;
    return 0;
}