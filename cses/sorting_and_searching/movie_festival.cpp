#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using vi = vector<ll>;
#define pb push_back

bool sort_by_second(const pair<ll, ll>& a, const pair<ll, ll>& b) {
    return (a.second < b.second);
}

int main() {
    ll n, s, e;
    cin >> n;
    vector<pair<ll, ll>> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        movies[i] = {s, e};
    }
    sort(movies.begin(), movies.end(), sort_by_second);
    int prev_end = INT_MIN, res = 0;
    for (int i = 0; i < n; i++) {
        if (movies[i].first >= prev_end) {
            res++;
            prev_end = movies[i].second;
        }
    }
    cout << res << endl;
    return 0;
}
