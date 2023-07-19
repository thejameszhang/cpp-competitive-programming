#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, x, y, mod = 1e9 + 7;
    scanf("%lld %lld", &n, &x);
    vector<ll> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> y;
        coins[i] = y;
    }
    vector<ll> dp(x + 1);
    dp[0] = 0;
    for (int i = 0; i < x + 1; i++) {
        for (auto c : coins) {
            if (i - c >= 0) {
                if (i == c) {
                    dp[i] = (dp[i] % mod) + (1 % mod) % mod;
                } else {
                    dp[i] = (dp[i] % mod) + (dp[i - c] % mod) % mod;
                }
            }
        }
    }
    cout << (dp[x] ==  mod ? 0 : dp[x]) << endl;
    return 0;
}