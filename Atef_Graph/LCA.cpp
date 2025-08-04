#include <bits/stdc++.h>
#define ll long long
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define vi vector<ll>
#define vii vector<vi>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define vc vector<char>
#define vcc vector<vc>
#define prq priority_queue
#define Dprq prq<pair<int , int> , vector<pair<int,int>> , greater<pair<int,int>>>
#define mi map<ll,ll>
#define mc map<char,int>
#define S second
#define F first
#define vp vector<pair<ll,ll>>
#define YES return void(cout<<"YES");
#define NO return void(cout<<"NO");
#define ZERO return void(cout<<"0");
using namespace std;
vector<vector<int>>g;
int const N = 1e5 + 1;
int const LOG = 20;
int level[N] , sp[N][LOG + 1];
bool checkBit(int x, int i){
    return x & (1 << i);
}
void dfs(int node , int par)
{
    level[node] = level[par] + 1;
    sp[node][0] = par;
    for (int i = 1; i <= LOG; i++)
    {
        int tmp = sp[node][i - 1];
        sp[node][i] = sp[tmp][i - 1];
    }
    for(int child : g[node])
        if(child != par)
            dfs(child, node);
}
int lca(int u  , int v)
{
    if(level[u] > level[v])
    {
        swap(u , v);
    }
    int diff = level[v] - level[u];
    for (int i = 0; i <= LOG; i++)
    {
        if(checkBit(diff , i))
        {
            v = sp[v][i];
        }
    }
    if(u == v)
        return v;
    for (int i = LOG; i >= 0; i--)
    {
        if(sp[u][i] != sp[v][i])
        {
            u = sp[u][i];
            v = sp[v][i];
        }
    }
    return sp[u][0];
}
