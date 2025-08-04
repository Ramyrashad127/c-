#include <bits/stdc++.h>
using namespace std;

int const N  = 1e5 + 2;
bool vis[N];
vector<int>g[N];
void dfs(int node)
{
    vis[node] =1;
    for(int child :g[node])
    {
        if(!vis[child])
        {
            dfs(child);
        }
    }
}

