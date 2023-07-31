#include <bits/stdc++.h>
using namespace std;

/* 
A spanning tree is a graph consisting of all nodes of the graph and some of 
the edges of the graph such that there exists a path between any two nodes.
A minimum spanning tree is a spanning tree whose weight is as small as possible,
given the graph.

Kruskals algorithm first sorts the edges in increasing order of their weights.
After this, the algorithm goes through the list of edges and adds each edge to
the tree IF it joins two separate components ie. if the next edge to be added
is A to B, but A and B are already in the same component, then this edge will
not be added. This is a greedy algorithm, and it can be proved that it works
via a simple proof by contradiction.

First sort the edges by the weights, which will take O(nlog(n)) time. Then,
we need two functions.
    1. `same()` which determines if two nodes are in the same component
    2. `unite()` which joins two separate components

We will use a union-find structure that implements both of these functions 
in O(log(n)) time. This structure maintains a collection of disjoint sets 
where `unite()` joins two sets, and `find` finds the representative of the set.
Join the representative of the smaller set to the represenative of the larger
set, every time.
*/

int find(int x, vector<int>& link) {
    while (x != link[x]) x = link[x];
    return x;
}

bool same(int a, int b, vector<int>& link) {
    return find(a, link) == find(b, link);
}

void unite(int a, int b, vector<int>& link, vector<int>& size) {
    a = find(a, link);
    b = find(b, link);
    if (size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    link[b] = a;
}


int main() {

    int n;
    cin >> n;

    vector<int> link(n + 1), size(n + 1);
    // Initially each element belongs to a separate set.
    for (int i = 1; i <= n; i++) {
        link[i];
        size[i] = 1;
    } 
    return 0;
}
