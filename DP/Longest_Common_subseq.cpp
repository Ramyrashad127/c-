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
void solve( int test)
{
string s , t;
cin>>s>>t;
int n = s.size();
int  m = t.size();
vii dp(n + 2 , vi(m + 2));
for (int i = 1; i <= n ; i++)
{
    for (int j = 1; j <=m; j++)
    {
        if(s[i - 1] != t[j - 1])
        dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
        else
            dp[i][j] = max(dp[i][j] , dp[i - 1][j - 1] + 1);
    }
}
cout<<dp[n][m];


}
int main() {
    int t = 1;
    IOS;
    // cin>>t;
    
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    for (int i = 1; i <=t ; ++i) {
        solve(i);
            cout<<"\n";
    }

}
