#include <iostream>
#include <vector>
#define ll long long
#define vi vector
using namespace std;
// basic segment
struct segtree {
    int size = 1;
    vi<ll>value;
    void init(int n) {
        while (size < n)
            size<<=1;
        value.assign(2*size, 0);
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
// lazy segment (update range)
struct segtree {
    vi<ll> values;
    int sz = 1;
    void init(int n) {
        while (sz < n)
            sz*=2;
        values.assign(2*sz, -1);
    }
    void build(vi<ll> &v, int node, int l, int r) {
        if (l==r) {
            if (l < v.size()) {
                values[node] = v[l];
            }
            return;
        }
        int m = (l+r)/2;
        build(v, 2*node+1, l,m);
        build(v, 2*node+2, m+1,r);
    }
    void build(vi<ll> &v) {
        init(v.size());
        build(v, 0, 0, sz-1);
    }
    void apply(int node, ll v) {
        values[node] = v;
    }
    void propagate(int node, int l , int r) {
        if (l == r) return;
        if (values[node] != -1) {
            apply(2*node+1, values[node]);
            apply(2*node+2, values[node]);
            values[node] = -1;
        }
    }
    void update(int lq, int rq, ll v, int node, int l, int r) {
        propagate(node,l,r);
        if (l > rq || r < lq) return;
        if (l >= lq && r <= rq) {
            values[node] = v;
            return;
        }
        int m = (l+r)/2;
        update(lq,rq,v, 2*node+1, l,m);
        update(lq,rq, v, 2*node+2, m+1,r);
    }
    void update(int lq, int rq, ll v) {
        update(lq, rq, v, 0, 0, sz-1);
    }
    ll get(int i, int node, int l, int r) {
        propagate(node, l,r);
        if (l==r)
            return values[node];
        int m = (l+r)/2;
        if (i<=m) {
            return get(i, 2*node+1, l,m);
        }
        else
            return get(i, 2*node+2, m+1,r);
    }
    ll get(int i) {
        return get(i, 0, 0, sz-1);
    }
};