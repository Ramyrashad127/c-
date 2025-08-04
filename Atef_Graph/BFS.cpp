#include <bits/stdc++.h>
using namespace std;

int const N  = 1e5 + 2;
int par[N];
vector<int>g[N];
void BFS(int start)
{
   queue<int>q;
   q.push(start);
   par[start] = start;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(int child :g[node])
        {
            if(!par[child])
            {
                par[child] = node;
                q.push(child);
            }
        }
    }
}

