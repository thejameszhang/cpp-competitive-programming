#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, mod = 1e9 + 7;
    char x;
    cin >> n;
    vector<vector<ll>> dp(n, vector<ll> (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            if (x == '*') {
                dp[i][j] = -1;
            }
        }
    }
    if (dp[n-1][n-1] == -1 || dp[0][0] == -1) {
        cout << 0 << endl;
        return 0;
    }
    dp[n-1][n-1] = 1;
    // dp[x][y] = dp[x+1][y] + dp[x][y+1]
    for (int i = n - 1; i > -1; i--) {
        for (int j = n - 1; j > -1; j--) {
            if (dp[i][j] == -1) {
                continue;
            }
            if (i < n - 1 && dp[i + 1][j] != -1) {
                dp[i][j] = (dp[i][j] % mod) + (dp[i + 1][j] % mod) % mod;
            }
            if (j < n - 1 && dp[i][j + 1] != -1) {
                dp[i][j] = (dp[i][j] % mod) + (dp[i][j + 1] % mod) % mod;
            }
        }
    }
    cout << dp[0][0] % mod << endl;
    return 0;
}