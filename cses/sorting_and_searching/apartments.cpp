#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, k, x, res = 0;
    scanf("%lld %lld %lld", &n, &m, &k);
    vector<long long> applicants(n);
    vector<long long> sizes(m);
    for (int i = 0; i < n; i++) {
        cin >> x;
        applicants[i] = x;
    }
    for (int j = 0; j < m; j++) {
        cin >> x;
        sizes[j] = x;
    }
    sort(applicants.begin(), applicants.end());
    sort(sizes.begin(), sizes.end());
    x = 0;
    for (auto size : sizes) {
        while (x < n && applicants[x] < size - k) {
            x++;
        }
        if (x >= n) {
            break;
        }
        if (applicants[x] >= size - k && applicants[x] <= size + k) {
            res++;
            x++;
            continue;
        }
        if (applicants[x] > size + k) {
            continue;
        }
    }
    cout << res << endl;
    return 0;
}
