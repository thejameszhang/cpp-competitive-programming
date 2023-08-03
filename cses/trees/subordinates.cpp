#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define pb push_back

int dfs(int node, unordered_map<int, vi>& tree, vi& res) {
    // Base case -> if it has no children, don't make a recursive call
    // return 1.
    if (tree[node].size() == 0) {
        res[node] = 0;
        return 1;
    }
    // Recursive step
    int subs = 0, curr = 0;
    for (auto& child : tree[node]) {
        if (res[child]) subs += res[child];
        else {
            curr = dfs(child, tree, res);
            res[child] = curr;
            subs += curr;
        }
    }
    res[node] = subs + 1;
    return subs + 1;
}

int main() {
    int n, x;
    cin >> n;
    unordered_map<int, vi> tree;
    vi res(n + 1, 0);
    for (int i = 2; i < n + 1; i++) {
        cin >> x;
        tree[x].pb(i);
    }
    dfs(1, tree, res);
    for (int i = 1; i < n + 1; i++) {
        cout << res[i] - 1 << " ";
    }
    cout << endl;
    return 0;
}