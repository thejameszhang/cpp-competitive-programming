#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define pb push_back

/*
Byteland has n cities, m roads. Construct new roads s.t. there is a route
between any two cities. 

Find the minimum number of roads required, and also determine whcih roads
should be built.

Sol: use dfs to find the number of connected components (k). thus, the solution
would be k - 1. to find which roads we should build, 
*/


void dfs(int node, vector<vi>& adj, vector<bool>& visited) {
    // Base case.
    if (visited[node]) return;
    // Recursive step.
    visited[node] = true;
    for (const auto& nei : adj[node]) {
        if (!visited[nei]) {
            dfs(nei, adj, visited);
        }
    }
}

int main() {
    int a, b;
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n + 1);
    vector<bool> visited(n + 1);
    vi representatives;
    // Create the map.
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    // Every time a node is unvisited, add to the list of component representatives.
    for (int i = 1; i < n + 1; i++) {
        // If not yet visited, then add it to representatives and call dfs. 
        if (!visited[i]) {
            representatives.pb(i);
            dfs(i, adj, visited);
        }
    }
    // Connect adjacent nodes in the representatives list.
    cout << representatives.size() - 1 << endl;
    for (int i = 0; i < representatives.size() - 1; i++) {
        cout << representatives[i] << " " << representatives[i + 1] << endl;
    }
    cout << endl;
    return 0;
}