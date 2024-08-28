ll summ_divisible(ll n,ll m)
{
    ll first_term = m;
    ll last_term = (n / m) * m;
    ll num_terms = (last_term - first_term) / m + 1;
    ll sum = (num_terms * (first_term + last_term)) / 2;
    return sum;
}
ll summ_odd(ll n)
{
    long long sum = (((n + 1) * (n + 1)) / 4);
    return sum;
}
ll summ_even(ll n)
{
    long long sum = (n * (n + 2)) / 4;
    return sum;
}
///////file.in / standered out/////////////////
ifstream inputFile("file.in");
inputFile>>variable;
//////////////////////////////////another way/////////////////
freopen("file.in", "r", stdin);
