#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define vi vector
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int , null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
bool isprime(ll n)
{
    bool x = true;
    if (n <= 1)
        return false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            x = false;
            return x;
        }
    }
    return x;
}
vi<bool> sieve(ll n)
{
    vi<bool>v(n + 1, 1);
    v[0] = v[1] = 0;
    for(ll i = 2; i * i <= n; i++)
    {
        if (v[i])
        {
            for (ll j = i * i; j <= n; j += i)
                v[j] = 0;
        }
    }
    return v;
}
vi<ll>spf;
void Spf(ll n)
{
    spf.resize(n+1);
    for(int i=0;i<=n;i++)spf[i] = i;
    for(ll i = 2; i *i <= n; i++)
    {
        if (spf[i] == i)
        {
            for (ll j = 2 * i; j <= n; j += i)
                spf[j] = min(i,spf[j]);
        }
    }
}
vi<ll> primefactors(ll n)
{
    vi<ll>res;
    while(n>1)
    {
        res.push_back(spf[n]);
        //st.insert(spf[n]);
        n/=spf[n];
    }
    return res;
}
bool check_power_of_two(ll x)
{
    if(x == 0)
        return 0;
    return !(x & (x-1));
}
vi<ll> divesors(ll n)
{
    vi<ll>def;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            def.push_back(i);
            if(n/i != i) {
                if(n/i +1)
                    def.push_back(n/i);
            }
        }
    }
    return def;
}
vi<ll> prime_factorization(ll n)
{
    vi<ll>v;
    for(ll i = 2;i*i <= n;i++)
    {
        while(n%i==0)
        {
            n/=i;
            v.push_back(i);
        }
    }
    if(n!=1)
        v.push_back(n);
    return v;
}
ll fastpower(ll x, ll n, ll m = 1e18)
{
    ll result = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            result = (result % m * x % m) % m;
            n--;
        }
        else
        {
            x = (x % m * x % m) % m;
            n /= 2;
        }

    }
    return result;
}
ll ncr(ll n, ll r) {
    if (r > n) {
        return 0;
    }
    ll res = 1;
    for (ll i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
ll fact(int n,ll m=100000009)
{
    ll res = 1;
    for (int i = 1; i <= n; i++)
        res =((res%m) * (i%m))%m;
    return res;
}
ll npr(ll n, ll r)
{
    return ncr(n,r) * fact(r);
}
int factN_primepower(int n, int p)
{
    int power = 0;
    for (int i = p; i <= n; i = i * p)
        power += n / i;
    return power;
}
ll sumpower(int a, int k) //  a^1+a^2+a^3+....+a^k
{
    if (k == 0)
        return 1;
    if (k % 2 == 1)
        return a * (1 + sumpower(a, k - 1));
    ll half = sumpower(a, k / 2);
    return half * (1 + half - sumpower(a, k / 2 - 1));

}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}
ll binary_search(vi<ll>v, ll l, ll r, ll x)
{
    ll m = 0;
    while (l < r)
    {
        m = l + (r - l) / 2;
        if (v[m] == x)
            return m;
        else if (v[m] > x)
            r = m - 1;
        else if (v[m] < x)
            l = m + 1;
    }
    return l;
}
ll binary_search(vi<ll>v, ll l, ll r, ll x, ll y)
{
    ll m = 0,res=0;
    while (l < r)
    {
        m = l + (r - l) / 2;
        if (v[m] > y - x)
        {
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return r;
}
long double bs_db(long double l, long double r, long double x, long double tol)
{
    long double m;
    while (fabs(l - r) > tol)
    {
        m = (l + r) / 2;
        if (m > x)
            r = m;
        else
            l = m;
    }
    cout << fixed << setprecision(6);
    return l;
}
ll sum(ll n)
{
    return(n * (n + 1) / 2);
}
int check(vi<pair<ll,ll>>v, ll l, ll r)
{
    ll st =0, en = v.size()-1,m;
    while(st < en)
    {
        m = st + (en -st)/ 2;
        if(v[m].first > l)
            en = m-1;
        else if(v[m].second < r)
            st = m+1;
        else
            return m;
    }
    return m;
}
vi<ll> nextgreater(vi<ll>v)
{
    stack<int> st;
    vi<ll>res(v.size());
    for(int i=0;i < v.size();i++)
    {
        if(st.empty())
            st.push(i);
        else if(v[st.top()] >= v[i])
            st.push(i);
        else
        {
            while(v[st.top()] < v[i])
            {
                res[st.top()] = i;
                st.pop();
                if(st.empty())
                    break;
            }
            st.push(i);
        }
    }
    while(!st.empty())
    {
        res[st.top()] = -1;
        st.pop();
    }
    return res;
}
vi<ll> nextequal(vi<ll> nums) {
    vi<ll> result(nums.size(), -1);

    unordered_map<ll, stack<ll>> indexMap;

    for (int i = 0; i < nums.size(); ++i) {
        if (indexMap.find(nums[i]) != indexMap.end()) {
            while (!indexMap[nums[i]].empty()) {
                result[indexMap[nums[i]].top()] = i; // Update result for popped indices
                indexMap[nums[i]].pop();
            }
        }
        indexMap[nums[i]].push(i); // Push current index onto the stack
    }

    return result;
}