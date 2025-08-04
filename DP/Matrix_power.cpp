#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define Row vector<ll>
#define Matrix vector<Row>
using namespace std;
ll const mod = 1e9 + 7;
Matrix Mul_Matrices(Matrix &a , Matrix &b)
{
    Matrix c(a.size() , Row(b[0].size()));
    for (int i = 0; i < c.size(); i++)
    {
        for (int j = 0; j < c[i].size(); j++)
        {
           for (int k = 0; k <b.size(); k++)
           {
                c[i][j] =  (c[i][j] %mod+ (a[i][k] %mod * b[k][j] % mod)) %mod;
                if(c[i][j] >=mod)
                    c[i][j]-=mod;
           }
        }
    }
    return c;
}
Matrix power(Matrix &x, ll y)
{
    Matrix res(x.size() , Row(x.size() , 0));
    for (int i = 0; i < x.size(); i++)
    {
        res[i][i] = 1;
    }
    while (y > 0)
    {

        if (y & 1ll)
        res = Mul_Matrices(res , x);
        y = y >> 1ll; 
        x = Mul_Matrices(x , x);
    }
    return res;
}
void solve(int test) 
{
    ll n ;
    cin>>n;
    Matrix T = {{0 , 1 ,1 ,1,0} , {1 , 0 ,1 , 1,0} , {1 , 1 , 0 , 1,0} , {1 , 1 , 1 ,0,0} , {0 ,0 , 0 , 1 , 1}};
    Matrix s = {{1 , 1 , 1 , 1 , 0}};
    T = power(T , n+1);
    s = Mul_Matrices(T, s);
    if(n % 2 == 1)
    cout<<s[4][0] - 1<<' ';
    else
    cout<<s[4][0]<<' ';
}

int main() {
    IOS
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++) {
        solve(i);
        cout<<'\n';
    }
}
