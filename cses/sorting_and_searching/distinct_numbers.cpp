#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, x;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> x;
        v[i] = x;
    }
    sort(v.begin(), v.end());
    x = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] != v[i - 1]) {
            x++;
        }
    }
    cout << x << endl;
    return 0;
}
