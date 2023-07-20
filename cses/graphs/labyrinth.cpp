#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);
    char x;
    pair<int, int> start;
    vector<vector<char>>grid(n, vector<char>(m,'#'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            grid[i][j] = x;
            if (x == 'A') {
                start.first = i;
                start.second = j;
            }
        }
    }
    set<pair<int, int>> visited;
    // BFS because we need to find the length of the shortest path.
    queue<tuple<int, int, string>> q;
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    map<pair<int, int>, char> mp;
    mp[{1, 0}] = 'D';
    mp[{0, 1}] = 'R';
    mp[{-1, 0}] = 'U';
    mp[{0, -1}] = 'L';
    int r, c, nr, nc;
    string curr;
    q.push({start.first, start.second, ""});
    while (!q.empty()) {
        r = get<0>(q.front());
        c = get<1>(q.front());
        curr = get<2>(q.front());
        q.pop();
        visited.insert({r, c});
        if (grid[r][c] == 'B') {
            cout << "YES" << endl;
            cout << curr.size() << endl;
            cout << curr << endl;
            return 0;
        }
        for (auto dir : directions) {
            nr = r + dir.first;
            nc = c + dir.second;
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && (grid[nr][nc] == '.' || 
            grid[nr][nc] == 'B') && visited.find({nr, nc}) == visited.end()) {
                    q.push({nr, nc, curr + mp[dir]});
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}