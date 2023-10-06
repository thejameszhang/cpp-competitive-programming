#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    int n, x, mod = 1e9 + 7;
    cin >> n >> x;
    // Defining the dp vector 
    vector<int> dp(x + 1), coins(n);
    dp[0] = 1;
    for (int i = 0; i < n; i++) cin >> coins[i];
    // O(mn)
    for (const auto& coin : coins) {
        for (int i = 1; i < x + 1; i++) {
            // Making sure not out of boudns
            if (i - coin >= 0) {
                if (i - coin == 0) {
                    dp[i] = ((dp[i] % mod) + 1) % mod;
                } else {
                    dp[i] = ((dp[i] % mod) + dp[i - coin] % mod) % mod;
                }
            }
        }
    }
    cout << dp[x] << endl;
    return 0;
}