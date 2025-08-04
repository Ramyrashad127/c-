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
#define mi map<int,int>
#define mc map<char,int>
#define S second
#define F first
#define coutv(v) for(auto x : v)cout<<x<<' ';
#define vp vector<pair<ll,ll>>
using namespace std;
int const N = 1e5  + 5;
int const LOG = 20;
ll t[N][LOG];
ll merge(ll x , ll y)
{
    return min(x , y);
}
void build(int n , vi& arr)
{
    for (int i = 1; i <= n; i++)
    {
        t[i][0] = arr[i];
    }
    for(int i = 1 ;(1 << i) <=n ;i++)
    {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) 
        {
           t[j][i] = merge(t[j][i - 1] , t[j + (1 << (i - 1))][i - 1]);
        }
    }
}

ll query(int  l ,int r)
{
  int len = r - l  + 1;
  ll lgg = __lg(len);
  return merge(t[l][lgg], t[r - (1 << lgg) + 1][lgg]);
}
