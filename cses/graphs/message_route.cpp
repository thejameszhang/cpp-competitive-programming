#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define pb push_back

int main() {
    // Parse input.
    int N, M, A, B;
    cin >> N >> M;
    // Define distance, parent, and adjacency vectors.
    vi dist(N + 1, INT_MAX), parent(N + 1);
    vector<vi> adj(N + 1);
    // Parse the M connections.
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        adj[A].pb(B);
        adj[B].pb(A);
    }
    // BFS.
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    int x;
    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (const auto& nei : adj[x]) {
            if (dist[nei] == INT_MAX) {
                dist[nei] = dist[x] + 1;
                parent[nei] = x;
                q.push(nei);
            }
        }
    }
    if (dist[N] == INT_MAX) cout << "IMPOSSIBLE" << endl;
    else {
        cout << dist[N] + 1 << endl;
        vi v = {N};
        while (v.back() != 1) {
            v.pb(parent[v.back()]);
        }
        reverse(begin(v), end(v));
        for (int t : v) {
            cout << t << " ";
        }
    }
    return 0;
}