#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, curr = 5, res = 0;
    cin >> n;
    while (curr <= n) {
        res += floor(n / curr);
        curr *= 5;
    }
    cout << res;
    return 0;
}