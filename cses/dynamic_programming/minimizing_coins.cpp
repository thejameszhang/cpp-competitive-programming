#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, x, y;
    scanf("%lld %lld", &n, &x);
    vector<ll> coins(n);
    // Populate the coins vector.
    for (int i = 0; i < n; i++) {
        cin >> y;
        coins[i] = y;
    }
    vector<ll> dp(x + 1);
    dp[0] = 0;
    for (int i = 1; i < x + 1; i++) {
        for (auto c : coins) {
            if (i < c) continue;
            if (i == c) {
                dp[i] = 1;
            } else {
                if (dp[i - c]) {
                    if (dp[i]) {
                        dp[i] = min(1 + dp[i - c], dp[i]);
                    } else {
                        dp[i] = 1 + dp[i - c];
                    }
                }
            }
        }
    }

    cout << (dp[x] == 0 ? -1 : dp[x]) << endl;
    return 0;
}