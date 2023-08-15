/*
Successor are graphs suich that each node has outdegree of 1. It can have 
multiple components, all of which contain a cycle or lead up to a cycle.
Any successor graph corresponds to a function where the parameter for the 
function is the node, and the output is the successor of that node.

We can also define a function node succ(node x, int k) that outputs the node
k steps away from x. With preprocessing, this can be calculated in O(log k)
time. Precalculate all values of succ(x, k) where k is a power of 2 and at
most u. Precalculating takes O(n log u) time because `log u` values are 
calculated for each node. Thus, now if we want to calculate succ(x, 11)
we can find
succ(x, 11) = succ(succ(succ(x, 8), 2), 1).
*/

#include <bits/stdc++.h>
using namespace std;