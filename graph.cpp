#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define vi vector
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int , null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
vi<int> adj[100002];
bool vis[100002];
void dfs(int node){
    vis[node] = true;
    for(auto neg : adj[node]) {
        if(!vis[neg])
            dfs(neg);
    }
}
// dsu
struct DSU {
    vi<ll> par, sz;
    void init(int n) {
        par.assign(2*n,0);
        sz.assign(2*n,0);
    }
    int get(int node) {
        if (node == par[node])
            return node;
        int p = get(par[node]);
        par[node] = p;
        return p;
    }
 
    void Union(int node1, int node2) {
        int p1 = get(node1);
        int p2 = get(node2);
        if (p1 == p2)
            return;
        if (sz[p1] > sz[p2])
            swap(p1, p2);
        sz[p2] += sz[p1];
        par[p1] = p2;
    }
};
// void move(int u, int v) {
//     int x = find(u);
//     v = find(v);
//     sz[x]--, sz[v]++;
//     su[x]-=u, su[v]+=u;
//     par[u] = v;
// }
struct edge {
    int u;
    int v;
    ll w;
};

bool bellman(int n, int m, vi<edge> &edges, int src) {
    vi<ll>d(n+5, -1e8);
    d[src] = 1.0;
    for(int i=1;i<=n-1;i++) {
        for(int j=1;j<=m;j++) {
            ll u = edges[j].u, v = edges[j].v;
            ll w = edges[j].w;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
            }
        }
    }
    // check cyc
    for(int i=1;i<=m;i++) {
        ll u = edges[i].u, v = edges[i].v;
        long double w = edges[i].w;
        if(d[v] > d[u] + w) {
            return true;
        }
    }
    return false;
}
void floyed(int n, vi<vi<ll>>&d) {
    for(int k=1; k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
}