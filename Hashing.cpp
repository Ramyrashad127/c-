// double hashing
ll mod[] = {1000000007, 1000000009}, p[] = {31, 37};
vi<ll> modinv[2], pw[2];
void init(int sz) {
    for (int j=0;j<2;j++) {
        modinv[j].assign(sz, 1);
        pw[j].assign(sz,1);
        ll inv = fastpower(p[j], mod[j] - 2, mod[j]);
        for (int i=0;i<sz;i++) {
            if (i==0) {
                pw[j][i] = modinv[j][i] = 1;
            }
            else {
                pw[j][i] = (p[j] * pw[j][i-1])%mod[j];
                modinv[j][i] = (inv * modinv[j][i-1])%mod[j];
            }
        }
    }
}
