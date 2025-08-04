#include <bits/stdc++.h>
#define ll long long
#define vi vector
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
using namespace std;

int const N  = 1e5 + 2;
vector<pair<ll,ll>>g[N];
ll d[N];
int n , m;
void dij( int source)
{
    prq<pair<ll,ll>> q;
    for (int i = 1; i <=n; i++)
    {
       d[i] = 1e18;
    }
    d[source] = 0;
    q.push({d[source] , source});
    while(!q.empty())
    {
        ll cost = -q.top().first;
        ll node = q.top().second;
        q.pop();
        if(d[node] < cost)
            continue;
        for(auto child : g[node])
        {
            ll ncost = child.second + cost;
            if(ncost < d[child.first])
            {
                d[child.first] = ncost;
                q.push({-ncost , child.first});
            }
        }
    }
}

