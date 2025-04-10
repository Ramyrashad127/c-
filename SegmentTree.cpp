#include <iostream>
#include <vector>
#define ll long long
#define vi vector
using namespace std;
struct segtree {
    int size = 1;
    vi<ll>value;
    void init(int n) {
        while (size < n)
            size<<=1;
        value.assign(2*size,    0);
    }
    void merge(int node) {
        value[node] = value[2*node+1] + value[2*node+2];
    }
    // 1-based index
    void build(vi<ll> &v, int node, int l, int r) {
        if (r == l) {
            if (l < (int)v.size()) {
                value[node] = v[l];
            }
            return;
        }
        int m = (l+r)/2;
        build(v, 2*node+1, l, m);
        build(v, 2*node+2, m+1,r);
        merge(node);
    }
    void build(vi<ll> &v) {
        init(v.size());
        build(v, 0, 0, size-1);
    }
    ll getans(ll left, ll right) {
        return left + right;
    }
    ll get(int lq, int rq, int node, int l, int r) {
        if (lq > r || rq < l)return 0;
        if (lq <= l && rq >= r) return value[node];
        int m = (l+r)/2;
        ll left = get(lq,rq, 2*node+1, l,m);
        ll right = get(lq,rq, 2*node+2,m+1, r);
        ll ans = getans(left, right);
        return ans;

    }
    ll get(int l, int r) {
        return get(l,r,0,0,size-1);
    }
    void set(int i, ll val, int node, int l ,int r) {
        if (r==l) {
            value[node] = val;
            return;
        }
        int m = (l+r)/2;
        if (i <= m) {
            set(i,val,2*node+1,l,m);
        }
        else {
            set(i,val,2*node+2, m+1,r);
        }
        merge(node);
    }
    void set(int i, ll val)
    {
        set(i,val,0,0,size-1);
    }
};