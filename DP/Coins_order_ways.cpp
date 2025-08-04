#include <bits/stdc++.h>
using namespace std;
void solve() {
cin>>n;
cin>>num;
v.assign(n + 1 , 0);
for (int i =1; i <= n; i++)
{
  cin>>v[i];
}
vector<ll> dp(num + 1, 0);
dp[0] = 1; 
for (int i = 1; i <= n; ++i) {
    for (int x = v[i]; x <= num; ++x) {
        dp[x] = (dp[x] + dp[x - v[i]]) % mod;
    }
}
 
cout << dp[num] << "\n";
 
}
