#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, x, digit, best;
    cin >> n;
    vector<ll> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        x = i;
        while (x) {
            digit = x % 10;
            if (digit) {
                if (dp[i]) {
                     dp[i] = min(dp[i], 1 + dp[i - digit]);
                } else {
                    dp[i] = 1 + dp[i - digit];
                }
            }
            x /= 10;
        }
    }
    cout << dp[n] << endl;
    return 0;
}