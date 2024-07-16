#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define vi vector
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int , null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
// convert decimal to binary O(log2(n))
string to_binary(ll n)
{
    string t;
    while(n>0)
    {
        t.push_back(char('0' + n%2));
        n/=2;
    }
    //reverse(t.begin(),t.end());
    return t;
}
// turn on Ith bit O(1) 0 <= i < 64
ll turn_on(ll n, int x)
{
    return (n | (1 << (x)));
}
// turn off Ith bit 0 <= i < 64
ll turn_off (ll n,int x)
{
    return (n & (~(1<<x)));
}
// check state of Ith bit
int checkbit(ll n, int x)
{
    return (1 & (n>>x));
}
ll flipbit(ll n, int x)
{
    return (n ^ (1<<x));
}
// least signeficant bit LSB return the value in decimal
int LSB(int n)
{
    return n & (-n);
}
// most signficant bit 0 base
int MSB(int x)
{
    int ans = 0;
    while(x>0)
    {
        x = x>>1;
        ans++;
    }
    return ans-1;
}
// check if the number is power of two or not
bool check_power_of_two(ll x)
{
    if(x == 0)
        return 0;
    return !(x & (x-1));
}
string to_binary(ll n)
{
    string t;
    while(n>0)
    {
        t.push_back(char('0' + n%2));
        n/=2;
    }
    //reverse(t.begin(),t.end());
    return t;
}
int MSB(int x)
{
    int ans = 0;
    while(x>0)
    {
        x = x>>1;
        ans++;
    }
    return ans-1;
}
void solve() {
    int n;
    cin>>n;
    vi<int>mp,used,v();
    for()
}
int main() {
    IOS
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
