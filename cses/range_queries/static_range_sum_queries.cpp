#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, q, x, y;
    cin >> n >> q;
    vector<ll> v(n + 1, 0);
    // For static range sum queries, a prefix array suffices.
    for (int i = 1; i < n + 1; i++) {
        cin >> x;
        v[i] = x + v[i - 1];
    }
    // Now process the q queries
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        cout << v[y] - v[x - 1] << endl;
    }
    return 0;
}