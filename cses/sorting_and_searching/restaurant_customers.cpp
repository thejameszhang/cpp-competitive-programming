#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

/* 
You are given the arrival and leaving times of n customers in a restaurant.
What was the maximum number of customers in the restaurant at any time?
*/

int main() {
    int n, a, d;
    cin >> n;
    vi arrivals(n), departures(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> d;
        arrivals[i] = a;
        departures[i] = d;
    }
    sort(arrivals.begin(), arrivals.end());
    sort(departures.begin(), departures.end());
    a = 0; d = 0;
    int res = 0, curr = 0;
    while (a < n) {
        if (arrivals[a] < departures[d]) {
            curr += 1;
            res = max(res, curr);
            a += 1;
        } else if (departures[d] < arrivals[a]) {
            curr -= 1;
            d += 1;
        } else {
            a += 1;
            d += 1;
        }
    }
    cout << res << endl;
    return 0;
}