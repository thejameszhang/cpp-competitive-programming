#include <bits/stdc++.h>
using namespace std;

/* 
Fenwick trees are a dynamic variant of a prefix sum array that support two 
O(log n) operations: processing a range sum query and updating a value.
Note that if you want to update a value in a prefix sum array, it's an O(n)
operation.

Let p(k) denote the largest power of 2 that divides k. A binary indexed tree
can be stored as tree[k] = sum_q(k - p(k) + 1, k)
- Each position k contains the sum of values in the range of the original array
whose length is p(k) and ends at position k

If the original array is 1-indexed and is [1, 3, 4, 8, 6, 1, 4, 2]
-> [1, 3, 4, 16, 6, 7, 4, 29]
For any sum_q(a, b) s.t. a > 1 --> sum_q(a,b) = sum_q(1, b) - sum_q(1, a-1)

Since each element belongs to O(n) ranges, it suffices to only update O(log n)
values in the tree. Implementation becomes trivial when one realizes that 
p(k) = k&-k which uses bit operations and twos complement
-> 0101 = 5 and so 1011 = -5 and 0101 & 1011 -> p(k) = 1
-> 01000 = 8 and so 11000 = -8 and 01000 & 11000 -> p(k) = 8 
*/

int sum(int k, vector<int>& tree) {
    int sum = 0;
    while (k >= 1) {
        sum += tree[k];
        k -= k&-k;
    }
    return sum;
}

void add(int k, int x, int n, vector<int>& tree) {
    while (k <= n) {
        tree[k] += x;
        k += k&-k;
    }
}

int main() {
    int n, y;
    cin >> n;
    vector<int> v(n+1), tree(n+1); 
    for (int i = 0; i < n; i++) {
        cin >> y;
        v[i] = y;
        // i + 1 for 1-indexing.
        add(i + 1, y, n, tree);
    }
    // Verify that the tree was built correctly.
    for (auto x : tree) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}