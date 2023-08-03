#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, c = 1e9 + 7;
    cin >> n;
    vector<ll> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j <= 6; j++) {
            if (j > i) continue;
            dp[i] = (dp[i] + dp[i - j]) % c;
        }
    }
    cout << dp[n] << endl;
    return 0;
}