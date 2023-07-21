#include <bits/stdc++.h>
#include <limits>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int x) {
      // Define some variables for the algorithm.
      int INF = numeric_limits<int>::max();
      vector<int> distances;
      vector<bool> processed;
      // Note that this will act as a min heap.
      priority_queue<pair<int, int>>pq;
      // Populate the distances vector with INF.
      int n = adj.size();
      for (int i = 1; i <= n; i++) {
        distances[i] = INF;
      }
      distances[x] = 0;
      // Push our initial node to the priority queue.
      pq.push({0, x});
      while (!pq.empty()) {
        // a is the node in the pq.
        int a = pq.top().second;
        pq.pop();
        if (processed[a]) continue;
        processed[a] = true;
        // If not processed yet, then process it.
        for (auto u : adj[a]) {
          // Current distance to node b is w.
          int b = u.first, w = u.second;
          // If the distance from node a is less, then update.
          if (distances[a] + w < distances[b]) {
            distances[b] = distances[a] + w;
            pq.push({-distances[b], b});
          }
        }
        return distances;
      }
    }
};