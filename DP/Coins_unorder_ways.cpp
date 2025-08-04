#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin>>n;
    int num;
    cin>>num;
    vi v(n + 1);
    ll mod = 1e9+7;
    for (int i =1; i <= n; i++)
    {
        cin>>v[i];
    }
    sort(all(v));
    vi dp(num + 1 , 0);
    dp[0] = 1;
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <=n; j++)
        {
                if(i - v[j] >= 0){
                dp[i] = dp[i] + dp[i - v[j]]% mod;
                dp[i]%=mod;
            }
        }
    }
    cout<<dp[num] % mod;
    
 
}
