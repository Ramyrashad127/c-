#include <bits/stdc++.h>
using namespace std;

int const N  = 1e5;
int par[N] , sz[N];
int find(int node)
{
    if(node == par[node])
    {
        return node;
    }
    return par[node] = find(par[node]);
}
bool join(int u , int v)
{
    u = find(u);
    v = find(v);
    if(u == v)
    {
        return false;
    }
    if(sz[u]<sz[v])
    {
        swap(u , v);
    }
    par[v] = u;
    sz[u]+=sz[v];
    return true;
}
struct Node
{
    int u , v , weight;
};
bool comp(Node x , Node y)
{
    if(x.weight <y.weight)
    {
        return true;
    }
    else
        return false;
}
