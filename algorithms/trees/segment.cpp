#include <bits/stdc++.h>
using namespace std;

/*
A segment tree supports the same 2 operations as a fenwick tree, but it can 
support sum queries, minimum and maximum queries, and more.
- Nodes on the bottom represent the original array.
- Other nodes contain more information for processing range queries.
Assume the size of the array is a power of 2 and zero-indexed. Suppose the 
original array is [5, 8, 6, 3, 2, 7, 2, 6]
The segment tree for a sum query is 
                            39
                        22          17
                    13     9     9      8
                  5   8   6  3  2  7   2  6
where the segment tree is of length 2n, where n is the size of the original
array. tree[1] is the top node, tree[2] and tree[3] are its children
and tree[n] to tree[2n-1] are the original array
*/

int sum(int a, int b, int n, vector<int>& tree) {
    a += n;
    b += n;
    int sum = 0;
    while (a <= b) {
        if (a % 2 == 1) sum += tree[a++];
        if (b % 2 == 0) sum += tree[b--];
        a /= 2;
        b /= 2;
    }
    return sum;
}

void add(int k, int x, int n, vector<int>& tree) {
    k += n;
    tree[k] += x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = tree[2*k] + tree[2*k+1];
    }
}