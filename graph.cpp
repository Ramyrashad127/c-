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