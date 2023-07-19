#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, x, w, l, r, res = 0;
    scanf("%lld %lld", &n, &x);
    vector<long long> children(n);
    for (int i = 0; i < n; i++) {
        cin >> w;
        children[i] = w;
    }
    sort(children.begin(), children.end());
    l = 0;
    r = children.size() - 1;
    while (l <= r) {
        if (l == r) {
            res++;
            break;
        }
        if (children[r] + children[l] > x) {
            r--;
        } else {
            r--;
            l++;
        }
        res++;
    }
    cout << res << endl;
    return 0;
}
