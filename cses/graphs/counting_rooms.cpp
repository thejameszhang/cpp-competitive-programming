#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int i, int j, ll n, ll m, vector<vector<char>>& grid, 
set<pair<int, int>>& visited) {
    if (i < 0 || j < 0 || i >= n || j >= m
    || grid[i][j] == '#' || visited.find({i, j}) != visited.end()) {
        return;
    }
    visited.insert({i, j});
    dfs(i + 1, j, n, m, grid, visited);
    dfs(i - 1, j, n, m, grid, visited);
    dfs(i, j + 1, n, m, grid, visited);
    dfs(i, j - 1, n, m, grid, visited);
}

int main() {
    ll n, m, res = 0;
    char x;
    scanf("%lld %lld", &n, &m);
    vector<vector<char>> grid(n, vector<char>(m, '#'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            grid[i][j] = x;
        }
    }
    set<pair<int, int>> visited;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && visited.find({i, j}) == visited.end()) {
                dfs(i, j, n, m, grid, visited);
                res += 1;
            }
        }
    }
    cout << res << endl;
    return 0;
}