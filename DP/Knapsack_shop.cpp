#include <bits/stdc++.h>
using namespace std;
void solve() {
    cin >> n;
    cin>>num;
    h.assign(n + 1 , 0);
    s.assign(n + 1 , 0);
    vi dp;
    dp.assign(num + 1 , 0);
    for (int i = 0; i <n; i++)
    {
        cin>>h[i + 1];
    }
    for (int i = 0; i <n; i++)
    {
        cin>>s[i + 1];
    }
    for (int i = 1; i <=n; i++)
    {
        for (int j = num; j>= 0; j--)
        {
            if(j  - h[i]>=0)
            dp[j] = max(dp[j] , dp[j - h[i]] + s[i]);
        }
    }
    cout<<dp[num];
    
}
