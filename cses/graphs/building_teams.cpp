#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define pb push_back

/* 
there are n pupils, m friendships. divide the pupils into 2 teams in such a 
way that no 2 pupils in a team are friends. suppose 1 and 3 are friends.
wlog, set 1 to team 1 and 3 to team 2. now suppose 3 and 5 are friends.
    - if 3 is on team 2 and 5 is not visited yet, then set 5 to 1.
    - if 3 is on team 2 and 5 is on team 2, impossible.
    - if 3 is on team 2 and 5 is on team 1, continue.
*/

bool stop = false;

void dfs(int node, int prev, vector<vi>& adj, vi& res) {
    // Base case.
    if (res[node]) {
        if (res[node] == prev) {
            stop = true;
            return;
        }
    } 
    // Recursive step.
    res[node] = (prev == 1 ? 2 : 1);
    for (const auto& nei : adj[node]) {
        if (!res[nei]) dfs(nei, res[node], adj, res);
        else {
            if (res[nei] == res[node]) {
                stop = true;
                return;
            }
        }
    }
}

int main() {

    int n, m, a, b;
    cin >> n >> m;
    // Create the graph representation.
    vector<vi> adj(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    // Define the result vector.
    vi res(n + 1);
    for (int i = 1; i < n + 1; i++) {
        // If i has no team -> not visited yet.
        if (!res[i]) {
            res[i] = 1;
            dfs(i, 0, adj, res);
            if (stop) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    // Else print out the teams.
    for (int i = 1; i < n + 1; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}