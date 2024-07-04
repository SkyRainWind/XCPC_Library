#include <bits/stdc++.h>
using namespace std;
// Compile with "(g++) -std=c++11 -Wall -Wextra -Wconversion -Wshadow -Dcychien"
#ifdef cychien
#define debug(...) do {\
	fprintf(stderr, "%s - %d : (%s) = ", __PRETTY_FUNCTION__, __LINE__, #__VA_ARGS__);\
    _DO(__VA_ARGS__);\
}while(0) 
template<typename I> void _DO(I&&x) {cerr << x << '\n';}
template<typename I, typename ...T> void _DO(I&&x,T&&...tail) {cerr << x << ", "; _DO(tail...);}
#define IOS
#else
#define debug(...)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#endif
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define rsz resize
#define X first
#define Y second
#define SZ(x) (ll)x.size()
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
const int NF = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
const ld PI = 3.14159265358979323846264338327950288;
ll spd[10000005];
ll ans[10000005];
int main() {
    IOS;
    spd[0] = 1;
    spd[1] = 1;
    for (ll i = 2; i <= (int)(1e7); i++){
        if (spd[i] == 0){
            // debug(i);
            spd[i] = i;
            for (ll j = i * i; j <= (int)(1e7); j += i){
                if (spd[j] == 0){
                    spd[j] = i;
                }
            }
        }
    }
    ans[1] = 1;
    for (int i = 2; i <= (int)(1e7); i++){
        ll xx = i, fp = 1;
        ll sm = spd[i];
        while (xx % sm == 0){
            xx /= sm;
            fp *= sm;
        }
        if (i == sm){
            ans[i] = 1;
        }
        else if (fp == i){
            ans[i] = sm * ans[i / sm / sm];
        }
        else {
            ans[i] = ans[fp] * i / fp;
        }
    }
    ll n;
    cin >> n;
    ll bns = 0;
    for(int i=200000;i<=200050;i++)printf("%d\n",ans[i]);
    FOR1 (i, n) bns += ans[i];
    cout << bns << '\n';
    return 0;
}
