#include <bits/stdc++.h>
#define ll long long 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
bool checkBit(long long x, long long i){
    long long one = 1;
    return x & (one << i);
}
int const N = 21;
int total;
vector<int>g[N];
int const LOG = 5;
int level[N] , sp[N][LOG + 1];
    vector<int>v;
bool checkBit(int x, int i){
    return x & (1 << i);
}
int n;
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
int cost(int i , int mask , int last)
{
    int node = i;
    while(node != last && node != 1 && checkBit(mask , node - 2 ) == 1)
    {
        node = sp[node][0];
    }
    return v[node];    
}
int const Mask = (1 << 19);
ll dp[N][Mask];
ll ret(int last , int mask)
{
    if(__builtin_popcount(mask) == total)
        return 0;
    ll &ans = dp[last][mask];
    if(~ans)
        return ans;
    ans = 1e16;
    int take = __builtin_popcount(mask) % 2;
    for (int i = 2; i <=n; i++)
    {
        if(checkBit(mask , i - 2) == 0 && take == 1)
        {
            ans = min(ans , ret(i  , mask + (1 << (i - 2)))+ cost(lca(i , last) , mask , last)) ;
        }
        else if(checkBit(mask , i - 2) == 0)
        {
            ans = min(ans , ret(i  , mask + (1 << (i - 2))));
        }
    }
    
    return ans;
}
void solve(int test) 
{
    cin>>n;
    total = n - 1;
    v.assign(n + 1 , 0);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i + 1];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u , v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1 , 1);
    memset(dp , -1 , sizeof dp);
    ll res = ret(0 , 0);
    if(n % 2== 0)
        res+=v[1];
    cout<<res;
}

int main() {
    IOS
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) solve(i);
}
