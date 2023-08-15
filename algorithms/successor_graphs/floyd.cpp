/* 
The easiest way to detect a cycle is to walk through the graph and keep track all 
of the nodes and keep track of all of the nodes that have been visited. Once
a node is visited for the second time, we conclude that that node is the 
first node in the graph -> O(N) time and O(N) memory.

Floyd's algorithm for cycle detection is O(N) time, but only O(1) memory. This
is really the turtoise and the hare algorithm, and it is commonly taught to
detecting a cycle in a linked list.
*/
#include <bits/stdc++.h>
using namespace std;

#ifndef  NODE_H
#define NODE_H
class Node{
public:
    Node(int data);
    Node *next;
    int data;
    Node(){}
};
#endif

Node* succ(Node* x) {
    return x->next;
}

Node* floyds(Node* x) {
    Node* a = succ(x);
    Node* b = succ(succ(x));
    // This while loop is sufficient for purely cycle detection.
    while (a != b) {
        a = succ(a);
        b = succ(succ(b));
    }
    // To find the start of the cycle, proceed. At this point, a has walked
    // k steps and b has walked 2k steps, so the length of the cycle divides
    // k.
    a = x;
    while (a != b) {
        a = succ(a);
        b = succ(b);
    }
    Node* first = a;
    return first;
}

