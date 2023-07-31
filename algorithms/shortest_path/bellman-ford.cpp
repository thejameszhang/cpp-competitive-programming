#include <bits/stdc++.h>
#include <limits>
using namespace std;

class Solution {
  public:
    vector<int> bellman_ford(vector<tuple<int, int, int>>& edges, int x) {
        // Define some variables for the algorithm.
        int INF = numeric_limits<int>::max();
        int n = edges.size();
        // Set all distances to INF except node x, the starting node.
        vector<int> distances;
        for (int i = 1; i <= n; i++) {
            distances[i] = INF;
        }
        distances[x] = 0;
        // Algorithm consists of n - 1 rounds, each round iterate through edges.
        for (int i = 1; i <= n - 1; i++) {
            for (auto e : edges) {
                int a, b, w;
                tie(a, b, w) = e;
                // Update the minimum distance, if possible.
                distances[b] = min(distances[b], distances[a] + w);
            }
        }
        return distances;
    }
};