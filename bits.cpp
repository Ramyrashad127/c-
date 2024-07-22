#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl '\n'
//#define sort(X) sort(X.begin(),X.end());
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define mi map<ll,int>
#define mc map<char,int>
#define cinv(v,n) for(int i = 0;i<n;i++)cin>>v[i];
using namespace std;
void letsMakeItFaster()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
string to_binary(int n){
    string s;
    while (n){
        int rem = n % 2;
        s.push_back(char(rem + '0'));
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}
// multiply x by 2 i times
int shift_left(int x, int i){
    return x << i;
}
// divide x by 2 i times
int shift_right(int x, int i){
    return x >> i;
}
// set ith bit
int light(int x, int i){
    return x | (1 << i);
}
// unset ith bit
int dark(int x, int i){
    return x & (~(1 << i));
}
// check the existence of the bit
bool checkBit(int x, int i){
    return x & (1 << i);
}
// Flipping the ith bit
int flipBit(int x, int i){
    return x ^ (1 << i);
}
// get the least significant bit
int LSB(int x){
    return x & (-x);
}
// get the most significant bit
int MSB(int x){
    int msb = 0;
    while (x){
        x >>= 1;
        msb++;
    }
    return msb - 1;
}
bool checkPowerOfTwo(int x){
    return !(x & (x - 1));
}
void subseq(int n , vector<ll>&v)
{
    int res = (1<<n)-1;
    for(int i = 0;i<=res;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(checkBit(i,j)==1)
            {
                cout<<v[j]<<" ";
            }
        }
        cout<<endl<<" ";
    }
}
void solve(int test) {

}
int main() {
    letsMakeItFaster();
    int test = 1;
    cin >> test;
    for(int i = 1;i<=test;i++)
    {
        solve(i);
	cout<<'\n';
    }

}
