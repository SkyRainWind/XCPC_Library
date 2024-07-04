#include<bits/stdc++.h>
 
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
 
#define mod 998244353
#define ll long long
 
ll fpow(ll a, int b){
    ll ans = 1;
    for(; b; b >>= 1){
        if(b & 1){
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
    }
    return ans;
}
 
ll fact[500010], ifact[500010];
 
inline ll C(int n, int m){
    if(n < 0 || m < 0 || n < m)
        return 0;
    return fact[n] * ifact[m] % mod * ifact[n - m] % mod;
}
 
inline ll getp(int n, int m){
    if(n < 0)
        return 0;
    if(n == 0 && m == 0)
        return 1;
    return C(n - 1, m - 1);
}
 
int main(){
    // freopen("1.in", "r", stdin);
    std::cin.sync_with_stdio(false);
    
    int T;
    int ti = clock();
    fact[0] = ifact[0] = 1;
    for(int i = 1; i <= 500000; i++){
        fact[i] = fact[i - 1] * i % mod;
    }
    ifact[500000] = fpow(fact[500000], mod-2);
    for(int i=499999;i>=1;i--)ifact[i] = ifact[i+1] * (i+1) % mod;
    
    for(std::cin >> T; T >= 1; T--){
        int n, m, k;
        std::cin >> n >> m >> k;
        k += (n >> 1);
        ll ans = 0;
        for(int i = 1; i <= n; i++){ // black start
            ans += getp(((m - n + i) >> 1) + n + 1, n + 1) * getp(n - k, (i + 1) >> 1) % mod * getp(k, i >> 1) % mod;
            // printf("black | i = %d, ans = %lld\n", i, ans);
            ans %= mod;
        }
        for(int i = 1; i <= n; i++){ // white start
            ans += getp(((m - n + i - 1) >> 1) + n + 1, n + 1) * getp(k, (i + 1) >> 1) % mod * getp(n - k, i >> 1) % mod;
            // printf("white | i = %d, ans = %lld | %lld, %lld, %lld\n", i, ans, getp(((m - n + i - 1) >> 1) + n + 1, n + 1), getp((i + 1) >> 1, k), getp(i >> 1, n - k));
            ans %= mod;
        }
        // for(int i = 1; i <= n + 1; i++){
        //     ll tmp = getp(((m - n + i) >> 1) + n + 1, n + 1);
        //     if(i > 1)
        //         ans += getp(k, (i - 1) >> 1) * getp(n - k, i >> 1) % mod * tmp; // black start
        //     printf("i = %d, ans = %lld || ", i, ans);
        //     if(i <= n)
        //         ans += getp(k, (i + 1) >> 1) * getp(n - k, i >> 1) % mod * tmp; // white start
        //     ans %= mod;
        //     printf("i = %d, ans = %lld, tmp = %lld\n", i, ans, tmp);
        // }
        std::cout << ans << '\n';
    }
    // std::cerr << clock() - ti << '\n';
}
