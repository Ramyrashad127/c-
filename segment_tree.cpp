#include <bits/stdc++.h>
using namespace std;
vector<int> A(1e6), ST(1e6);
 
void build(int node, int L, int R)
{
 
    // Leaf node where L == R
    if (L == R) {
        ST[node] = A[L];
    }
    else {
 
        // Find the middle element to
        // split the array into two halves
        int mid = (L + R) / 2;
 
        // Recursively travel the
        // left half
        build(2 * node, L, mid);
 
        // Recursively travel the
        // right half
        build(2 * node + 1, mid + 1, R);
 
        // Storing the sum of both the
        // children into the parent
        ST[node] = ST[2 * node] + ST[2 * node + 1];
    }
}
 
void update(int node, int L, int R, int idx, int val)
{
 
    // Find the lead node and
    // update its value
    if (L == R) {
        A[idx] += val;
        ST[node] += val;
    }
    else {
 
        // Find the mid
        int mid = (L + R) / 2;
 
        // If node value idx is at the
        // left part then update
        // the left part
        if (L <= idx and idx <= mid)
            update(2 * node, L, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, R, idx, val);
 
        // Store the information in parents
        ST[node] = ST[2 * node] + ST[2 * node + 1];
    }
}
 
int query(int node, int tl, int tr, int l, int r)
{
 
    // If it lies out of range then
    // return 0
    if (r < tl or tr < l)
        return 0;
 
    // If the node contains the range then
    // return the node value
    if (l <= tl and tr <= r)
        return ST[node];
    int tm = (tl + tr) / 2;
 
    // Recursively traverse left and right
    // and find the node
    return query(2 * node, tl, tm, l, r)
           + query(2 * node + 1, tm +1, tr, l, r);
}
