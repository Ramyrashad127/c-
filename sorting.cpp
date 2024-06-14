#include <bits/stdc++.h>
#define ll long long
#define vi vector
using namespace std;
void Bubble_sort(vi<ll>&v,int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-1-i;j++) {
            if(v[j] > v[j+1])
                swap(v[j], v[j+1]);
        }
    }
}
void Selectin_sort(vi<ll>&v,int n) {
    for(int i=0;i<n;i++) {
        int mn = v[i];
        int pos = i;
        for(int j=i+1;j<n;j++) {
            if(mn > v[j]) {
                mn = v[j];
                pos = j;
            }
        }
        swap(v[pos],v[i]);
    }
}
void Insertion_sort(vi<ll>&v,int n) {
    for(int i=1;i<n;i++)
    {
        for(int j=i;j>=1;j--) {
            if(v[j] < v[j-1])swap(v[j],v[j-1]);
            else break;
        }
    }
}
// no negative numbers
void Count_sort(vi<ll>&v,int n) {
   ll mx = v[0];
    // get the max element
    for(int i=0;i<n;i++) {
        mx = max(mx,v[i]);
    }
    vi<ll>freq(mx+1);
    for(int i=0;i<n;i++)
        freq[v[i]]++;
    int j=0;
    for(int i=0;i<mx+1;i++) {
        if(freq[i] == 0)continue;
        while(freq[i] > 0) {
            v[j] = i;
            j++;
            freq[i]--;
        }
    }
}
// radix
void count(vi<ll>& v,int n, ll pos) {
    vi<ll>freq(10);
    vi<ll>output(n);
    for(int i=0; i<n; i++) {
        int idx = (v[i] / pos)%10;
        freq[idx]++;
    }
    for(int i=1;i<10;i++)
        freq[i] += freq[i-1];

    for(int i = n-1; i >= 0; i--) {
        int temp = (v[i] / pos)%10;
        int idx = freq[temp];
        output[idx - 1] = v[i];
        freq[(v[i] / pos)%10]--;
    }
    for(int i=0;i<n;i++)v[i] = output[i];
}
void Radix_sort(vi<ll>& v, int n) {
    for(ll pos = 1;pos<1e18; pos*=10) {
        count(v,n,pos);
    }
}
